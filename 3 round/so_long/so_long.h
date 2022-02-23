#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_lib/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_game
{
	int		h;
	int		w;
	int		x;
	int		y;
	void	*mlx;
	void	*scrn;
	char	**map;
	int		plr_c;
	int		ext_c;
	int		itm_c;
	int		steps;
	int		win;
	int		x_st;
	int		y_st;
	void	*bck_i;
	void	*wll_i;
	void	*plr_i;
	void	*ext_i;
	void	*itm_i;

}				t_game;

int		hot_keys(int keycode, t_game *game);
int		game_over(t_game *game);
void	fullfree(t_game *game);
void	error(char *str);
void	read_map(char	*map, t_game	*game);
void	init_image(t_game *game);
void	init_game(t_game *game);
void	checker_map(t_game *game);
void	check_counts(t_game *game);
void	check_walls(t_game *game);
void	len_strings_map(t_game	*game);
void	write_map(t_game	*game);
void	protection(char	*str);
int		main(int argc, char **argv);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif