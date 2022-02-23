#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<fcntl.h>
# include	<stdlib.h>
# include	<unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char	*s1, char	*s2);

#endif