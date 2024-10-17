# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 17:56:56 by kamitsui          #+#    #+#              #
#    Updated: 2024/10/17 11:53:49 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Build Cub3D : Top level build

# Directories
SRCS_DIR = \
		   ./srcs \
		   ./srcs/init_utils \
		   ./srcs/init_utils/parse_cubfile_utils \
		   ./srcs/draw_2d_utils \
		   ./srcs/draw_3d_utils \
		   ./srcs/draw_line_utils \
		   ./srcs/free_utils \
		   ./srcs/mlx_utils \
		   ./srcs/keypress_utils \
		   ./srcs/update_utils

OBJ_DIR = objs
INC_DIR = includes
DEP_DIR = .deps
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBFTPRINTF_DIR = $(LIB_DIR)/ft_printf
LIBMLX_DIR = $(LIB_DIR)/minilibx-linux
LIBDEBUG_DIR = $(LIB_DIR)/debug

# Source files
SRCS = \
	   main.c \
	   init_game.c \
	   render.c \
	   \
	   arg_check.c \
	   init_mlx_window.c \
	   init_mlx_image.c \
	   init_cub_contents.c\
	   \
	   init_texture.c \
	   init_floor_and_ceiling.c \
	   init_map.c \
	   is_enable_map.c \
	   init_player.c \
	   set_direction.c \
	   \
	   draw_2d_player.c \
	   draw_2d_wall.c \
	   \
	   init_ray.c \
	   perform_dda.c \
	   set_wall_slice.c \
	   draw_vertical_line.c \
	   \
	   draw_line.c \
	   init_line.c \
	   \
	   destroy_texture_image.c \
	   \
	   hook_functions.c \
	   my_mlx_pixel_put.c \
	   \
	   set_move_strafe_flag.c \
	   set_rotate_flag.c \
	   handle_quit_invalid_keys.c \
	   \
	   is_hit_flag.c \
	   is_collision_detection.c \
	   move_and_strafe.c \
	   rotate.c

	   #debug.c

# Object files and dependency files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Library name
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
LIBDEBUG = $(LIBDEBUG_DIR)/libdebug.a
LIBS = $(LIBDEBUG) $(LIBFT) $(LIBFTPRINTF) $(LIBMLX)

# Build target
NAME = cub3D

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
CF_OPTIMIZE = -O3
CF_ASAN = -g -fsanitize=address
#CF_THSAN = -g -fsanitize=thread
CF_GENERATE_DEBUG_INFO = -g
CF_INC = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBFTPRINTF_DIR)/includes \
	 -I$(LIBMLX_DIR) -I$(LIBDEBUG_DIR)/includes
CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Get OS type for choosing API
OS := $(shell uname)
# To link internal macOS API
ifeq ($(OS), Darwin)
LIBMLX := $(LIBMLX_DIR)/libmlx_Darwin.a
CF_API = -L./lib/minilibx-linux -lmlx_Darwin -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
endif
# To link internal Linux API
ifeq ($(OS), Linux)
LIBMLX := $(LIBMLX_DIR)/libmlx_Linux.a
CF_API = -L$(LIBMLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz
endif

# Makefile Option
MAKEFLAGS += --no-print-directory

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) $(CF_INC) $(CF_OPTIMIZE) $(CF_DEP) -c $< -o $@

$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: start build_lib $(NAME) end display_art
.PHONY: all

# Out starting message
start:
	@echo "${YELLOW}Starting build process for '${NAME}'...${NC}"
.PHONY: start

# Build libraries
$(LIBS): build_lib

build_lib:
	make -C $(LIB_DIR)
	@echo "${YELLOW}Build process completed for '${LIBS}'.${NC}"
.PHONY: build_lib

# Out ending message
end:
	@echo "${YELLOW}Build process completed $(NAME).${NC}"
.PHONY: end

display_art:
	$(ASCII_ART)
.PHONY: display_art

# Target
$(NAME): $(LIBS) $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(CF_API) -o $(NAME)
	@echo "${GREEN}Successfully created execute: $@${NC}"

# Option : make rules

# Address sanitizer mode make rule
asan: fclean
	make WITH_ASAN=1
.PHONY: asan

# Leak check
check: fclean
	make WITH_VALGRIND=1
	$(VALGRIND_USAGE)
.PHONY: check

# Clean target
clean:
	@echo "${RED}Cleaning object files of '${NAME}'...${NC}"
	rm -rf $(OBJ_DIR) $(DEP_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBFTPRINTF_DIR) clean
	make -C $(LIBMLX_DIR) clean
	make -C $(LIBDEBUG_DIR) clean
.PHONY: clean

# Clean and remove library target
fclean: clean
	@echo "${RED}Removing archive file...${NC}"
	rm -f $(LIBFT)
	rm -f $(LIBFTPRINTF)
	rm -f $(LIBMLX)
	rm -f $(LIBDEBUG)
	rm -f $(NAME)
	@echo "${GREEN}Archive file removed.${NC}"
.PHONY: fclean

# Rebuild target
re: fclean all
.PHONY: re

# Enable dependency file
-include $(DEPS)

# Enabel Address sanitizer
ifdef WITH_ASAN
CFLAGS += $(CF_ASAN)
endif

# Enabel Thread sanitizer
ifdef WITH_THSAN
CFLAGS += $(CF_THSAN)
endif

# Enabel valgrind tool
ifdef WITH_VALGRIND
CFLAGS += $(CF_GENERATE_DEBUG_INFO)
endif

# Color Definitions
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

# ASCII Art
define ASCII_ART
@echo " _________________________________________________"
@echo "< Usage : ./cub3D map/*.cub                       >"
@echo "<  $$ ./cub3D map/*.cub                            >"
@echo "<  or                                             >"
@echo "<  $$ source config/alias.zsh                      >"
@echo "<  $$ run                                          >"
@echo "<                                                 >"
@echo "--------------------------------------------------"
@echo "       \   ^__^"
@echo "        \  (oo)\_______"
@echo "           (__)\       )\\/\\"
@echo "               ||----w |"
@echo "               ||     ||\n"
endef

# Valgrind Usage
define VALGRIND_USAGE
@echo "        /"
@echo "       /"
@echo " __________________________________________________________________________"
@echo "< Vargrind Usage :                                                         >"
@echo "<  valgrind --leak-check=full ./cub3D map/*.cub                            >"
@echo "<  or                                                                      >"
@echo "<  $$ source config/alias.zsh                                               >"
@echo "<  $$ leak_check                                                           >"
@echo "---------------------------------------------------------------------------"
endef
