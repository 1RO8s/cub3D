#include "cub3d.h"

char	*find_next_line(const char *contents)
{
	char	*line;

	line = ft_strchr(contents, '\n');
	if (line == NULL)
		return (NULL);
	line++;
// ??
//	if (*line == '\0')
//		return (NULL);
	return (line);
}
