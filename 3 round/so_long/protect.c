#include "so_long.h"

void	protection(char	*str)
{
	int		fd;
	int		res;
	int		i;
	char	buf[1];

	i = ft_strlen(str);
	buf[0] = '\0';
	if ((i < 5) && (str[i - 4] != '.' || str[i - 3] != 'b' \
		|| str[i - 2] != 'e' || str[i - 1] != 'r'))
		error("Что-то с картой, сладость\n");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error("Что-то с картой, сладость\n");
	res = read(fd, &buf, 1);
	if (res < 0)
		error("Что-то с картой, сладость\n");
}
