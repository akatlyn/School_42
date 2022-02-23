#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
		protection(argv[1]);
	else
		error("Что-то с картой, сладость\n");
	game.mlx = mlx_init();
	init_game(&game);
	init_image(&game);
	read_map(argv[1], &game);
	checker_map(&game);
	len_strings_map(&game);
	check_walls(&game);
	check_counts(&game);
	game.scrn = mlx_new_window(game.mlx, game.x * 64, \
		game.y * 64, "GACHI GAME");
	write_map(&game);
	mlx_hook(game.scrn, 17, 0, game_over, &game);
	mlx_hook(game.scrn, 2, (1L << 0), hot_keys, &game);
	mlx_loop(game.mlx);
}
