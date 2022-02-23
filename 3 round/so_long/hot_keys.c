#include "so_long.h"

static void	write_steps(t_game	*game)
{
	printf("Всего фрикций: %d\n", game->steps);
}

static void	step_to(int y, int x, t_game	*game)
{
	game->map[game->y_st + y][game->x_st + x] = 'P';
	game->map[game->y_st][game->x_st] = '0';
	game->y_st = game->y_st + y;
	game->x_st = game->x_st + x;
	game->steps += 1;
	write_steps(game);
}

static void	checker_steps(int	y, int x, t_game	*game)
{
	if (game->map[game->y_st + y][game->x_st + x] != '1')
	{
		if (game->itm_c == 0)
			game->win = 1;
		if (game->win == 1 && game->map[game->y_st + y][game->x_st + x] == 'E')
		{
			game->steps += 1;
			write_steps(game);
			game_over(game);
		}
		else if (game->map[game->y_st + y][game->x_st + x] == 'C')
		{
			game->itm_c -= 1;
			step_to(y, x, game);
		}
		else if (game->map[game->y_st + y][game->x_st + x] == '0')
			step_to(y, x, game);
		write_map(game);
	}
}

int	hot_keys(int keycode, t_game *game)
{
	char	*s;

	s = ft_itoa(game->steps);
	if (keycode == 0)
		checker_steps(0, -1, game);
	if (keycode == 2)
		checker_steps(0, 1, game);
	if (keycode == 13)
		checker_steps(-1, 0, game);
	if (keycode == 1)
		checker_steps(1, 0, game);
	if (keycode == 53)
		exit(0);
	mlx_put_image_to_window(game->mlx, game->scrn, game->wll_i, 0 * 64, 0 * 64);
	mlx_put_image_to_window(game->mlx, game->scrn, game->wll_i, 1 * 64, 0 * 64);
	mlx_string_put(game->mlx, game->scrn, 3, 1, 0xFFFFFF, "Steps: ");
	mlx_string_put(game->mlx, game->scrn, 65, 1, 0xFFFFFF, s);
	free(s);
	return (0);
}
