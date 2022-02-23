#include "so_long.h"

static void	ft_mlx_image(int y, int x, t_game	*game, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->scrn, game->wll_i, \
			x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->scrn, game->bck_i, \
			x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->scrn, game->plr_i, \
			x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->scrn, game->ext_i, \
			x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->scrn, game->itm_i, \
			x * 64, y * 64);
}

void	write_map(t_game	*game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			ft_mlx_image(y, x, game, game->map[y][x]);
	}
}
