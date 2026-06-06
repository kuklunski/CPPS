#include "../cub3d.h"

void check_range(t_data *data, int number)
{
  if (number < 0 || number > 255)
    ft_exit_failure(data, "{-} Check your floor/ceiling ranges");
}

void check_ranges(t_data *data)
{
  check_range(data, data->floor[0]);
  check_range(data, data->floor[1]);
  check_range(data, data->floor[2]);
  check_range(data, data->ceiling[0]);
  check_range(data, data->ceiling[1]);
  check_range(data, data->ceiling[2]);
}
