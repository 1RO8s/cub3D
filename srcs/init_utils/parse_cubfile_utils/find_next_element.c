#include "cub3d.h"

const char	*find_next_element(const char *line)
{
	bool	is_empty_pre_line;

	is_empty_pre_line = (*line == '\n');
	while (line != NULL)
	{
		line = find_next_line(line);
		if (line == NULL)
			return (NULL);
		if (is_empty_pre_line == true && *line != '\n')
			break ;
		is_empty_pre_line = (*line == '\n');
	}
	return (line);
}
// behavior about each of line type ( NULL or "\n" or "exist_next_line" )
// NULL : next line is empty
// "\n" : repeat to call get_next_line
// "exist_next_line" : return line
