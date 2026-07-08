#ifndef LIFE_HPP
#define LIFE_HPP

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
    int width;
    int height;
    char **map;
    int iterations;
} t_game;

#endif
