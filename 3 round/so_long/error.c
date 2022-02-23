#include "so_long.h"

void	fullfree(t_game *game)
{
	int		i;

	i = -1;
	while (game->map[++i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
	}
	free(game->map);
	game->map = NULL;
}

void	error(char *str)
{
	printf("%s", str);
	exit(1);
}
