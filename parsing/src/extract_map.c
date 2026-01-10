#include "../cub3d.h"

int is_config_line(char *line)
{
  if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "EA ", 3)
    || ft_strnstr(line, "SO ", 3) || ft_strnstr(line, "WE ", 3))
  {
    return (1);
  }
  if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2))
  {
    return (1);
  }
  return (0);
}

int return_map_index(t_data *data)
{
	int i = 0;
  int j = 0;
	while (data->file_data[i])
	{
		if (is_config_line(data->file_data[i]))
      j++;
    i++;
	}
  return (j);
}

void get_map_height(t_data *data, int start_index)
{
  int i = start_index;
  int j = start_index;
  int map_height = 0;
  while (data->file_data[i])
    i++;
  map_height = i - j;
  data->map_height = map_height;
}

void get_map_width(t_data *data, int start_index)
{
  int i = start_index;
  int j = start_index;
  int max_width = 0;
  int cur_width = 0;
  int mwi = 0; // max with index
  while (data->file_data[i])
  {
    cur_width = ft_strlen(data->file_data[i]);
    if (cur_width > max_width)
    {
      max_width = cur_width;
      mwi = i;
    }
    i++;
  }
  mwi -= j;
  data->map_width = max_width;
}

void rm_newline_from_map_lines(t_data *data)
{
	int i;;
	int j;

	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '\n')
				data->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void extract_map(t_data *data)
{
	int start_index = return_map_index(data) + 1;
	int i = start_index;
	int j;
	get_map_width(data, start_index);
	get_map_height(data, start_index);
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		ft_exit_failure(data, "map allocation failed!");
	data->map[data->map_height] = NULL;
	j = 0;
	while (data->file_data[i])
	{
		data->map[j] = ft_strdup(data->file_data[i]);
		if (!data->map[j])
			ft_exit_failure(data, "map allocation failed!");
		i++;
		j++;
	}
	rm_newline_from_map_lines(data);
}
