#include "so_long.h"

void	init_game(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->plr_c = 0;
	game->ext_c = 0;
	game->itm_c = 0;
	game->steps = 0;
	game->win = 0;
}

void	init_image(t_game *game)
{
	game->wll_i = mlx_xpm_file_to_image(game->mlx, "imag/locker.xpm", \
		&game->h, &game->w);
	game->plr_i = mlx_xpm_file_to_image(game->mlx, "imag/plr_k.xpm", \
		&game->h, &game->w);
	game->bck_i = mlx_xpm_file_to_image(game->mlx, "imag/floor_k.xpm", \
		&game->h, &game->w);
	game->itm_i = mlx_xpm_file_to_image(game->mlx, "imag/face_k.xpm", \
		&game->h, &game->w);
	game->ext_i = mlx_xpm_file_to_image(game->mlx, "imag/exit_k.xpm", \
		&game->h, &game->w);
}
