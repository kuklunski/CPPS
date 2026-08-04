#pragma once

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_game
{
	int		width;
	int		height;
	int		iterations;
	char	**map;
} t_game;
