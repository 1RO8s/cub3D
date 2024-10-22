#include "cub3d.h"

static bool	is_texture_element(const char *str)
{
	const char	*identifier[4] = {"NO ", "SO ", "WE ", "EA "};
	size_t		i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(str, identifier[i], (size_t)3) == 0)
			return (true);
		i++;
	}
	return (false);
}

static bool	is_floor_ceiling_element(const char *str)
{
	const char	*identifier[2] = {"F ", "C "};
	size_t		i;

	i = 0;
	while (i < 2)
	{
		if (ft_strncmp(str, identifier[i], (size_t)2) == 0)
			return (true);
		i++;
	}
	return (false);
}

static bool	is_map_element(const char *str)
{
	const char	*identifier = " 1";
	size_t		i;
	size_t		len;

	len = ft_strlen(identifier);
	while (*str != '\n')
	{
		i = 0;
		while (i < len)
		{
			if (ft_strncmp(str, identifier + i, (size_t)1) != 0)
				return (false);
			i++;
		}
		str++;
	}
	return (true);
}

t_enum_element	get_type_element(const char *line)
{
	if (is_texture_element(line) == true)
		return (ENUM_TEX);
	else if (is_floor_ceiling_element(line) == true)
		return (ENUM_FC);
	else if (is_map_element(line) == true)
		return (ENUM_MAP);
	else
		return (ENUM_ELEMENT_ERR);
}
