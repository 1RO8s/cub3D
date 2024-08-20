#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>//for sleep

#define MAP_WIDTH 25
#define MAP_HEIGHT 9
#define TILE_SIZE 30
#define DEBUG_TILE_SIZE 4
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
//#define DEBUG_WINDOW_WIDTH 200
//#define DEBUG_WINDOW_HEIGHT 200
#define DEBUG_SCREEN_WIDTH 200
#define DEBUG_SCREEN_HEIGHT 200
#define FOV 60

void render_debug_map(char *img_data, char *map[MAP_HEIGHT], int size_line);

typedef struct {
    int x, y;
} t_player;

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *addr; // img_data
    int bpp;
    int line_length;// size_line
    int endian;
    t_player player;
    char *map[MAP_HEIGHT];
} t_game;

typedef struct {
//    void *mlx;
//    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_debug;

void my_mlx_pixel_put(t_game *game, int x, int y, int color) {
    char *dst;

    dst = game->addr + (y * game->line_length + x * (game->bpp / 8));
    *(unsigned int*)dst = color;
}

void draw_ceiling_and_floor(t_game *game) {
    for (int y = 0; y < SCREEN_HEIGHT / 2; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            my_mlx_pixel_put(game, x, y, 0xADD8E6); // Light Blue for Ceiling
        }
    }
    for (int y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            my_mlx_pixel_put(game, x, y, 0x8B4513); // Brown for Floor
        }
    }
}

void draw_walls(t_game *game) {
    double ray_angle;
    double ray_x, ray_y;
    double delta_dist_x, delta_dist_y;
    double side_dist_x, side_dist_y;
    double perp_wall_dist;
    int step_x, step_y;
    int hit, side;
    int map_x, map_y;
    int line_height;
    int draw_start, draw_end;
    int color;

    for (int x = 0; x < SCREEN_WIDTH; x++) {
        ray_angle = (game->player.x - FOV / 2.0) + ((double)x / (double)SCREEN_WIDTH) * FOV;
        ray_x = game->player.x;
        ray_y = game->player.y;
        map_x = (int)ray_x / TILE_SIZE;
        map_y = (int)ray_y / TILE_SIZE;

        delta_dist_x = fabs(1 / cos(ray_angle));
        delta_dist_y = fabs(1 / sin(ray_angle));

        if (cos(ray_angle) < 0) {
            step_x = -1;
            side_dist_x = (ray_x - map_x * TILE_SIZE) * delta_dist_x;
        } else {
            step_x = 1;
            side_dist_x = ((map_x + 1) * TILE_SIZE - ray_x) * delta_dist_x;
        }
        if (sin(ray_angle) < 0) {
            step_y = -1;
            side_dist_y = (ray_y - map_y * TILE_SIZE) * delta_dist_y;
        } else {
            step_y = 1;
            side_dist_y = ((map_y + 1) * TILE_SIZE - ray_y) * delta_dist_y;
        }

        hit = 0;
        while (hit == 0) {
            if (side_dist_x < side_dist_y) {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            } else {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (game->map[map_y][map_x] == '1') hit = 1;
        }

        if (side == 0) perp_wall_dist = (map_x - ray_x + (1 - step_x) / 2) / cos(ray_angle);
        else perp_wall_dist = (map_y - ray_y + (1 - step_y) / 2) / sin(ray_angle);

        line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
        draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_start < 0) draw_start = 0;
        draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_end >= SCREEN_HEIGHT) draw_end = SCREEN_HEIGHT - 1;

        if (side == 0) {
            if (step_x > 0) color = 0xFFFFFF; // West wall - White
            else color = 0xFFFF00; // East wall - Yellow
        } else {
            if (step_y > 0) color = 0xFF0000; // South wall - Red
            else color = 0x808080; // North wall - Gray
        }

        for (int y = draw_start; y < draw_end; y++) {
            my_mlx_pixel_put(game, x, y, color);
        }
    }
}

int main(void) {
    t_game game;
	t_debug	debug;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
    game.img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    game.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_length, &game.endian);

 //   debug.mlx = mlx_init();
 //   debug.win = mlx_new_window(debug.mlx, DEBUG_WINDOW_WIDTH, DEBUG_WINDOW_HEIGHT, "Debug");
    debug.img = mlx_new_image(game.mlx, DEBUG_SCREEN_WIDTH, DEBUG_SCREEN_HEIGHT);
    debug.addr = mlx_get_data_addr(game.img, &game.bpp, &game.line_length, &game.endian);

    game.player.x = 14 * TILE_SIZE;
    game.player.y = 3 * TILE_SIZE;

    char *map[MAP_HEIGHT] = {
        "111111111111111111111111111",
        "10000000000000000000100001",
        "1001000000000P00000000001",
        "1001000000000000001000001",
        "1001000000000000001000001",
        "1001000000100000001000001",
        "10010000000000000001000001",
        "1001000000001000001000001",
        "111111111111111111111111111"
    };

    for (int i = 0; i < MAP_HEIGHT; i++) {
        game.map[i] = map[i];
    }

    draw_ceiling_and_floor(&game);
    draw_walls(&game);

	render_debug_map(debug.img, map, debug.line_length);
    mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
    mlx_put_image_to_window(game.mlx, game.win, debug.img, 800, 100);
    mlx_loop(game.mlx);

    return 0;
}
