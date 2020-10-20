/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:00:42 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/20 14:28:57 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		int2char(uint8_t *char_adr, int int_var)
{
	int	*ptr;

	ptr = (int *)char_adr;
	*ptr = int_var;
}

static void		header_write(t_cub *data, int32_t fd, uint32_t padding)
{
	uint8_t		bmp_header[54];
	uint32_t	filesize;

	ft_bzero(bmp_header, 54);
	filesize = 54 + (data->r_x * 3 + padding) * data->r_y;
	bmp_header[0] = (uint8_t)'B';
	bmp_header[1] = (uint8_t)'M';
	int2char(&bmp_header[2], filesize);
	bmp_header[10] = (uint8_t)54;
	bmp_header[14] = (uint8_t)40;
	int2char(&bmp_header[18], data->r_x);
	int2char(&bmp_header[22], -data->r_y);
	bmp_header[26] = (uint8_t)1;
	bmp_header[28] = (uint8_t)24;
	write(fd, bmp_header, 54);
}

static void		img_write(t_cub *data, int32_t fd, uint32_t padding)
{
	unsigned char	*line;
	int				i;
	int				j;
	int				tmp;

	i = 0;
	if (!(line = (uint8_t *)malloc(sizeof(char) * 3 * data->r_x + padding)))
		error_exit(data, "Allocation error");
	ft_bzero(line, 3 * data->r_x + padding);
	while (i < data->r_y)
	{
		j = 0;
		while (j < data->r_x)
		{
			tmp = data->img_i[i * data->r_x + j];
			tmp = (tmp & 0xFF0000) | (tmp & 0x00FF00) | (tmp & 0x0000FF);
			int2char(&line[j * 3], tmp);
			j++;
		}
		if ((write(fd, line, 3 * data->r_x + padding)) < 0)
			error_exit(data, "Writing in Screenshot.bmp failed");
		i++;
	}
	free(line);
}

void			bmp2img(t_cub *data)
{
	uint32_t	padding;
	int32_t		fd;

	data->apply_tex = 1;
	cub_init(data);
	tex_load(data);
	if ((fd = open("Screenshot.bmp", O_WRONLY | O_CREAT
									| O_TRUNC, S_IRWXU)) < 0)
		error_exit(data, "Screenshot.bmp creation failed");
	padding = ((data->r_x % 4)) % 4;
	header_write(data, fd, padding);
	dda(data);
	img_write(data, fd, padding);
	close(fd);
	exit(0);
}
