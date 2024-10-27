#include "cub3d.h"

int	print_until_nl(int fd, const char *str)
{
	size_t	len;

	if (str == NULL)
		return (EXIT_FAILURE);
	len = ft_strchr(str, '\n') - str;
	write(fd, str, len);
	return (EXIT_SUCCESS);
}

// refactor (move file)
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

static int	get_texture_image(
		void *mlx, const char *file_line, t_texture *texture)
{
	char	*file;

	file = strdup_until_ch(file_line, '\n');
	if (file == NULL)
		return (EXIT_FAILURE + 1);
	texture->img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file, &texture->width, &texture->height);
	if (texture->img_tex.img == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s%s %s\n", ERR_PROMPT, EMSG_XPM_FILE, file);
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
	int			status;

	init_tex_keys(key, 4);
	mlx = parse->game->mlx;
	texture = parse->game->texture;
	while (line != NULL)// parse->flag BIT_NO, WE, EA, WE ... may be ...
	{
		i = 0;
		while (i < 4)
		{
			if (is_key_line(line, key[i]) == false)
			{
				i++;
				continue ;
			}
			status = get_texture_image(mlx, &line[3], &texture[i]);
			if (status != EXIT_SUCCESS)
			{
				i = i - (status != EXIT_FAILURE);
				destroy_texture_image(mlx, texture, i);
				return (EXIT_FAILURE);
			}
			break ;
		}
		// if (i == 4) // may be...
		// {
		// 	ft_dprintf(STDERR, "Error: texture direction\n");
		// 	print_until_nl(STDERR_FILENO, line);
		// 	return (EXIT_FAILURE);
		// }
		line = find_next_line(line);
	}
	// if (is_created_all_tex_image() == false) // may be ...
	// 	return (EXIT_FAILURE);
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
		{
			ft_dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_IMG_DATA_ADDR);
			return (EXIT_FAILURE);
		}
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
