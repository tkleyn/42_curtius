/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:40:29 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/23 11:18:32 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int dda(t_cub *data)
{
		for(int x = 0; x < data->r_x; x++)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)data->r_x - 1; //x-coordinate in camera space
			double rayDirX = data->dir.x + data->plane.x * cameraX;
			double rayDirY = data->dir.y + data->plane.y * cameraX;
			//which box of the map we're in
			int mapX = (int)data->pos.x;
			int mapY = (int)data->pos.y;

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = fabs(1 / rayDirX);
			double deltaDistY = fabs(1 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if(rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (data->pos.x - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - data->pos.x) * deltaDistX;
			}
			if(rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (data->pos.y - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - data->pos.y) * deltaDistY;
			}

			//perform DDA
			while (hit == 0)
			{

				//jump to next map square, OR in x-direction, OR in y-direction
				if(sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}	
				//Check if ray has hit a wall
				if(data->map[mapY][mapX] > '0') hit = 1;

			}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if(side == 0) perpWallDist = (mapX - data->pos.x + (1 - stepX) / 2) / rayDirX;
			else perpWallDist = (mapY - data->pos.y + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
			int lineHeight = (int)(data->r_y / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + data->r_y / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + data->r_y / 2;
			if(drawEnd > data->r_y)drawEnd = data->r_y;

			int i;

			i =  0;
			while (i < drawStart)
				data->img_i[i++ * data->r_x + x] = data->ceiling;
			while (i < drawEnd)
				data->img_i[i++ * data->r_x + x] = 0xFF0000;
			while (i < data->r_y)
				data->img_i[i++ * data->r_x + x] = data->floor;

				
		}
		return 0;
}