#include "cub3d.h"

bool	is_key_line(const char *line, const char *key)
{
	size_t	len;

	len = ft_strlen(key);
	return (ft_strncmp(line, key[i], len) == 0);
}

static int	get_texture_image(
		void *mlx, char *file_line, t_texture *texture, int i)
{
	char	*file;
	size_t	len;

	len = file_line - ft_strchr(file_line, '\n');
	file = ft_strndup(file_line, len);
	texture->img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file, &texture->width, &texture->height);
	if (texture->img_tex.img == NULL)
	{
		free(file);
		//destroy_texture_image(mlx, texture, i);
		return (EXIT_FAILURE);
	}
	debug_texture(file, texture[i], i,
		"after mlx_xpm_file_to_image");
	return (EXIT_SUCCESS);
}

int	parse_tex(const char *line, t_parse *parse)
{
	const char	*key[4] = {"NO ", "WE ", "EA ", "SO "};
	void		*mlx;
	t_texture	*texture;
	int			i;

	mlx = parse->game->mlx;
	texture = parse->game->texture;
	while (line != NULL)
	{
		i = 0;
		while (i < 4)
		{
			if (is_key_line(line, key[i]) == false)
			{
				i++;
				continue ;
			}
			if (get_texture_image(mlx, &line[3], texture[i]) != EXIT_SUCCESS)
			{
				destroy_texture_image(mlx, texture, i);
				return (EXIT_FAILURE);
			}
			break ;
		}
		find_next_line(line);
	}
	// get_texture_addr();
	return (EXIT_SUCCESS);
}
