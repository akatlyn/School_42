#include	"libft.h"

char	*ft_strdup(const char *str)
{
	char	*dstr;
	int		i;

	i = 0;
	dstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dstr == 0)
		return (0);
	while (str[i] != '\0')
	{
		dstr[i] = str[i];
		i++;
	}
	dstr[i] = '\0';
	return (dstr);
}
