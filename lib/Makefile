# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 22:03:00 by kamitsui          #+#    #+#              #
#    Updated: 2024/09/01 22:31:55 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Build Libraries : nest of Cub3D
# target -> MiniLibX, Libft, ft_printf

## Makefile Option
MAKEFLAGS += --no-print-directory

# Directories
LIBFT_DIR = libft
LIBFTPRINTF_DIR = ft_printf
LIBMLX_LINUX_DIR = minilibx-linux
LIBMLX_MAC_DIR = minilibx_mms_20200219
LIBMLXOPENGL_DIR = libmlxopengl
RESOURCE_DIR = ../resource
LIBDEBUG_DIR = debug

# Resource files
RESOURCE_MLX_LINUX = minilibx-linux.tgz
RESOURCE_MLX_MAC = minilibx_mms_20200219_beta.tgz
RESOURCE_MLX_OPENGL = minilibx_opengl.tgz

# Library name
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
LIBDEBUG = $(LIBDEBUG_DIR)/libdebug.a

# Get OS type for choosing API
OS := $(shell uname)
# To Build MLX on macOS
ifeq ($(OS), Darwin)
RESOURCE_MLX := $(RESOURCE_MLX_LINUX)
LIBMLX_DIR = $(LIBMLX_LINUX_DIR)
LIBMLX = $(LIBMLX_DIR)/libmlx_Darwin.a
endif
# To Build MLX on Linux
ifeq ($(OS), Linux)
RESOURCE_MLX := $(RESOURCE_MLX_LINUX)
LIBMLX_DIR = $(LIBMLX_LINUX_DIR)
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a
endif
LIBS = $(LIBMLX) $(LIBFT) $(LIBFTPRINTF) $(LIBDEBUG)

NAME := start submodules $(LIBMLX)

# Default target
all: $(NAME)
	make -C $(LIBFT_DIR)
	make -C $(LIBFTPRINTF_DIR)
	make -C $(LIBDEBUG_DIR)
.PHONY: all

PROJECT_DIR = $(notdir $(CURDIR))
start:
	@echo "${YELLOW}Starting build process for '${PROJECT_DIR}'...${NC}"
.PHONY: start

end:
	@echo "${YELLOW}Build process completed for '${LIBS}'.${NC}"
.PHONY: end

# Build MiniLibX
$(LIBMLX):
	make extract_mlx
	make install_dependencies
	@echo "${YELLOW}Starting build process for '${LIBMLX_DIR}'...${NC}"
	make -C $(LIBMLX_DIR)
	@echo "${GREEN}Successfully created archive: $@${NC}"

# Extract from resource (minilibx-linux.tgz minilibx_opengl.tgz)
extract_mlx:
	@./extract_mlx.sh $(RESOURCE_MLX)
.PHONY: extract_mlx

# Check dependencies installed
install_dependencies:
	@./install_dependency.sh
.PHONY: install_dependencies

# Update submodules
SUBMODULE_DIR := $(LIBFT_DIR)
submodules:
	@command -v git >/dev/null 2>&1 \
		|| { echo >&2 "git is not installed. Aborting."; exit 1; }
	@./initialize_submodules.sh
.PHONY: submodules

## Clean target
clean:
	@echo "${RED}Cleaning object files of Libraries...${NC}"
	make -C $(LIBFT_DIR) clean
	make -C $(LIBFTPRINTF_DIR) clean
	make -C $(LIBMLX_DIR) clean
	make -C $(LIBDEBUG_DIR) clean
.PHONY: clean

# Clean and remove library target
fclean: clean
	@echo "${RED}Removing archive file...${NC}"
	rm -f $(LIBFT) $(LIBFTPRINTF) $(LIBDEBUG)
	@echo "${GREEN}All archive file removed.${NC}"
.PHONY: fclean

## Rebuild target
re: fclean all
.PHONY: re

# Color Definitions
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color
