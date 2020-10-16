/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 11:19:19 by tkleynts          #+#    #+#             */
/*   Updated: 2020/10/08 12:14:01 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_swap_sp(t_sp_pos *a, t_sp_pos *b)
{
	t_sp_pos tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void		sort_sprite(t_cub *data)
{
	int i;
	int j; 

	i = 0;
	while (i < data->n_srites)
	{
		j = 0;
		while (j < data->n_srites - i - 1)
		{
			if (data->s_pos[j].dist > data->s_pos[j + 1].dist) 
				ft_swap_sp(&data->s_pos[j], &data->s_pos[j + 1]);
			j++;
		}
	}
}

static			math_sprite(t_cub *data, t_sp_data *s, int i)
{
	double invdet;

	//translate sprite position to relative to camera
	s->sprite.x = data->s_pos[i].pos.x - data->pos.x;
	s->sprite.y = data->s_pos[i].pos.y - data->pos.y;


	invdet = 1.0 / (data->plane.x * data->dir.y - data->dir.x * data->plane.y); //required for correct matrix multiplication

	s->transform.x = invdet * (data->dir.y * s->sprite.x - data->dir.x * s->sprite.y);
	s->transform.y = invdet * (-data->plane.y * s->sprite.x + data->plane.x * s->sprite.y); //this is actually the depth inside the screen, that what Z is in 3D

	s->spritescreenx = (int)(data->r_x/ 2) * (1 + s->transform.x / s->transform.y);

	//calculate height of the sprite on screen
	s->spritedata.y = abs((int)data->r_y / (s->transform.y)); //using 'transform.y' instead of the real distance prevents fisheye
	//calculate lowest and highest pixel to fill in current stripe
		s->drawstart.y = -s->spritedata.y / 2 +data->r_y / 2;
	if (s->drawstart.y < 0) s->drawstart.y = 0;
		s->drawend.y = s->spritedata.y / 2 +data->r_y / 2;
	if (s->drawend.y >=data->r_y) 
		s->drawend.y = data->r_y- 1;

	//calculate width of the sprite
	s->spritedata.x = abs((int) data->r_y/ (s->transform.y));
	s->drawstart.x = -s->spritedata.x / 2 + s->spritescreenx;
	if (s->drawstart.x < 0) s->drawstart.x = 0;
		s->drawend.x = s->spritedata.x / 2 + s->spritescreenx;
	if (s->drawend.x >= data->r_x)
		s->drawend.x = data->r_x - 1;
}

static void		draw_sprite(t_cub *data, t_sp_data *s, int i)
{
	int stripe;
	int y;

	stripe = s->drawstart.x;
	//loop through every vertical stripe of the sprite on screen
	while (stripe < s->drawend.x)
	{
		int texX = (int)(256 * (stripe - (-s->spritedata.x / 2 + s->spritescreenx)) * data->t[4].size.x / s->spritedata.x) / 256;
		//the conditions in the if are:
		//1) it's in front of camera plane so you don't see things behind you
		//2) it's on the screen (left)
		//3) it's on the screen (right)
		//4) ZBuffer, with perpendicular distance
		if (s->transform.y > 0 && stripe > 0 && stripe <data->r_x&& s->transform.y < ZBuffer[stripe])
		{
			y = s->drawstart.y;
			while (y < s->drawend.y) //for every pixel of the current stripe
			{
				int d = (y) * 256 -data->r_y * 128 + s->spritedata.y * 128; //256 and 128 factors to avoid floats
				int texY = ((d * data->t[4].size.y) / s->spritedata.y) / 256;
				uint32_t color = data->t[4].tex_i[data->t[4].size.x * texY + texX]; //get current color from the texture
				if ((color & 0x00FFFFFF) != 0) 
					buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
				y++;
			}
		}
		stripe++;
	}
}

void			sprite_cast(t_cub *data)
{
	t_sp_data s;
	double invdet;
	int i;
	
	i = 0;
	//sort sprites from far to close
	while (i < data->n_srites)
	{
		data->s_pos[i].dist =	((data->pos.x - data->s_pos[i].pos.x)
							* (data->pos.x - data->s_pos[i].pos.x)
							+ (data->pos.y - data->s_pos[i].pos.y)
							* (data->pos.y - data->s_pos[i].pos.y));
		i++;
	}
	sort_sprites(data);

	i = 0;
	//after sorting the sprites, do the projection and draw them
	while (i < data->n_srites)
	{
		math_sprite(data, &s, i);
		draw_sprite(data, &s, i);
		i++;
	}
}