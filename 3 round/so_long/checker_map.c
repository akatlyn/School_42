#include "so_long.h"

static void	max_len(int i, int j)
{
	if (i > 50 || j > 50)
		error("Слишком большой, пупсик\n");
}

static void	check_char(char c, t_game *game)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1')
	{
		fullfree(game);
		error("Детка не спеши, сделай все красиво\n");
	}
}

void	checker_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			check_char(game->map[i][j], game);
			if (game->map[i][j] == 'P')
			{
				game->plr_c += 1;
				game->y_st = i;
				game->x_st = j;
			}
			if (game->map[i][j] == 'E')
				game->ext_c += 1;
			if (game->map[i][j] == 'C')
				game->itm_c += 1;
		}
	}
	max_len(i, j);
	game->x = j;
	game->y = i;
}
