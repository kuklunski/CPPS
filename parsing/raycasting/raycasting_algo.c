/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:07:19 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/06 23:07:19 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_wall(t_ray *r)
{
	if (r->side == 0)
		r->perpWallDist = r->sideDistX - r->deltaDistX;
	else
		r->perpWallDist = r->sideDistY - r->deltaDistY;
	if (r->perpWallDist < 1e-6)
		r->perpWallDist = 1e-6;
	r->lineHeight = (int)(HEIGHT / r->perpWallDist);
	r->drawStart = -r->lineHeight / 2 + HEIGHT / 2;
	if (r->drawStart < 0)
		r->drawStart = 0;
	r->drawEnd = r->lineHeight / 2 + HEIGHT / 2;
	if (r->drawEnd >= HEIGHT)
		r->drawEnd = HEIGHT - 1;
}

int	get_texture_index(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->stepX > 0)
			return (EAST);
		return (WEST);
	}
	else
	{
		if (r->stepY > 0)
			return (SOUTH);
		return (NORTH);
	}
}

void	calc_texture(t_ray *r, e_data *d)
{
	if (r->side == 0)
		r->wallX = d->posY + r->perpWallDist * r->rayDirY;
	else
		r->wallX = d->posX + r->perpWallDist * r->rayDirX;
	r->wallX -= floor(r->wallX);
	r->texX = (int)(r->wallX * d->tex_width[r->tex]);
	if ((r->side == 0 && r->stepX < 0)
		|| (r->side == 1 && r->stepY > 0))
		r->texX = d->tex_width[r->tex] - r->texX - 1;
}


void	draw_column(e_data *d, t_ray *r, int x)
{
	int	y;

	r->step = 1.0 * d->tex_height[r->tex] / r->lineHeight;
	r->texPos = (r->drawStart - HEIGHT / 2 + r->lineHeight / 2) * r->step;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < r->drawStart)
			my_pixel_put(d, x, y, d->c);
		else if (y > r->drawEnd)
			my_pixel_put(d, x, y, d->f);
		else
		{
			r->texY = (int)r->texPos
				& (d->tex_height[r->tex] - 1);
			r->texPos += r->step;
			my_pixel_put(d, x, y,
				d->tex_data[r->tex][r->texY
				* d->tex_width[r->tex] + r->texX]);
		}
		y++;
	}
}

void	draw_scene_3d(e_data *d, t_data *p)
{
	t_ray	r;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		ft_bzero(&r, sizeof(t_ray));
		init_ray(&r, d, x);
		init_step(&r, d);
		perform_dda(&r, p);
		if (r.hit)
		{
			calc_wall(&r);
			r.tex = get_texture_index(&r);
			calc_texture(&r, d);
			draw_column(d, &r, x);
		}
		x++;
	}
}