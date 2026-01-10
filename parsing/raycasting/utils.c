/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mypixel_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:45:47 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/06 23:45:47 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void my_pixel_put(e_data *data, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void cleanup_and_exit(e_data *data)
{
    if (data->img)
        mlx_destroy_image(data->mlx, data->img);
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    exit(0);
}

int handle_close(e_data *data)
{
    cleanup_and_exit(data);
	free_data(data->pdata);
    return (0);
}


void draw_vertical_line(e_data *data, int x, int start, int end, int color)
{
    int y;

    y = start;
    while (y < end)
    {
        my_pixel_put(data, x, y, color);
        y++;
    }
}