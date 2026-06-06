#include "../cub3d.h"

void free_double_char_pointer(char **matrix)
{
  int i = 0;
  while (matrix && matrix[i])
  {
    free(matrix[i]);
    i++;
  }
  free(matrix[i]);
  free(matrix);
}

void free_data(t_data *data)
{
  if (data->file_data)
    free_double_char_pointer(data->file_data);
  if (data->map)
    free_double_char_pointer(data->map);
  if (data->map_copy)
    free_double_char_pointer(data->map_copy);
  if (data->no_texture)
    free(data->no_texture);
  if (data->so_texture)
    free(data->so_texture);
  if (data->we_texture)
    free(data->we_texture);
  if (data->ea_texture)
    free(data->ea_texture);
  init_reset_data(data);
}

void free_file_descriptors()
{
  // let's come up with a way to keep track of all of them first 
}

// have a function to free evethingn that has been allocated
// test that there are no memory leaks by your part and then
// comment the calls that free the map and textures until the very 
// end of the program
//
// TODO: make sure to free out everthing at every call to exit ,
//
// so every time the program hits an error, 
// we need to free out everything.
//
//
//
// file descriptors (did you free them all) ? on errors too?
