/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:07:10 by tkleynts          #+#    #+#             */
/*   Updated: 2020/02/28 10:14:15 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define R 1
#define NO 2
#define SO 4
#define WE 8
#define EA 16
#define F 32
#define C 64
#define S 128

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct 
{
			char			*tp_no;
			char			*tp_so;
			char			*tp_we;
			char			*tp_ea;
			char			*tp_s;
			int				r_x;
			int				r_y;
			unsigned char	f_red;
			unsigned char	f_grn;
			unsigned char	f_blu;
			unsigned char	c_red;
			unsigned char	c_grn;
			unsigned char	c_blu;
			char			**map;
}			t_cub;

int				ck_path(char *str, t_cub *data, char *msg, char **path);
int				ck_colors(char *str, t_cub *data, char *msg, unsigned char *col);
int				ck_res(char *str, t_cub *data, char *msg);
int				ck_arg(char *str, t_cub *data, unsigned char *ck);

int				f_err(char *msg, int ret, char **tab);
void			tab_free(char **tab);

#endif