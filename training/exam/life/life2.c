#include "life2.h"

static char **allocate_map(int width, int height)
{
    char **map;
    map = malloc(sizeof(char *) * height);
    int y = 0;
    while (y < height)
    {
        map[y] = malloc(sizeof(char ) * width);
        for (int x = 0; x < width; x++)
            map[y][x] = ' ';
        y++;
    }
    return map;
}

static void print_map(t_game *game)
{
    int x;
    int y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            putchar(game->map[y][x]);
            x++;
        }
        putchar('\n');
        y++;
    }
}

static int count_neighbor(t_game *game, int x, int y)
{
    int count = 0;
    for (int dy = -1; dy <= 1; dy++)
    for (int dx = -1; dx <= 1; dx++)
    {
        if (dx == 0 && dy == 0)
            continue;
        int nx = dx + x;
        int ny = dy + y;
        if (nx >= 0 && ny >= 0 && ny < game->height && nx < game->width && game->map[ny][nx] == '0')
            count++;
    }
    return count;
}

static void free_map(char **map, int height)
{
    int y = 0;
    while (y < height)
    {
        if (map[y])
            free(map[y]);
        y++;
    }
    if (map)
        free(map);
}

static void step(t_game *game)
{
    char **next;
    next = allocate_map(game->width, game->height);
    int x;
    int y = 0;
    int n = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            n = count_neighbor(game, x, y);
            if (game->map[y][x] == '0' && (n == 2 || n == 3))
                next[y][x] = '0';
            else if (game->map[y][x] != '0' && (n == 3))
                next[y][x] = '0';
            else
                next[y][x] = ' ';
            x++;
        }
        y++;
    }
    free_map(game->map, game->height);
    game->map = next;
}

static void draw_map(t_game *game)
{
    int drawing = 0;
    int x = 0;
    int y = 0;
    char c;

    while (read(STDIN_FILENO, &c, 1) == 1)
    {
        if (c == 'w' && y > 0)
            y--;
        else if (c == 's' && y < game->height - 1)
            y++;
        else if (c == 'd' && x < game->width - 1)
            x++;
        else if (c == 'a' && x > 0)
            x--;
        else if (c == 'x')
            drawing = !drawing;
        if (drawing)
            game->map[y][x] = '0';
    }
}

int main (int ac, char **av)
{
    t_game game;
    if (ac != 4)
        return 1;
    game.width = atoi(av[1]);
    game.height = atoi(av[2]);
    game.iterations = atoi(av[3]);
    if (game.width <= 0 || game.height <= 0 || game.iterations < 0)
        return 1;
    game.map = allocate_map(game.width, game.height);
    draw_map(&game);
    for (int i = 0; i < game.iterations; i++)
        step(&game);
    print_map(&game);
    free_map(game.map, game.height);
    return 0;
}