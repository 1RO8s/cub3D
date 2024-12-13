/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:49:52 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:03:33 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	char	*file_contents;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		printf( "%s%s\n", ERR_PROMPT, EMSG_OPEN_FAILED);
		return (NULL);
	}
	file_contents = get_file_contents(fd);
	if (file_contents == NULL)
	{
		printf( "%s%s\n", ERR_PROMPT, EMSG_READ_FAILED);
		return (NULL);
	}
	close(fd);
	return (file_contents);
}

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
