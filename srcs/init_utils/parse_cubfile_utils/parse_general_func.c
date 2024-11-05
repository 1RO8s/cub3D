#include "cub3d.h"

char	*find_next_line(const char *contents)
{
	char	*line;

	line = ft_strchr(contents, '\n');
	if (line == NULL)
		return (NULL);
	line++;
	if (*line == '\0')
		return (NULL);
	return (line);
}

bool	is_key_line(const char *line, const char *key)
{
	size_t	len;

	len = ft_strlen(key);
	return (ft_strncmp(line, key, len) == 0);
}

char	*strdup_until_ch(const char *line, int until_ch)
{
	size_t	len;
	char	*file;

	len = ft_strchr(line, until_ch) - line;
	file = ft_strndup(line, len);
	return (file);
}

void	init_tex_keys(const char *keys[], int size)
{
	int					i;
	static const char	*defaults[] = {
		"NO ", "WE ", "EA ", "SO "};

	i = 0;
	while (i < size)
	{
		keys[i] = defaults[i];
		i++;
	}
}
