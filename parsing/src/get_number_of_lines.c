#include "../cub3d.h"

void get_number_of_lines(char *path, t_data *data)
{
	char	*line;
	int		fd;
	int		count;
	
	count = 0;
	fd = open(path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	data->line_count = count;
}
