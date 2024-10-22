#include "cub3d.h"

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
