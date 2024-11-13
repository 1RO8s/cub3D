# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 21:09:57 by kamitsui          #+#    #+#              #
#    Updated: 2024/11/14 05:11:10 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Build Library : nest of Cub3D/libs

# Build target
NAME = libdebug.a

## Makefile Option
MAKEFLAGS += --no-print-directory

# Directories
PROJECT_DIR = $(notdir $(CURDIR))
SRCS_DIR = srcs
OBJ_DIR = objs
DEP_DIR = .deps
INC_DIR = includes
PARENT_DIR = ..
LIBFT_DIR = $(PARENT_DIR)/libft
LIBPRINTF_DIR = $(PARENT_DIR)/ft_printf
LIBMLX_LINUX_DIR = $(PARENT_DIR)/minilibx-linux
LIBMLX_MAC_DIR = $(PARENT_DIR)/minilibx_mms_20200219
LIBMLXOPENGL_DIR = $(PARENT_DIR)/libmlxopengl
CUB3D_DIR = $(PARENT_DIR)/..

# Get OS type for choosing API
OS := $(shell uname)
# To Build MLX on macOS
ifeq ($(OS), Darwin)
LIBMLX_DIR = $(LIBMLX_LINUX_DIR)
endif
# To Build MLX on Linux
ifeq ($(OS), Linux)
LIBMLX_DIR = $(LIBMLX_LINUX_DIR)
endif


# Source files
SRCS = \
	   debug_map_data.c \
	   debug_player.c \
	   debug_ray.c \
	   debug_perform_dda.c \
	   debug_wall_slice.c \
	   debug_frame.c \
	   debug_texture.c \
	   debug_keypress.c \
	   debug_is_hit_flag.c \
	   debug_moved_player.c \
	   debug_texture_coordinate.c \
	   debug_texture_y_coordinate_overflow.c \
	   double_to_string.c \
	   debug_element_type.c \
	   init_debug_info.c \
	   open_log.c

# Object files and dependency files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
CF_OPTIMIZE = -O3
CF_ASAN = -g -fsanitize=address
#CF_THSAN = -g -fsanitize=thread
CF_GENERATE_DEBUG_INFO = -g
CF_INC = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBPRINTF_DIR)/includes \
		 -I$(LIBMLX_DIR) -I$(CUB3D_DIR)/includes
CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) $(CF_INC) $(CF_OPTIMIZE) $(CF_DEP) -c $< -o $@

$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: start $(NAME) end
.PHONY: all

start:
	@echo "${YELLOW}Starting build process for '${PROJECT_DIR}'...${NC}"
.PHONY: start

end:
	@echo "${YELLOW}Build process completed.${NC}"
.PHONY: end

# Target
$(NAME): $(DEPS) $(OBJS)
	ar rcs $@ $(OBJS)
	@echo "${GREEN}Successfully created archive: $@${NC}"

# Address sanitizer mode make rule
asan: fclean
	make $(NAME) WITH_ASAN=1
.PHONY: asan

# Thread sanitizer mode make rule
#thsan: fclean
#	make WITH_THSAN=1
#.PHONY: thsan

# Clean target
clean:
	@echo "${RED}Cleaning object files of '${PROJECT_DIR}'...${NC}"
	rm -rf $(OBJ_DIR) $(DEP_DIR)
.PHONY: clean

# Clean and remove library target
fclean: clean
	@echo "${RED}Removing archive file...${NC}"
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

# Color Definitions
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color
