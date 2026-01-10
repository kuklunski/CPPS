#include "../cub3d.h"

int validate_number(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void free_matrix(char **matrix)
{
	int i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix[i])
		free(matrix[i]);
	if (matrix)
		free(matrix);
}

void set_ceiling_values(t_data *data, char **matrix)
{
	int i = 0;
	char *re;
	while (matrix[i])
	{
		re = ft_strtrim(matrix[i], " \n\t");
		data->ceiling[i] = ft_atoi(re);
		free(re);
		i++;
	}
}

void get_ceiling_out_of_matrix(t_data *data, char **matrix)
{
	int i = 0;
	char *re;
	while (matrix[i])
	{
		re = ft_strtrim(matrix[i], " \n\t");
		if (!validate_number(re))
		{
			free(re);
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad ceiling values!");
		}
		if (ft_strlen(re) == 0)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad ceiling values!!");
		}
		free(re);
		i++;
	}
	set_ceiling_values(data, matrix);
	free_matrix(matrix);
}

void set_floor_values(t_data *data, char **matrix)
{
	int i = 0;
	char *re;
	while (matrix[i])
	{
		re = ft_strtrim(matrix[i], " \n\t");
		data->floor[i] = ft_atoi(re);
		free(re);
		i++;
	}
}

void get_floor_out_of_matrix(t_data *data, char **matrix)
{
	int i = 0;
	char *re;
	while (matrix[i])
	{
		re = ft_strtrim(matrix[i], " \n\t");
		if (!validate_number(re))
		{
			free(re);
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad Floor values!");
		}
		if (ft_strlen(re) == 0)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad Floor values!");
		}
		free(re);
		i++;
	}
	set_floor_values(data, matrix);
	free_matrix(matrix);
}

void get_ceiling(t_data *data, char *line)
{
	int i = 0;
	if (ft_strnstr(line, "C ", 2))
	{
		if (data->ceiling[0] != -1)
			ft_exit_failure(data, "{-} Ceiling is duplicated!");
		char **matrix = ft_split(line + 2, ',');
		while (matrix[i])
			i++;
		if (!matrix[0] || i < 3 || i > 3)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad ceiling values!!!!");
		}
		get_ceiling_out_of_matrix(data, matrix);
	}
}

void get_floor(t_data *data, char *line)
{
	int i = 0;
	if (ft_strnstr(line, "F ", 2))
	{
		if (data->floor[0] != -1)
			ft_exit_failure(data, "{-} Floor is duplicated!");
		char **matrix = ft_split(line + 2, ',');
		while (matrix[i])
			i++;
		if (!matrix[0] || i < 3 || i > 3)
		{
			free_matrix(matrix);
			ft_exit_failure(data, "{-} Bad Floor values!");
		}
		get_floor_out_of_matrix(data, matrix);
	}
}

void extract_floor_and_ceiling(t_data *data)
{
	int	i;

	i = 0;
	while (data->file_data[i])
	{
		get_floor(data, data->file_data[i]);
		get_ceiling(data, data->file_data[i]);
		i++;
	}
}
