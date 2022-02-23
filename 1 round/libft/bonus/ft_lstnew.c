#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (0);
	a->content = content;
	a->next = NULL;
	return (a);
}
