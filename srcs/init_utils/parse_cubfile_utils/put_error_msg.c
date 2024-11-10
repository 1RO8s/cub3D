#include "cub3d.h"

void	put_error_msg(const char *entry, const char *msg)
{
	dprintf(STDERR_FILENO, ERR_PROMPT);
	while (*entry != ' ' && *entry != '\0' && *entry != '\n')
	{
		write(STDERR_FILENO, entry, 1);
		entry++;
	}
	dprintf(STDERR_FILENO, ": %s\n", msg);
}
