/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/28 05:32:40 by kamitsui         ###   ########.fr       */
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

void	debug_element_type(int fd, const char *str, const char *msg)
{
	t_enum_elem	type;
	static int	count = 0;

	if (IS_DEBUG == false)
		return ;
	dprintf(fd,
		"\n\n>>> func debug_element_type() ... call by '%s' <<<\n", msg);
	type = get_type_element(str);
	dprintf(fd, "\tNo.%d first_char[%c]%p\n", count, *str, str);
	dprintf(fd, "\telement type [%d] ... tex[%d] fc[%d] map[%d] err[%d]\n",
			(int)type, (int)ENUM_TEX, (int)ENUM_FC, (int)ENUM_MAP, (int)ENUM_ELEMENT_ERR);//debug
	dprintf(fd, "\t---- current element ----\n");
	dprintf(fd, "%s\t-------------------------\n", str);
	count++;
}

/**
 * @brief Parse the cub file contents
 */
static int	parse_cubfile(t_game *game, const char *element)
{
	t_parse			parse;
	t_parse_elem	func[3] = {parse_tex, parse_fc, parse_map};
	t_enum_elem		type;

	parse.flag = 0x00;
	parse.game = game;
	if (*element == '\n')
		element = find_next_element(element);
	while (element != NULL)
	{
		type = get_type_element(element);
		debug_element_type(game->debug.fd, element, "parse_cubfile()");
		if (type == ENUM_ELEMENT_ERR)
		{
			ft_dprintf(STDERR_FILENO, "Error: cub file\n");
			return (EXIT_FAILURE);
		}
		if (func[type](element, &parse) != EXIT_SUCCESS)
		{
			//if (is_initialized(BIT_INIT_TEX) == true)
			//	destroy_texture_image(game->mlx, game->texture, 4);
			//if (is_initialized(BIT_INIT_MAP) == true)
			//	free_double_pointer(game->map.data);
			return (EXIT_FAILURE);
		}
		element = find_next_element(element);
	}
	//exit(0);// debug
	init_frame(game);
	return (EXIT_SUCCESS);
}
// Before branch <parse/cub_file>
//static int	parse_cubfile(t_game *game, char *file_contents)
//{
//	if (init_texture(game->mlx, game->texture, file_contents) != EXIT_SUCCESS)
//		return (EXIT_FAILURE);
//	if (init_floor_and_ceiling(game, file_contents) != EXIT_SUCCESS)
//	{
//		destroy_texture_image(game->mlx, game->texture, 4);
//		return (EXIT_FAILURE);
//	}
//	if (init_map(&game->map, file_contents) != EXIT_SUCCESS)
//	{
//		destroy_texture_image(game->mlx, game->texture, 4);
//		return (EXIT_FAILURE);
//	}
//	if (init_player(&game->map, &game->player) != EXIT_SUCCESS)
//	{
//		destroy_texture_image(game->mlx, game->texture, 4);
//		free_double_pointer(game->map.data);
//		return (EXIT_FAILURE);
//	}
//	init_frame(game);
//	return (EXIT_SUCCESS);
//}

int	init_cub_contents(t_game *game, char *filename)
{
	char	*file_contents;
	int		status;

	file_contents = read_cubfile(filename);
	if (file_contents == NULL)
		return (EXIT_FAILURE);
	status = parse_cubfile(game, (const char *)file_contents);
	free(file_contents);
	if (status != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
