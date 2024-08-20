/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_debug_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 03:49:23 by kamitsui          #+#    #+#             */
/*   Updated: 2024/08/21 04:00:43 by kamitsui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DEBUG_TILE_SIZE 4
#define MAP_WIDTH 25
#define MAP_HEIGHT 9
void draw_square(char *img_data, int x, int y, int color, int size_line)
{
    for (int i = 0; i < DEBUG_TILE_SIZE; i++)
    {
        for (int j = 0; j < DEBUG_TILE_SIZE; j++)
        {
            int pixel = (y * DEBUG_TILE_SIZE + i) * size_line + (x * DEBUG_TILE_SIZE + j) * 4;
            *(unsigned int *)(img_data + pixel) = color;
        }
    }
}

void render_debug_map(char *img_data, char *map[MAP_HEIGHT], int size_line)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            int color;
            if (map[y][x] == '1')
                color = 0xFFFFFF; // White for walls
            else
                //color = 0x000000; // Black for empty space
                color = 0x808080; // Gray for empty space

            draw_square(img_data, x, y, color, size_line);
        }
    }
}
