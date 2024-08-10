/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:19:09 by hnagasak          #+#    #+#             */
/*   Updated: 2024/08/11 05:08:16 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"

# define MAP_WIDTH 25
# define MAP_HEIGHT 9
# define TILE_SIZE 30
# define SCREEN_WIDTH 1900
# define SCREEN_HEIGHT 1000
# define FOV 60

typedef struct
{
	int x, y;
}				t_player;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_player	player;
	t_vector	pos;
	t_vector	dir;
	char		**map;
	char		*cubfile;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			floor;
	int			ceiling;
}				t_game;

char			*read_cubfile(char *filepath);
int				arg_check(int argc, char *argv[]);
int				set_map_info(t_game *g);

void			print_map_info(t_game *game);

// utils.c
void			*ft_free(void *ptr);
void			free_double_pointer(char **array);

#endif
