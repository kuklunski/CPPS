#include "../cub3d.h"

void validate_single_texture(t_data *data, char *texture)
{
  check_is_directory(data, texture);
  check_xpm_extention(data, texture);
  check_is_fd_valid(data, texture);
}

void validate_textures(t_data *data)
{
  validate_single_texture(data, data->no_texture);
  validate_single_texture(data, data->so_texture);
  validate_single_texture(data, data->we_texture);
  validate_single_texture(data, data->ea_texture);
}
