/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube_contents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/10/05 23:34:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief initialize the player
 *
 * @note
 *  player view point , ray direction, camera forcal plane direction
 */
static int	set_position_and_direction(t_player *player, int x, int y, char direction)
{
	player->view_point.x = x + 0.5;
	player->view_point.y = y + 0.5;
	return (set_direction(direction, player));
}

/**
 * @brief check the player position
 */
static bool	is_player_position(char map_point)
{
	return (map_point == 'N' || map_point == 'S'
		|| map_point == 'W' || map_point == 'E');
}

/**
 * @brief get player's position
 */
int	init_player(t_map *map, t_player *player)
{
	int	x;
	int	y;
	int	count_player;

	count_player = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player_position(map->data[y][x]) == true)
			{
				if (count_player != 0)
				{
					// syntax error : invalid map
					return (EXIT_FAILURE);
				}
				count_player++;
				if (set_position_and_direction(player, x, y, map->data[y][x])
					!= EXIT_SUCCESS)
					return (EXIT_FAILURE);
				map->data[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	debug_map_data(*map, "parse_map() after");
	return (EXIT_SUCCESS);
}

static char	*get_xpm_file_name(char *file_contents, const char *key)
{
	char	*line;

	line = get_element_line(file_contents, key);
	if (line == NULL)
		return (NULL);
	return (extract_value(line, key));
}

void	destroy_image(void *mlx, void *img[4], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		mlx_destroy_image(mlx, img[i]);
		i++;
	}
}

static int	get_texture_image(void *mlx, t_texture *texture, char *file_contents)
{
	const char	key[4] = {"NO", "SO", "WE", "EA"};
	int			i;
	t_texture	texture;

	i = 0;
	while (i < 4 && (status == EXIT_SUCCESS))
	{
		xpm_file = get_xpm_file_name(file_contents, key[i]);
		if (xpm_file == NULL)
		{
			destroy_image(mlx, texture->img, i);
			return (EXIT_FAILURE);
		}
		texture->img_texture[i] = mlx_xpm_file_to_image(mlx, xpm_file,
				&texture->width[i], &texture->height[i]);
		if (texture->img_texture[i] == NULL)
		{
			free(xpm_file);
			destroy_image(mlx, texture->img, i);
			return (EXIT_FAILURE);
		}
		free(xpm_file);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	enable_texture_image(t_texture *texture)
{
	int		i;
	void	*img;
	char	*addr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;

	i = 0;
	while (i < 4)
	{
		img = texture->img[i];
		if (img == NULL)
			return (EXIT_FAILURE);
		bits_per_pixel = &(img_texture[i]->bpp);
		size_line = &(img_texture[i]->line_length);
		endian = &(img_texture[i]->endian);
		addr = (char *)mlx_get_data_addr(img, bits_per_pixel, size_line, endian);
		if (addr == NULL)
			return (EXIT_FAILURE);
		img_texture[i]->addr = addr;
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	init_texture(void *mlx, t_texture *texture, char *file_contents)
{
	if (get_texture_image(mlx, texture, file_contents) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (enable_image_address(texture) == EXIT_SUCCESS)
	{
		// destroy texture image[4]
		return (EXIT_FAILURE);
	}
	debug_texture(mlx->debug.fd, texture, file_contents);
	return (EXIT_SUCCESS);
}

//int	has_elements(t_game *g)
//{
//	char	*floor_val;
//	char	*ceil_val;
//
//	// printf("--- has_wall_textures ---\n");
//	if (!has_textures(g))
//		return (false);
//	floor_val = get_element_line(g->cubfile, "F");
//	ceil_val = get_element_line(g->cubfile, "C");
//	if (floor_val == NULL || ceil_val == NULL)
//		return (false);
//	floor_val = extract_value(floor_val, "F");
//	ceil_val = extract_value(ceil_val, "C");
//	if (floor_val == NULL || ceil_val == NULL)
//		return (false);
//	g->floor = convert2color(floor_val);
//	g->ceiling = convert2color(ceil_val);
//	if (g->floor == -1 || g->ceiling == -1)
//		return (false);
//	floor_val = ft_free(floor_val);
//	ceil_val = ft_free(ceil_val);
//	return (true);
//}

/**
 * @brief Parse the cube file contents
 */
int	parse_cube_contents(t_game *game, char *file_contents)
{
	if (init_texture(game->mlx, &game->texture, file_contents) != EXIT_SUCCESS)// fix
		return (EXIT_FAILURE);
	if (init_map(game->map, file_contents) != EXIT_SUCCESS)// fix
		return (EXIT_FAILURE);
	if (init_player(game->map, game->player) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
