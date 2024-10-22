/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/22 21:38:19 by kamitsui         ###   ########.fr       */
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

void	debug_element_type(int fd, const char *str)
{
	t_enum_elem	type;

	type = get_type_element(str);
	dprintf(fd, "\telement type [%d] c[%c]%p\n", (int)type, *str, str);
}

/**
 * @brief Parse the cub file contents
 */
static int	parse_cubfile(t_game *game, const char *element)
{
	t_parse			parse;
	//t_parse_element	func[3] = {parse_tex, parse_fc, parse_map};
	t_enum_elem		type;
	//size_t			row;

	parse.flag = 0x00;
	parse.game = game;
	//row = 1;
	printf(">> file_contents\n");
	printf("----------\n%s----------\n", element);
	printf("type tex[%d] fc[%d] map[%d] err[%d]\n",
			(int)ENUM_TEX, (int)ENUM_FC, (int)ENUM_MAP, (int)ENUM_ELEMENT_ERR);//debug
	//printf("before[%c] [%p]\n", *element, element);
	if (*element == '\n')
		element = find_next_element(element);
	//printf("after [%c] [%p]\n", *element, element);
	//exit(0);
	while (element != NULL)
	{
		type = get_type_element(element);
		debug_element_type(game->debug.fd, element);
		if (type == ENUM_ELEMENT_ERR)
		{
			ft_dprintf(STDERR_FILENO, "Error: cub file\n");
			//ft_dprintf(STDERR_FILENO, "line[%zu]: %10s", row, element);// refactor '\n'
			return (EXIT_FAILURE);
		}
		//if (func[type](element, &parse) != EXIT_SUCCESS)
		//	return (EXIT_FAILURE);
		element = find_next_element(element);
		//row++;
	}
	(void)init_frame;// remove
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
