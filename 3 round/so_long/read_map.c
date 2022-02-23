#include "so_long.h"

static void	cant_read(char *buf)
{
	free(buf);
	error("Что-то с картой, сладость\n");
}

static char	*s_malloc(char *buf, int len)
{
	char	*tmp;

	tmp = buf;
	buf = malloc(len);
	if (!buf)
	{
		error("У Маллока 'эти дни'. Не сегодня котенок\n");
		exit(1);
	}
	free(tmp);
	return (buf);
}

static void	empty_str(char *buf)
{
	int		i;

	i = 1;
	while (buf[i])
	{
		if (buf[i] == buf[i - 1] && buf[i] == '\n')
		{
			free(buf);
			error("Убери эти ненужные дырки, пупсик\n");
			exit(1);
		}
		i++;
	}
}

static int	map_len(char *map)
{
	int		fd;
	char	c;
	int		len;

	len = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("Что-то с картой, сладость\n");
	if (fd)
		while (read(fd, &c, 1))
			len++;
	if (!len)
		error("*звук пустоты*\n");
	close(fd);
	return (len);
}

void	read_map(char	*map, t_game	*game)
{
	int		len;
	char	*buf;
	int		fd;
	int		i;

	i = 0;
	buf = 0;
	len = 0;
	len = map_len(map);
	buf = s_malloc(buf, len + 1);
	fd = open(map, O_RDONLY);
	if ((read(fd, buf, len)) < 0)
		cant_read(buf);
	close(fd);
	buf[len] = '\0';
	empty_str(buf);
	game->map = ft_split(buf, '\n');
	if (!game->map)
		error("Карта RIP\n");
	free(buf);
}
