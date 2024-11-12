#include "cub3d.h"

static int	get_texture_image(
		void *mlx, const char *file_line, t_texture *texture)
{
	char	*file;

	file = strdup_until_ch(file_line, '\n');
	if (file == NULL)
		return (EXIT_FAILURE);// may be ...
		//return (EXIT_FAILURE + 1);
	// if (is_exist_file(file) != true)
	//{
	//	put_error_msg(file, EMSG_NOT_EXIST_FILE);
	//	return (EXIT_FAILURE);
	//}
	texture->img_tex.img = (void *)mlx_xpm_file_to_image(
			mlx, file, &texture->width, &texture->height);
	if (texture->img_tex.img == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s%s: %s\n",
			ERR_PROMPT, EMSG_MLX_XPM_TO_IMG, file);
		free(file);
		return (EXIT_FAILURE);
	}
	debug_texture(file, *texture, "get_texture_image()");
	free(file);
	return (EXIT_SUCCESS);
}

bool	is_created_all_tex_image(int flag, const char *key[4], const int bit_tex[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((flag & bit_tex[i]) == 0x00)
		{
			put_error_msg(key[i], EMSG_ENTRY_MISS);
			//ft_dprintf(STDERR_FILENO, "%s%s: %s\n",
			//	ERR_PROMPT, key[i], EMSG_ENTRY_MISS);
			return (false);
		}
		i++;
	}
	return (true);
}

static int	create_texture_images(const char *line, t_parse *parse)
{
	const char	*key[4];
	void		*mlx;
	t_texture	*texture;
	int			i;
	int			status;
	const int	bit_tex[4] = {BIT_NORTH, BIT_WEST, BIT_EAST, BIT_SOUTH};

	init_tex_keys(key, 4);
	mlx = parse->game->mlx;
	texture = parse->game->texture;
	while (line != NULL && *line != '\n' && *line != '\0')// parse->flag BIT_NO, WE, EA, WE ... may be ...
	{
		i = 0;
		while (i < 4)
		{
			if (is_key_line(line, key[i]) == false)
			{
				i++;
				continue ;
			}
			if ((parse->flag & bit_tex[i]) > 0)
			{
				put_error_msg(key[i], EMSG_ENTRY_DUP);
				//ft_dprintf(STDERR_FILENO, "%s%s: %s\n",
				//	ERR_PROMPT, key[i], EMSG_ENTRY_DUP);
				return (EXIT_FAILURE);
			}
			parse->flag |= bit_tex[i];
			if (line[3] == '\n' || line[3] == '\0')
			{
				put_error_msg(key[i], EMSG_XPM_FILE);
				return (EXIT_FAILURE);
			}
			status = get_texture_image(mlx, &line[3], &texture[i]);
			if (status != EXIT_SUCCESS)
			{
				//i = i - (status != EXIT_FAILURE);
				destroy_texture_image(mlx, texture, i);
				//ft_dprintf(STDERR_FILENO, "%s%s: %s\n",
				//	ERR_PROMPT, key[i], EMSG_ENTRY_DUP);
				return (EXIT_FAILURE);
			}
			break ;
		}
		if (i == 4) // may be...
		{
			put_error_msg(line, EMSG_ENTRY_INVAL);
			//print_until_nl(STDERR_FILENO, line);
			return (EXIT_FAILURE);
		}
		line = find_next_line(line);
	}
	if (is_created_all_tex_image(parse->flag, key, bit_tex) == false)
		return (EXIT_FAILURE);
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
	if (get_textures_addr(texture) != EXIT_SUCCESS)
	{
		destroy_texture_image(mlx, texture, 4);
		return (EXIT_FAILURE);
	}
	parse->flag |= BIT_INIT_TEX;
	return (EXIT_SUCCESS);
}
