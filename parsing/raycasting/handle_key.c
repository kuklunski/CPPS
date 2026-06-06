/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylemkere <ylemkere@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 06:14:53 by ylemkere          #+#    #+#             */
/*   Updated: 2026/01/06 06:14:53 by ylemkere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int handle_key(int key, e_data *d)
{
    double moveSpeed = 0.5;
    double rotSpeed = 0.2;
    char **map = d->pdata->map;

    if (key == 65307) // ESC
        cleanup_and_exit(d);

    // --- MOVE FORWARD ---
    if (key == 'w')
    {
        if (map[(int)d->posY][(int)(d->posX + d->dirX * moveSpeed)] != '1')
            d->posX += d->dirX * moveSpeed;
        if (map[(int)(d->posY + d->dirY * moveSpeed)][(int)d->posX] != '1')
            d->posY += d->dirY * moveSpeed;
    }

    // --- MOVE BACKWARD ---
    if (key == 's')
    {
        if (map[(int)d->posY][(int)(d->posX - d->dirX * moveSpeed)] != '1')
            d->posX -= d->dirX * moveSpeed;
        if (map[(int)(d->posY - d->dirY * moveSpeed)][(int)d->posX] != '1')
            d->posY -= d->dirY * moveSpeed;
    }

    // STRAFE RIGHT (D)
    if (key == 'd')
    {
        if (map[(int)d->posY][(int)(d->posX + d->planeX * moveSpeed)] != '1')
            d->posX += d->planeX * moveSpeed;
        if (map[(int)(d->posY + d->planeY * moveSpeed)][(int)d->posX] != '1')
            d->posY += d->planeY * moveSpeed;
    }

    // STRAFE LEFT (A)
    if (key == 'a')
    {
        if (map[(int)d->posY][(int)(d->posX - d->planeX * moveSpeed)] != '1')
            d->posX -= d->planeX * moveSpeed;
        if (map[(int)(d->posY + -d->planeY * moveSpeed)][(int)d->posX] != '1')
            d->posY -= d->planeY * moveSpeed;
    }

    // --- ROTATE LEFT ---
    if (key == 65363)
    {
        double oldDirX = d->dirX;
        d->dirX = d->dirX * cos(-rotSpeed) - d->dirY * sin(-rotSpeed);
        d->dirY = oldDirX * sin(-rotSpeed) + d->dirY * cos(-rotSpeed);
        double oldPlaneX = d->planeX;
        d->planeX = d->planeX * cos(-rotSpeed) - d->planeY * sin(-rotSpeed);
        d->planeY = oldPlaneX * sin(-rotSpeed) + d->planeY * cos(-rotSpeed);
    }

    // --- ROTATE RIGHT ---
    if (key == 65361)
    {
        double oldDirX = d->dirX;
        d->dirX = d->dirX * cos(rotSpeed) - d->dirY * sin(rotSpeed);
        d->dirY = oldDirX * sin(rotSpeed) + d->dirY * cos(rotSpeed);
        double oldPlaneX = d->planeX;
        d->planeX = d->planeX * cos(rotSpeed) - d->planeY * sin(rotSpeed);
        d->planeY = oldPlaneX * sin(rotSpeed) + d->planeY * cos(rotSpeed);
    }

    return 0;
}
