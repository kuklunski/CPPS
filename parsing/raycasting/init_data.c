/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:46:46 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/06 22:46:46 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int rgb_to_hex(int rgb[3])
{
    return ((rgb[0] & 0xFF) << 16)
         | ((rgb[1] & 0xFF) << 8)
         |  (rgb[2] & 0xFF);
}

static void init_textures(e_data *data)
{
    int i;

    i = 0;
    while (i < 4)
    {
        data->textures[i] = NULL;
        data->tex_data[i] = NULL;
        data->tex_width[i] = 0;
        data->tex_height[i] = 0;
        i++;
    }
}

static void set_dirplane(e_data *data, double dirX, double dirY, double planeX, double planeY)
{
    data->dirX = dirX;
    data->dirY = dirY;
    data->planeX = planeX;
    data->planeY = planeY;
}

static void init_dirplane(e_data *data, t_data *pdata)
{
    if (pdata->player_char == 'N')
        set_dirplane(data, 0, -1, -0.66, 0);
    else if (pdata->player_char == 'S')
        set_dirplane(data, 0, 1, 0.66, 0);
    else if (pdata->player_char == 'E')
        set_dirplane(data, 1, 0, 0, -0.66);
    else if (pdata->player_char == 'W')
        set_dirplane(data, -1, 0, 0, 0.66);
    else
    {
        ft_printf("Invalid player direction\n");
        exit(1);
    }
}



void init_data(e_data *data, t_data *pdata)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	data->posX = pdata->player_position.x + 0.5;
	data->posY = pdata->player_position.y + 0.5;
    init_dirplane(data, pdata);
    data->c = rgb_to_hex(pdata->ceiling);
    data->f = rgb_to_hex(pdata->floor);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img,
                                   &data->bits_per_pixel,
                                   &data->line_length,
                                   &data->endian);
    init_textures(data);
	data->pdata = pdata;
}