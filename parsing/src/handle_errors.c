#include "../cub3d.h"

void ft_exit_failure(t_data *data, char *msg)
{
  printf("%s\n", msg);
  free_data(data);
  exit(1);
}
