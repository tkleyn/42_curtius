/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:40:29 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/22 14:36:41 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int dda(t_cub *data)
{
		for(int x = 0; x < data->r_x; x++)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)data->r_x - 1; //x-coordinate in camera space
			double rayDirX = data->dir_x + data->plane_x * cameraX;
			double rayDirY = data->dir_y + data->plane_y * cameraX;
			//which box of the map we're in
			int mapX = (int)data->pos_x;
			int mapY = (int)data->pos_y;

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
				sideDistX = (data->pos_x - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - data->pos_x) * deltaDistX;
			}
			if(rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (data->pos_y - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - data->pos_y) * deltaDistY;
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
			if(side == 0) perpWallDist = (mapX - data->pos_x + (1 - stepX) / 2) / rayDirX;
			else perpWallDist = (mapY - data->pos_y + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
			int lineHeight = (int)(data->r_y / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + data->r_y / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + data->r_y / 2;
			if(drawEnd > data->r_y)drawEnd = data->r_y;

			for (int i = drawStart; i < drawEnd; i++)
				data->img_i[i * data->r_x + x] = data->ceiling;
				
		}
		return 0;
}