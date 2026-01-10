/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algo2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:41:55 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/06 23:41:55 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(t_ray *r, e_data *d, int x)
{
	r->cameraX = 2 * x / (double)WIDTH - 1;
	r->rayDirX = d->dirX + d->planeX * r->cameraX;
	r->rayDirY = d->dirY + d->planeY * r->cameraX;
	r->mapX = (int)d->posX;
	r->mapY = (int)d->posY;
	r->deltaDistX = fabs(1 / r->rayDirX);
	r->deltaDistY = fabs(1 / r->rayDirY);
}


void	init_step(t_ray *r, e_data *d)
{
	if (r->rayDirX < 0)
	{
		r->stepX = -1;
		r->sideDistX = (d->posX - r->mapX) * r->deltaDistX;
	}
	else
	{
		r->stepX = 1;
		r->sideDistX = (r->mapX + 1.0 - d->posX) * r->deltaDistX;
	}
	if (r->rayDirY < 0)
	{
		r->stepY = -1;
		r->sideDistY = (d->posY - r->mapY) * r->deltaDistY;
	}
	else
	{
		r->stepY = 1;
		r->sideDistY = (r->mapY + 1.0 - d->posY) * r->deltaDistY;
	}
}


void	perform_dda(t_ray *r, t_data *p)
{
	while (!r->hit)
	{
		if (r->sideDistX < r->sideDistY)
		{
			r->sideDistX += r->deltaDistX;
			r->mapX += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sideDistY += r->deltaDistY;
			r->mapY += r->stepY;
			r->side = 1;
		}
		if (r->mapY < 0 || r->mapY >= p->map_height)
			return ;
		if (r->mapX < 0 || r->mapX >= (int)ft_strlen(p->map[r->mapY]))
			return ;
		if (p->map[r->mapY][r->mapX] == '1')
			r->hit = 1;
	}
}