#include "../cub3d.h"

void init_reset_data(t_data *data)
{
	ft_memset(data, 0, sizeof(*data));
	data->floor[0] = -1;
	data->floor[1] = -1;
	data->floor[2] = -1;
	data->ceiling[0] = -1;
	data->ceiling[1] = -1;
	data->ceiling[2] = -1;
}
