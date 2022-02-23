#include	"get_next_line.h"
#include	<stdio.h>

static int	laststring(char *buf, char **rm)
{
	*rm = ft_strjoin(*rm, buf);
	if (!(*rm))
		return (-1);
	return (0);
}

static int	rmliner(char **line, char **rm)
{
	char	*swap;
	char	*p;

	p = ft_strchr(*rm, '\n');
	if (p)
	{
		swap = *rm;
		*p++ = '\0';
		*line = ft_strdup(*rm);
		if (!(*line))
			return (-1);
		*rm = ft_strdup(p);
		if (!(*rm))
			return (-1);
		free(swap);
	}
	else
	{
		*line = ft_strdup(*rm);
		if (!(*line))
			return (-1);
		free(*rm);
		*rm = NULL;
	}
	return (0);
}

static int	rmck(char *rm)
{
	if (!rm)
		return (0);
	if (ft_strchr(rm, '\n'))
		return (1);
	return (0);
}

static int	remrd(char **rm, char **line, char *buf, int fd)
{
	int		rd;

	rd = 1;
	while ((!rmck(*rm)) && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (-1);
		buf[rd] = '\0';
		if (!(*rm))
		{
			*rm = ft_strdup(buf);
			if (!(*rm))
				return (-1);
		}
		else
			laststring(buf, rm);
	}
	rmliner(line, rm);
	if (rd)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*rm;
	char			*buf;
	int				rt;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	rt = remrd(&rm, line, buf, fd);
	free(buf);
	return (rt);
}

// int main()
// {
// 	char 	*line;
// 	int		fd;
// 	int		res;

// 	fd = open("txt.txt", O_RDONLY);
// 	while ((res = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("result = %d %s\n", res, line);
// 		free(line);
// 	}
// 	printf("result = %d %s\n", res, line);
// 	free(line);
// 	return (0);
// }