#include "so_long.h"

void	check_counts(t_game *game)
{
	if (game->plr_c != 1 || game->ext_c < 1 || game->itm_c < 1)
	{
		fullfree(game);
		error("Детка не спеши, сделай все красиво\n");
	}
}

void	check_walls(t_game *game)
{
	int		y;
	int		x;

	y = -1;
	while (game->y > ++y)
	{
		x = -1;
		while (game->x > ++x)
		{
			if (game->map[0][x] != '1' || game->map[game->y - 1][x] != '1')
			{
				fullfree(game);
				error("Есть пробитие!\n");
			}
			if (game->map[y][0] != '1' || game->map[y][game->x - 1] != '1')
			{
				printf("y = %d, x = %d\n", y, x);
				fullfree(game);
				error("Есть пробитие!\n");
			}
		}
	}
}

void	len_strings_map(t_game	*game)
{
	int		i;

	i = -1;
	while (game->y > ++i)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
		{
			fullfree(game);
			error("Стены шатает\n");
		}
	}
}
