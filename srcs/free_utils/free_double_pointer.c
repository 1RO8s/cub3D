#include <stdlib.h>

/**
 * @brief Free the memory and set the pointer to NULL.
 * @param[in] ptr The pointer to be freed.
 * @return NULL always.
 */
void	*ft_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	return (NULL);
}

void	free_double_pointer(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		array[i] = ft_free(array[i]);
		i++;
	}
	ft_free(array);
}
