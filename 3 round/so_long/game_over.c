#include "so_long.h"

int	game_over(t_game *game)
{
	fullfree(game);
	if (game->win == 1)
		error("Ты лучше всех, пупсик\n");
	exit(0);
}
