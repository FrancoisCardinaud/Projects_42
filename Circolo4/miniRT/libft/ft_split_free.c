#include "libft.h"

void	ft_split_free(char **s)
{
	size_t	i;

	if (!s || !*s)
		return ;
	i = 0;
	while (i < ft_strlen_const(s))
		free(s[i++]);
	free(s);
	//*s = NULL;
}