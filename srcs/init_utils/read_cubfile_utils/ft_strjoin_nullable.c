#include "cub3d.h"

char	*ft_strjoin_nullable(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	return (ft_strjoin(s1, s2));
}
