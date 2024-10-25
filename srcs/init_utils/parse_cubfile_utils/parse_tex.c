#include "cub3d.h"

bool	is_key_line(const char *line, const char *key)
{
	size_t	len;

	len = ft_strlen(key);
	return (ft_strncmp(line, key, len) == 0);
}

static int	get_texture_image(
		void *mlx, const char *file_line, t_texture *texture)
{
	char	*file;
	size_t	len;

	len = ft_strchr(file_line, '\n') - file_line;
	file = ft_strndup(file_line, len);
	texture->img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file, &texture->width, &texture->height);
	if (texture->img_tex.img == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error: texture file %s\n", file);
		free(file);
		return (EXIT_FAILURE);
	}
	debug_texture(file, *texture, "get_texture_image()");
	return (EXIT_SUCCESS);
}

static int	create_texture_images(const char *line, t_parse *parse)
{
	const char	*key[4];
	void		*mlx;
	t_texture	*texture;
	int			i;

	init_tex_keys(key, 4);
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
			if (get_texture_image(mlx, &line[3], &texture[i]) != EXIT_SUCCESS)
			{
				destroy_texture_image(mlx, texture, i);
				return (EXIT_FAILURE);
			}
			break ;
		}
		line = find_next_line(line);
	}
	return (EXIT_SUCCESS);
}

static int	get_textures_addr(t_texture *texture)
{
	int		i;
	t_img	*img;

	i = 0;
	while (i < 4)
	{
		img = (t_img *)&texture[i].img_tex;
		img->addr = (char *)mlx_get_data_addr(
				img->img, &img->bpp, &img->line_length, &img->endian);
		if (img->addr == NULL)
			return (EXIT_FAILURE);
		debug_img_tex(texture[i].debug.fd, texture[i].img_tex, i,
			"after mlx_get_data_addr()");
		i++;
	}
	return (EXIT_SUCCESS);
}
int	parse_tex(const char *line, t_parse *parse)
{
	void		*mlx;
	t_texture	*texture;

	mlx = parse->game->mlx;
	texture = parse->game->texture;
	if (create_texture_images(line, parse) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	printf("parse end\n");
	if (get_textures_addr(texture) != EXIT_SUCCESS)
	{
		destroy_texture_image(mlx, texture, 4);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_fc(const char *line, t_parse *parse)
{
	(void)line;
	(void)parse;
	return (EXIT_SUCCESS);
}
int	parse_map(const char *line, t_parse *parse)
{
	(void)line;
	(void)parse;
	return (EXIT_SUCCESS);
}
