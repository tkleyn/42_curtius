/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:50:26 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/20 14:22:31 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void					ft_swap_sp(t_sp_pos *a, t_sp_pos *b)
{
	t_sp_pos	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void					sort_sprite(t_cub *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->n_srites)
	{
		j = 0;
		while (j < data->n_srites - i - 1)
		{
			if (data->s_pos[j].dist < data->s_pos[j + 1].dist)
				ft_swap_sp(&data->s_pos[j], &data->s_pos[j + 1]);
			j++;
		}
		i++;
	}
}

static void					math_sprite(t_cub *data, t_sp_data *s, int i)
{
	double		invdet;

	s->sprite.x = data->s_pos[i].pos.x - data->pos.x;
	s->sprite.y = data->s_pos[i].pos.y - data->pos.y;
	invdet = 1.0 / (data->plane.x * data->dir.y - data->dir.x * data->plane.y);
	s->transform.x = invdet * (data->dir.y
					* s->sprite.x - data->dir.x * s->sprite.y);
	s->transform.y = invdet * (-data->plane.y
					* s->sprite.x + data->plane.x * s->sprite.y);
	s->spritescreenx = (int)(data->r_x / 2)
					* (1 + s->transform.x / s->transform.y);
	s->spritedata.y = fabs((int)data->r_y / (s->transform.y));
	s->drawstart.y = -s->spritedata.y / 2 + data->r_y / 2;
	if (s->drawstart.y < 0)
		s->drawstart.y = 0;
	s->drawend.y = s->spritedata.y / 2 + data->r_y / 2;
	if (s->drawend.y >= data->r_y)
		s->drawend.y = data->r_y - 1;
	s->spritedata.x = fabs((int)data->r_y / (s->transform.y));
	s->drawstart.x = -s->spritedata.x / 2 + s->spritescreenx;
	if (s->drawstart.x < 0)
		s->drawstart.x = 0;
	s->drawend.x = s->spritedata.x / 2 + s->spritescreenx;
	if (s->drawend.x >= data->r_x)
		s->drawend.x = data->r_x - 1;
}

static void					draw_sprite(t_cub *data, t_sp_data *s, double *zbuf)
{
	int			y;
	int			d;

	s->stripe = s->drawstart.x;
	while (s->stripe < s->drawend.x)
	{
		s->tex.x = (int)(256 * (s->stripe - (-s->spritedata.x / 2 +
				s->spritescreenx)) * data->t[4].size.x / s->spritedata.x) / 256;
		if (s->transform.y > 0 && s->stripe > 0 && s->stripe < data->r_x
								&& s->transform.y < zbuf[s->stripe])
		{
			y = s->drawstart.y;
			while (y < s->drawend.y)
			{
				d = (y) * 256 - data->r_y * 128 + s->spritedata.y * 128;
				s->tex.y = ((d * data->t[4].size.y) / s->spritedata.y) / 256;
				s->color = data->t[4].tex_i[data->t[4].size.x
							* s->tex.y + s->tex.x];
				if ((s->color & 0x00FFFFFF) != 0)
					data->img_i[y * data->r_x + s->stripe] = s->color;
				y++;
			}
		}
		s->stripe++;
	}
}

void						sprite_cast(t_cub *data, double *zbuf)
{
	t_sp_data	s;
	int			i;

	i = 0;
	while (i < data->n_srites)
	{
		data->s_pos[i].dist = ((data->pos.x - data->s_pos[i].pos.x)
							* (data->pos.x - data->s_pos[i].pos.x)
							+ (data->pos.y - data->s_pos[i].pos.y)
							* (data->pos.y - data->s_pos[i].pos.y));
		i++;
	}
	sort_sprite(data);
	i = 0;
	while (i < data->n_srites)
	{
		math_sprite(data, &s, i);
		draw_sprite(data, &s, zbuf);
		i++;
	}
}
