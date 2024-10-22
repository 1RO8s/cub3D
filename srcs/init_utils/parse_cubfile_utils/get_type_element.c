#include "cub3d.h"

static bool	is_texture_element(const char *str)
{
	const char	identifier[4] = {"NO ", "SO ", "WE ", "EA "};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(str, identifier[i], (size_t)3) == 0)
			return (true);
		i++;
	}
	return (false);
}

t_enum_element	get_type_element(const char *line)
{
	if (is_texture_element(line) == true)
		return (ENUM_TEX);
	else (is_floor_ceiling(line) == true)
		return (ENUM_FC);
	else if (is_map_element(line) == true)
		return (ENUM_MAP);
	else
		return (ENUM_ELEMENT_ERR);
}
