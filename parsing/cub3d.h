#ifndef CUB3D_H
# define CUB3D_H

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 700
#define MOVE_SPEED 10
#define NORTH   0
#define SOUTH   1
#define EAST    2
#define WEST    3

typedef struct s_player_position
{
  int x;
  int y;
} t_player_position;

typedef struct s_data
{
	char **file_data;
	char *file_str;
	int line_count;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	int floor[3];
	int ceiling[3];
	char **map;
	char **map_copy;
	int map_height;
	int map_width;
	t_player_position player_position;
	char player_char;
} t_data;


void get_number_of_lines(char *path, t_data *data);
void check_file_validity(t_data *data, char *file_str);
void get_file_data(t_data *data);
void extract_textures(t_data *data);
void extract_floor_and_ceiling(t_data *data);
void do_premap_elements_exist(t_data *data);
void extract_map(t_data *data);
void map_validation(t_data *data);
void create_map_copy(t_data *data);
void invoke_flood(t_data *data);
void init_reset_data(t_data *data);
void free_data(t_data *data);
void ft_exit_failure(t_data *data, char *msg);
void validate_textures(t_data *data);
void check_is_directory(t_data *data, char *texture);
void check_is_fd_valid(t_data *data, char *texture);
void check_xpm_extention(t_data *data, char *texture);
void check_ranges(t_data *data);

// execution

typedef struct s_paths
{
    char    *north;
    char    *south;
    char    *east;
    char    *west;
}   t_paths;

typedef struct execution_data 
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    double     posX;
    double     posY;
    int bits_per_pixel;
    int line_length;
    int endian;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    t_paths  paths;
    int c;
    int f;
    void    *textures[4];
    int     *tex_data[4];
    int     tex_width[4];
    int     tex_height[4];
    t_data  *pdata;
    int **int_map;
}   e_data;

typedef struct s_ray
{
  double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		tex;
	int		texX;
	int		texY;
	double	wallX;
	double	step;
	double	texPos;
} t_ray;

void    *ft_memset(void *b, int c, size_t len);
int handle_key(int key, e_data *d);
void cleanup_and_exit(e_data *data);
void print_map(char **map, int height);
void init_data(e_data *data, t_data *pdata);
void	draw_scene_3d(e_data *d, t_data *p);
void	init_ray(t_ray *r, e_data *d, int x);
void	init_step(t_ray *r, e_data *d);
void	perform_dda(t_ray *r, t_data *p);
void	calc_wall(t_ray *r);
void	calc_texture(t_ray *r, e_data *d);
void	draw_column(e_data *d, t_ray *r, int x);
int		get_texture_index(t_ray *r);
void my_pixel_put(e_data *data, int x, int y, int color);
void draw_vertical_line(e_data *data, int x, int start, int end, int color);
int handle_close(e_data *data);
void cleanup_and_exit(e_data *data);
void my_pixel_put(e_data *data, int x, int y, int color);

#endif
