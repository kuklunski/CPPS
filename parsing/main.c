#include "cub3d.h"

// TODO: think about when to exit and when to return -1
// when an error that demands closing the program is met
// just exit, but make sure to have that inside a function that makes
// sure everything that needs to be freed is freed.


void	debug_printf(t_data *d)
{
	printf("file_str: %s\n", d->file_str ? "true" : "false");
	printf("file_data: %s\n", d->file_data ? "true" : "false");
	printf("NO: %s\n", d->no_texture);
	printf("SO: %s\n", d->so_texture);
	printf("WE: %s\n", d->we_texture);
	printf("EA: %s\n", d->ea_texture);
	printf("F: %d %d %d\n", d->floor[0], d->floor[1], d->floor[2]);
	printf("C: %d %d %d\n", d->ceiling[0], d->ceiling[1], d->ceiling[2]);
}

void print_map(char **map, int height)
{
    for (int y = 0; y < height; y++)
    {
        int x = 0;
        while (map[y][x])
        {
            char c = map[y][x];
            if (c == ' ')
                putchar('s');
            else
                putchar(c);
            x++;
        }
        putchar('\n');
    }
}

void parsing(char *file_str, t_data *data)
{
	init_reset_data(data);
	data->file_str = file_str;
	check_file_validity(data, file_str);
	get_number_of_lines(file_str, data);
	get_file_data(data);
	extract_textures(data);
	validate_textures(data);
	extract_floor_and_ceiling(data);
	check_ranges(data);
	//debug_printf(data);
	//printf("-----------------------------------\n");
	do_premap_elements_exist(data);
	extract_map(data);
	map_validation(data);
	create_map_copy(data);
	invoke_flood(data);
	printf("map height : %d, map width : %d\n", data->map_height, data->map_width);
	printf("x : %d, y : %d\n", data->player_position.x, data->player_position.y);
	print_map(data->map, data->map_height);
	print_map(data->map_copy, data->map_height);
	//free_data(data);
}





















static void load_texture(e_data *data, int id, char *path)
{
    int bpp;
    int size_line;
    int endian;

    data->textures[id] = mlx_xpm_file_to_image(
            data->mlx,
            path,
            &data->tex_width[id],
            &data->tex_height[id]);
    if (!data->textures[id])
    {
        ft_printf("Error: failed to load texture id %d\n", id);
        exit(1);
    }
    data->tex_data[id] = (int *)mlx_get_data_addr(
            data->textures[id],
            &bpp,
            &size_line,
            &endian);
}

void    init_textures(e_data *data, t_data *pdata)
{
    char *paths[4];

    paths[NORTH] = pdata->no_texture;
    paths[SOUTH] = pdata->so_texture;
    paths[EAST] = pdata->ea_texture;
    paths[WEST] = pdata->we_texture;

    load_texture(data, NORTH, paths[NORTH]);
    load_texture(data, SOUTH, paths[SOUTH]);
    load_texture(data, EAST, paths[EAST]);
    load_texture(data, WEST, paths[WEST]);
}





/*void draw_scene_3d(e_data *data, t_data *p)
{
    for (int x = 0; x < WIDTH; x++)
    {
        // Calculate ray position and direction
        double cameraX = 2 * x / (double)WIDTH - 1;
        double rayDirX = data->dirX + data->planeX * cameraX;
        double rayDirY = data->dirY + data->planeY * cameraX;

        int mapX = (int)data->posX;
        int mapY = (int)data->posY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);

        double sideDistX, sideDistY;
        int stepX, stepY;
        int hit = 0;
        int side;

        // Determine step direction and initial side distance
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (data->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (data->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
        }

        // --- DDA ---
		while (!hit)
		{
			if (sideDistX < sideDistY)
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

			// bounds check for irregular maps
			if (mapY < 0 || mapY >= p->map_height)
				break;

			int row_len = ft_strlen(p->map[mapY]);
			if (mapX < 0 || mapX >= row_len)
				break;

			if (p->map[mapY][mapX] == '1')
				hit = 1;
		}

        // Calculate perpendicular distance to wall
        double perpWallDist;
        if (side == 0)
            perpWallDist = sideDistX - deltaDistX;
        else
            perpWallDist = sideDistY - deltaDistY;

		if (perpWallDist < 1e-6)
    		perpWallDist = 1e-6;

        // Calculate height of line to draw
        int lineHeight = (int)(HEIGHT / perpWallDist);

        // Calculate start and end positions on screen
        int drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;

        int drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

        // Determine texture index based on wall side
        int textureIndex;
        if (side == 0) // vertical wall
            textureIndex = (stepX > 0) ? EAST : WEST;
        else // horizontal wall
            textureIndex = (stepY > 0) ? SOUTH : NORTH;

        // Calculate exact point of wall hit
        double wallX;
        if (side == 0)
            wallX = data->posY + perpWallDist * rayDirY;
        else
            wallX = data->posX + perpWallDist * rayDirX;
        wallX -= floor(wallX); // keep fractional part

        // X coordinate on texture
        int texX = (int)(wallX * (double)data->tex_width[textureIndex]);
        if ((side == 0 && stepX < 0) || (side == 1 && stepY > 0))
            texX = data->tex_width[textureIndex] - texX - 1;

        // Step size for texture
        double step = 1.0 * data->tex_height[textureIndex] / lineHeight;
        double texPos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;

        // Draw vertical stripe
        for (int y = 0; y < HEIGHT; y++)
        {
            if (y < drawStart)
                my_pixel_put(data, x, y, data->c); // ceiling
            else if (y > drawEnd)
                my_pixel_put(data, x, y, data->f); // floor
            else
            {
                int texY = (int)texPos & (data->tex_height[textureIndex] - 1);
                texPos += step;
                int color = data->tex_data[textureIndex][texY * data->tex_width[textureIndex] + texX];
                my_pixel_put(data, x, y, color);
            }
        }
    }
}*/

int render(e_data *data)
{
    ft_memset(data->addr, 0, HEIGHT * data->line_length);
    draw_scene_3d(data, data->pdata);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

// pdata for parsing data
// edata for execution data
int main(int argc, char **argv)
{
	char *file_str;
	t_data pdata;
	e_data edata;

	if (argc != 2)
	{
		printf("{-} Wrong Number of Args!\n");
		exit(1);
	}
	file_str = argv[1];
	parsing(file_str, &pdata);
	printf("{+} every thing is working as expected\n");
	printf("{+} parsing status: SUCCESS...\n");

    init_data(&edata, &pdata);
    init_textures(&edata, &pdata);
	int i = 0;
	while (i < 3)
	{
		printf("floor %d : %d, Ceiling %d : %d, \n",i, pdata.floor[i], i, pdata.ceiling[i]);
		i++;
	}
    mlx_loop_hook(edata.mlx, render, &edata);
    mlx_key_hook(edata.win, handle_key, &edata);
    mlx_hook(edata.win, 17, 0, handle_close, &edata);
    mlx_loop(edata.mlx);
	return (0);
}
