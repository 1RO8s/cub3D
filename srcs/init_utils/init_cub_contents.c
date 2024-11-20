/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/11/21 02:09:33 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_frame(t_game *game)
{
	t_frame	*frame;

	frame = &game->frame;
	frame->map = (t_map *)&game->map;
	frame->img_3d = (t_img *)&game->img_3d;
	frame->texture = (t_texture *)&game->texture;
	frame->player = (t_player *)&game->player;
	frame->flag = 0;
}

static bool	is_find_element(const char *element)
{
	if (element == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_EMPTY_CUB);
		return (false);
	}
	return (true);
}

/**
 * @brief Parse the cub file contents
 */
static int	parse_cubfile(t_parse *parse, t_game *game, const char *element)
{
	static t_parse_elem	func[3] = {parse_tex, parse_fc, parse_map};
	t_enum_elem			type;

	if (*element == '\n')
		element = find_next_element(element);
	if (is_find_element(element) == false)
		return (EXIT_FAILURE);
	while (element != NULL)
	{
		type = get_type_element(element);
		debug_element_type(game->debug.fd, element, "parse_cubfile()");
		if (type == ENUM_ELEMENT_ERR)
		{
			put_error_msg(element, EMSG_ENTRY_INVAL);
			return (EXIT_FAILURE);
		}
		if (func[type](element, parse) != EXIT_SUCCESS)
		{
			if (is_hit_flag(parse->flag, BIT_INIT_TEX) == true)
				destroy_texture_image(game->mlx, game->texture, 4);
			if (is_hit_flag(parse->flag, BIT_INIT_MAP) == true)
				free_double_pointer(game->map.data);
			return (EXIT_FAILURE);
		}
		element = find_next_element(element);
	}
	return (EXIT_SUCCESS);
}

static char	*get_file_contents(int fd)
{
	char	*file_contents;
	char	*line;
	char	*temp;

	file_contents = NULL;
	temp = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (file_contents == NULL)
			file_contents = ft_strjoin("", line);
		else
		{
			temp = ft_strjoin(file_contents, line);
			free(file_contents);
			file_contents = temp;
		}
		line = ft_free(line);
		if (file_contents == NULL)
			return (NULL);
		line = get_next_line(fd);
	}
	return (file_contents);
}

static char	*read_cubfile(char *filepath)
{
	int		fd;
	char	*map;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_OPEN_FAILED);
		return (NULL);
	}
	map = get_file_contents(fd);
	if (map == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s%s\n", ERR_PROMPT, EMSG_READ_FAILED);
		return (NULL);
	}
	close(fd);
	return (map);
}

int	init_cub_contents(t_game *game, char *filename)
{
	char	*file_contents;
	int		status;
	t_parse	parse;

	file_contents = read_cubfile(filename);
	if (file_contents == NULL)
		return (EXIT_FAILURE);
	parse.flag = 0x00;
	parse.game = game;
	status = parse_cubfile(&parse, game, (const char *)file_contents);
	init_frame(game);
	free(file_contents);
	if (status != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
