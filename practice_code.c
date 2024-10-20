#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ------------------ minilibX exist leak bug ------------------
// cc practice_code.c -Ilib/minilibx-linux/ -L./lib/minilibx-linux -lmlx_Linux -L/usr/X11R6/lib -lX11 -lXext -g
// valgrind --leak-check=full --show-leak-kinds=all ./a.out
#include <mlx.h>

typedef struct s_game {
	void	*mlx;
	void	*win;
}	t_game;

static int	end_game(t_game *game)
{
	printf("quit Example\n");
	mlx_destroy_window(game->mlx, game->win);// still reachable: 62 blocks -> 60 blocks
	free(game->mlx);// still reachable: 60 blocks -> 59 blocks
	exit(0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	if (game.mlx == NULL)
	    return 1;
	game.win = mlx_new_window(game.mlx, 1024, 512, "Example");
	if (game.win == NULL)
	    return 1;
	mlx_hook(game.win, 17, 1L << 17, end_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
// ------------------ leak check ------------------ extract_value() OK
// compile macOS
//  cc lib/libft/libft.a practice_code.c srcs/init_utils/arg_check.c -Iincludes -Ilib/libft -g
// compile linux
//  cc -g practice_code.c srcs/init_utils/arg_check.c lib/libft/libft.a -Iincludes -Ilib/libft
//  valgrind ./a.out
//#include "libft.h"
//#define LINE "NO ./texture/sonic.xpm"
//char	*extract_value(char *line, char *identifier);
//int	main(void)
//{
//	char	*value;
//	printf("---- line is -----\n");
//	printf("%s", LINE);
//	printf("\n---------------------\n");
//	value = extract_value(ft_strdup(LINE), "NO");
//	printf("value[%p]\n", value);
//	printf("%s", value);
//	free(value);
//	return (0);
//}
// ------------------ leak check ------------------ get_element_line() OK
// compile macOS
//  cc lib/libft/libft.a practice_code.c srcs/init_utils/arg_check.c -Iincludes -Ilib/libft -g
// compile linux
//  cc -g practice_code.c srcs/init_utils/arg_check.c lib/libft/libft.a -Iincludes -Ilib/libft
//  valgrind ./a.out
//#define FILE_CONTENTS "1234567890\nasdfgh\nnoooooo\nwwwwNOyyyyyy\nNO ./texture/sonic.xpm"
//char	*get_element_line(char *map, char *identifier);
//int	main(void)
//{
//	char	*line;
//	printf("---- file_contents is -----\n");
//	printf("%s", FILE_CONTENTS);
//	printf("\n---------------------\n");
//	line = get_element_line(FILE_CONTENTS, "NO");
//	printf("line[%p]\n", line);
//	printf("%s", line);
//	free(line);
//	return (0);
//}
// ------------------ leak check ------------------ read_cubefile() OK
// compile macOS
//  cc lib/libft/libft.a practice_code.c srcs/init_utils/arg_check.c -Iincludes -Ilib/libft -g
// compile linux
//  cc practice_code.c srcs/init_utils/arg_check.c lib/libft/libft.a -Iincludes -Ilib/libft -g
//  valgrind ./a.out
//
//char	*read_cubfile(char *filepath);
//
//int	main(void)
//{
//	char	*filename = "aaa.txt";
//	char	*file_contents;
//
//	file_contents = read_cubfile(filename);
//	printf("--- filename ---\n%s\n", filename);
//	printf("--- read_contents ---\n%s", file_contents);
//	free(file_contents);
//	return (0);
//}
// ------------------ xpm data -------------------- unsuccess
// compile command
//cw practice_code.c -Ilib/minilibx-linux/ -L./lib/minilibx-linux -lmlx_Darwin -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -g -fsanitize=address
//#include <mlx.h>
//
//char *simple_xpm_data[] = {
//    "4 4 2 1",             // Width: 4, Height: 4, Colors: 2, Characters per pixel: 1
//    "0 c #FFFFFFFFFFFF",         // Color '0' is white (#FFFFFF)
//    "1 c #000000000000",         // Color '1' is black (#000000)
//    "0101",                // Row 1: Black, White, Black, White
//    "1010",                // Row 2: White, Black, White, Black
//    "0101",                // Row 3: Black, White, Black, White
//    "1010"                // Row 4: White, Black, White, Black
//    NULL                   // NULL to mark the end of the XPM data
//};
//
//size_t	count_size(char **xpm_data)
//{
//	size_t	count;
//	int		i;
//
//	if (xpm_data == NULL)
//		return (0);
//	count = 1;
//	i = 0;
//	while(xpm_data[i] != NULL)
//	{
//		count++;
//		i++;
//	}
//	return (count);
//}
//
//void	print_xpm_data(char **xpm_data, int size)
//{
//	int	i;
//
//	i = 0;
//	while(i < size)
//	{
//		printf("%s\n", xpm_data[i]);
//		i++;
//	}
//}
//
//int	dup_xpm_data(char **dst, char **src, int size)
//{
//	int	i;
//
//	i = 0;
//	while(i < size)
//	{
//		dst[i] = strdup(src[i]);
//		if (dst[i] == NULL)
//		{
//			// free 2d array
//			return (EXIT_FAILURE);
//		}
//		i++;
//	}
//	return (EXIT_SUCCESS);
//}
//
//void	free_xpm_data(char **xpm_data)
//{
//	int	i;
//
//	i = 0;
//	while(xpm_data[i] != NULL)
//	{
//		free(xpm_data[i]);
//		i++;
//	}
//	free(xpm_data);
//}
//
//int main() {
//    void *mlx_ptr;
//    void *win_ptr;
//    void *img_ptr;
//    int width, height;
//
//	size_t size;
//	//size = count_size(simple_xpm_data);
//	size = sizeof(simple_xpm_data) / 8;
//	printf("size [%zu]\n", size);
//	//return (0);
//	char	**xpm_data;
////    	"4 4 2 1",             // Width: 4, Height: 4, Colors: 2, Characters per pixel: 1
////    	"0 c #FFFFFF",         // Color '0' is white (#FFFFFF)
////    	"1 c #000000",         // Color '1' is black (#000000)
////    	"0101",                // Row 1: Black, White, Black, White
////    	"1010",                // Row 2: White, Black, White, Black
////    	"0101",                // Row 3: Black, White, Black, White
////    	"1010"};                // Row 4: White, Black, White, Black
//	xpm_data = (char **)malloc(sizeof(char *) * size);
//	if (dup_xpm_data(xpm_data, simple_xpm_data, sizeof(simple_xpm_data)/8) != EXIT_SUCCESS)
//	{
//		free(xpm_data);
//		return (1);
//	}
//	print_xpm_data(xpm_data, size);
//	printf("sizeof(xpm_data) = %lu\n", sizeof(xpm_data)/8);
//
//    // Initialize MiniLibX
//    mlx_ptr = mlx_init();
//    if (mlx_ptr == NULL) {
//        return 1;  // Failed to initialize MiniLibX
//    }
//
//    // Convert XPM data to image
//    img_ptr = mlx_xpm_to_image(mlx_ptr, xpm_data, &width, &height);
//    if (img_ptr == NULL) {
//		printf("Error: mlx_xpm_to_image()\n");
//        return 1;  // Failed to create an image from XPM data
//    }
//
//    // Create a window
//    win_ptr = mlx_new_window(mlx_ptr, width+100, height+100, "Simple XPM Example");
//    if (win_ptr == NULL) {
//        return 1;  // Failed to create a window
//    }
//
//    // Display the image in the window at coordinates (50, 50)
//    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 50, 50);
//
//    // Run the event loop
//    mlx_loop(mlx_ptr);
//
//    return 0;
//}

// ------------------ put image from xpm file --------------------
// compile command
//cw practice_code.c -Ilib/minilibx-linux/ -L./lib/minilibx-linux -lmlx_Darwin -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit -g -fsanitize=address
//cc practice_code.c -Ilib/minilibx-linux/ -L./lib/minilibx-linux -lmlx_Linux -L/usr/X11R6/lib -lX11 -lXext -g
//#include <mlx.h>
//
//typedef struct s_game {
//    void *mlx_ptr;
//    void *win_ptr;
//    void *img_ptr;
//	void *img_ptr2;
//}	t_game;
//
//#define KEY_ESC 53
//
//int	my_key_function(int keycode, t_game *game)
//{
//	if (keycode == KEY_ESC)
//	{
//		// free resource
//		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
//		mlx_destroy_image(game->mlx_ptr, game->img_ptr2);
//		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
//		free(game->mlx_ptr);
//		exit(0);
//	}
//}
//
//int	close_window(t_game *game)
//{
//	mlx_destroy_image(game->mlx_ptr, game->img_ptr);
//	mlx_destroy_image(game->mlx_ptr, game->img_ptr2);
//	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
//	free(game->mlx_ptr);
//	exit(0);
//}
//
//int main() {
//	t_game	game;
//    int width, height;
//
//    // Initialize MiniLibX
//    game.mlx_ptr = mlx_init();
//    if (game.mlx_ptr == NULL) {
//        return 1;  // Failed to initialize MiniLibX
//    }
//
//	// Get image from xpm file
//	game.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "texture/sonic.xpm", &width, &height);
//	if (game.img_ptr == NULL) {
//	    // Handle error: file might not exist or there was an issue reading it
//	    fprintf(stderr, "Failed to load texture.\n");
//	}
//	game.img_ptr2 = mlx_xpm_file_to_image(game.mlx_ptr, "texture/planks.xpm", &width, &height);
//
//    // Create a window
//    game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "Simple XPM Example");
//    if (game.win_ptr == NULL) {
//        return 1;  // Failed to create a window
//    }
//
//	// Clear
//    mlx_clear_window(game.mlx_ptr, game.win_ptr);
//
//    // Display the image in the window at coordinates (50, 50)
//    mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_ptr, 50, 50);
//    mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_ptr2, 150, 50);
//
//
//
//	mlx_key_hook(game.win_ptr, &my_key_function, &game);
//	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
//
//    // Run the event loop
//    mlx_loop(game.mlx_ptr);
//	//system("leaks ./a.out");// ?? does not done ... why ?
//    return 0;
//}
//
// ------------------ return structure ------------
//typedef struct	s_abc {
//	int		a;
//	int		b;
//	double	c;
//}	t_abc;
//
//t_abc	get_abc(int a, int b, double c)
//{
//	t_abc	abc;
//
//	abc.a = a;
//	abc.b = b;
//	abc.c = c;
//	return (abc);
//}
//
//int	main(void)
//{
//	t_abc	abc;
//
//	abc = get_abc(42, 123, 42.4242);
//	printf("a[%d] b[%d] c[%f]\n", abc.a, abc.b, abc.c);
//	return (0);
//}

// ------------------ cast double to int -----------
//int	main(void)
//{
//	int	int_var;
//	double double_var;
//
//	double_var = 5.9999999;
//	int_var = (int)double_var;
//	printf("double[%8.10f] int[%d]\n", double_var, int_var);
//	return (0);
//}

// ------------------ define mapdata ---------------
//#define TEST_DATA \
//	{ \
//		"1111111111", \
//		"1000000001", \
//		"1000000001", \
//		"1000N00001", \
//		"1000110001", \
//		"1000000001", \
//		"1000110001", \
//		"1000000001", \
//		"1000000001", \
//		"1111111111", \
//		NULL \
//	}
//
//int	main(void)
//{
//	const char	*data[] = TEST_DATA;
//	int i = 0;
//	while (data[i] != NULL)
//	{
//		printf("%s %p\n", data[i], data[i]);
//		i++;
//	}
//	return (0);
//}

// ------------------ FOV -----------------
//double calculate_camera_plane(double fov_degrees) {
//    double fov_radians = fov_degrees * (M_PI / 180.0);  // Convert to radians
//	printf("radian[%f]\n", fov_radians);
//    return tan(fov_radians / 2.0);  // Return the half-width of the camera plane
//}
//
//int	main(int argc, char *argv[])
//{
//	double	fov_degree;
//
//	if (argc != 2)
//		return (1);
//	//fov_degree = (double)atoi(argv[1]);
//	(void)argv;
//	fov_degree = 66;
//	printf("deg[%f] -> camera_plane_x[%f]\n", fov_degree, calculate_camera_plane(fov_degree));
//	return (0);
//}
