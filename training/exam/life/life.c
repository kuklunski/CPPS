#include "life.h"

char** alloc_map(int width, int heigth)
{
    char **map;
    int x ;
    int y ;
    map = malloc(sizeof(char *) * height);
    y = 0;
    while (y < heigth)
    {
        x = 0;
        map[y] = malloc(sizeof(char) * width);
        while (x < width)
        {
            map[y][x++] = ' ';
        }
        y++;
    }
    return map;
}

int main(int ac, char **av)
{
    t_game game;
    int i = 0;

    if (ac != 4)
        return 1;
    game.width = atoi(av[1]);
    game.height = atoi(av[2]);
    game.iterations = atoi(av[3]);
    if (game.width < 0 || game.height < 0 || game.iterations < 0)
        return 1;
    game.map = alloc_map(game.width, game.height);
    draw_map(&game);
}
