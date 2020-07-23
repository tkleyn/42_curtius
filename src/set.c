/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:20:04 by tkleynts          #+#    #+#             */
/*   Updated: 2020/07/23 11:27:22 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void setpos(t_cub *data, double x, double y)
{
	data->pos.x = x;
	data->pos.y = y;
}

void setdir(t_cub *data, double x, double y)
{
	data->dir.x = x;
	data->dir.y = y;
}

void setplane(t_cub *data, double x, double y)
{
	data->plane.x = x;
	data->plane.y = y;
}
