#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*trim;

	if (s1 == 0)
		return (0);
	left = 0;
	right = ft_strlen(s1);
	trim = 0;
	if (s1 != '\0' && set != '\0')
	{
		while (ft_strchr(set, s1[left]) && s1[left] != '\0')
			left++;
		while (ft_strchr(set, s1[right - 1]) && right > left)
			right--;
		trim = (char *)malloc(sizeof(char) * (right - left + 1));
		if (trim == 0)
			return (0);
		ft_strlcpy(trim, &s1[left], right - left + 1);
	}
	return (trim);
}
