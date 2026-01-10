#include "../cub3d.h"
#include <fcntl.h>


void get_file_data(t_data *data)
{
	int	fd;
	int i = 0;
	char *line = NULL;

	data->file_data = malloc(sizeof(char *) * (data->line_count + 1));
	fd = open(data->file_str, O_RDONLY);

	if (!data->file_data)
	{
		printf("{-} Error! allocation\n");
		return ;
	}

	while ((line = get_next_line(fd)))
	{
		data->file_data[i] = ft_strdup(line);
		free(line);
		i++;
	}
	data->file_data[data->line_count] = NULL;
	close(fd);
}
