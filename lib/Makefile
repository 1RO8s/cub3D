# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 22:03:00 by kamitsui          #+#    #+#              #
#    Updated: 2024/09/01 00:10:09 by kamitsui         ###   ########.fr        #
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

# Default target
all: start submodules $(LIBS) end
.PHONY: all

PROJECT_DIR = $(notdir $(CURDIR))
start:
	@echo "${YELLOW}Starting build process for '${PROJECT_DIR}'...${NC}"
.PHONY: start

end:
	@echo "${YELLOW}Build process completed for '${LIBS}'."
.PHONY: end

# Build MiniLibX
#$(LIBMLX): extract_mlx install_dependencies
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

# Build Libft
$(LIBFT): 
	make -C $(LIBFT_DIR)

# Build ft_printf
$(LIBFTPRINTF): 
	make -C $(LIBFTPRINTF_DIR)

# Build lib
$(LIBDEBUG):
	make -C $(LIBDEBUG_DIR)

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
	rm -f $(NAME)
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

## Build target
#NAME = $(notdir $(CURDIR))
#
## vpath for serching source files in multiple directories
#vpath %.c $(SRCS_DIR)
#
## Compiler
#CC = cc
#CFLAGS = -Wall -Wextra -Werror
#CF_ASAN = -g -fsanitize=address
##CF_THSAN = -g -fsanitize=thread
#CF_GENERATE_DEBUG_INFO = -g
#CF_INC = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBFTPRINTF)/includes \
#	 -I$(LIBMLX_DIR)/includes
#CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)
## macOS
#CF_FRAMEWORK = -framework OpenGL -framework AppKit
#
## Makefile Option
#MAKEFLAGS += --no-print-directory
#
## Rules for building object files
#$(OBJ_DIR)/%.o: %.c
#	@mkdir -p $(OBJ_DIR)
#	@mkdir -p $(DEP_DIR)
#	$(CC) $(CFLAGS) $(CF_INC) $(CF_DEP) -c $< -o $@
#
#$(DEP_DIR)/%.d: %.c
#	@mkdir -p $(DEP_DIR)
#
## Default target
#all: start build_lib $(NAME) end display_art
#.PHONY: all
#
#start:
#	@echo "${YELLOW}Starting build process for '${NAME}'...${NC}"
#.PHONY: start
#
#build_lib:
#	make -C $(LIB_DIR)
#.PHONY: build_lib
#
#end:
#	@echo "${YELLOW}Build process completed.${NC}"
#.PHONY: end
#
#display_art:
#	$(ASCII_ART)
#.PHONY: display_art
#
## Target
#$(NAME): $(LIBS) $(DEPS) $(OBJS)
#	$(CC) $(CFLAGS) $(CF_FRAMEWORK) $(OBJS) $(LIBS) -o $(NAME)
#	@echo "${GREEN}Successfully created execute: $@${NC}"
#
## Address sanitizer mode make rule
#asan: fclean
#	make WITH_ASAN=1
#.PHONY: asan
#
## Thread sanitizer mode make rule
##thsan: fclean
##	make WITH_THSAN=1
##.PHONY: thsan
#
## Leak check
#check: fclean
#	make WITH_VAL=1
#	$(VALGRIND_USAGE)
#.PHONY: leak
#
## Clean target
#clean:
#	@echo "${RED}Cleaning object files of '${NAME}'...${NC}"
#	rm -rf $(OBJ_DIR) $(DEP_DIR)
#	make -C $(LIBDEBUG_DIR) clean
#.PHONY: clean
#
## Clean and remove library target
#fclean: clean
#	@echo "${RED}Removing archive file...${NC}"
#	rm -f $(LIBDEBUG)
#	rm -f $(NAME)
#	@echo "${GREEN}Archive file removed.${NC}"
#.PHONY: fclean
#
## Rebuild target
#re: fclean all
#.PHONY: re
#
## Enable dependency file
#-include $(DEPS)
#
## Enabel Address sanitizer
#ifdef WITH_ASAN
#CFLAGS += $(CF_ASAN)
#endif
#
## Enabel Thread sanitizer
#ifdef WITH_THSAN
#CFLAGS += $(CF_THSAN)
#endif
#
## Enabel valgrind tool
#ifdef WITH_VAL
#CFLAGS += $(CF_GENERATE_DEBUG_INFO)
#endif
#
## Color Definitions
#RED=\033[0;31m
#GREEN=\033[0;32m
#YELLOW=\033[0;33m
#NC=\033[0m # No Color
#
## ASCII Art
#define ASCII_ART
#@echo " _________________________________________________"
#@echo "< Usage : ./cub3D map/*.cub                       >"
#@echo "<  first argment  : a map format                  >"
#@echo "--------------------------------------------------"
#@echo "       \   ^__^"
#@echo "        \  (oo)\_______"
#@echo "           (__)\       )\\/\\"
#@echo "               ||----w |"
#@echo "               ||     ||\n"
#endef
#
## Valgrind Usage
#define VALGRIND_USAGE
#@echo "        /"
#@echo "       /"
#@echo " __________________________________________________________________________"
#@echo "< Vargrind Usage :                                                         >"
#@echo "<  valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/*.cub      >"
#@echo "---------------------------------------------------------------------------"
#endef
