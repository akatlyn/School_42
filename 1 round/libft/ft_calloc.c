#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*reserv;

	reserv = malloc(count * size);
	if (reserv == 0)
		return (0);
	ft_bzero(reserv, count * size);
	return (reserv);
}
