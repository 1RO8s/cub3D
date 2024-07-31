# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 06:07:51 by kamitsui          #+#    #+#              #
#    Updated: 2024/08/01 06:44:33 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SRCS_DIR = ./srcs \
		   ./srcs/initialize \
		   ./srcs/render \
		   ./srcs/my_mlx_utils \
		   ./srcs/xxx \
		   ./srcs/yyy \
		   ./srcs/zzz
OBJ_DIR = objs
INC_DIR = includes
DEP_DIR = .deps
LIB_DIR = lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBFTPRINTF_DIR = $(LIB_DIR)/ft_printf
LIBMLX_DIR = $(LIB_DIR)/libmlx

# Source files
SRCS = \
	   main.c \
	   draw.c \
	   draw_line.c \
	   my_mlx.c \
	   read_map.c \
	   set_points.c \
	   error.c \
	   init.c


# Object files and dependency files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Library name
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
LIBMLX = $(LIBMLX_DIR)/libmlx.a
LIBS = $(LIBFT) $(LIBMLX)

# Build target
NAME = $(notdir $(CURDIR))

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
CF_ASAN = -g -fsanitize=address
#CF_THSAN = -g -fsanitize=thread
CF_GENERATE_DEBUG_INFO = -g
CF_INC = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIBFTPRINTF)/includes \
	 -I$(LIBMLX_DIR)/includes
CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)
# macOS
CF_FRAMEWORK = -framework OpenGL -framework AppKit

# Makefile Option
MAKEFLAGS += --no-print-directory

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) $(CF_INC) $(CF_DEP) -c $< -o $@

$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: start build_lib $(NAME) end display_art
.PHONY: all

start:
	@echo "${YELLOW}Starting build process for '${NAME}'...${NC}"
.PHONY: start

build_lib:
	make -C $(LIB_DIR)
.PHONY: build_lib

end:
	@echo "${YELLOW}Build process completed.${NC}"
.PHONY: end

display_art:
	$(ASCII_ART)
.PHONY: display_art

# Target
$(NAME): $(LIBS) $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) $(CF_FRAMEWORK) $(OBJS) $(LIBS) -o $(NAME)
	@echo "${GREEN}Successfully created execute: $@${NC}"

# Address sanitizer mode make rule
asan: fclean
	make WITH_ASAN=1
.PHONY: asan

# Thread sanitizer mode make rule
#thsan: fclean
#	make WITH_THSAN=1
#.PHONY: thsan

# Leak check
check: fclean
	make WITH_VAL=1
	$(VALGRIND_USAGE)
.PHONY: leak

# Clean target
clean:
	@echo "${RED}Cleaning object files of '${NAME}'...${NC}"
	rm -rf $(OBJ_DIR) $(DEP_DIR)
	make -C $(LIBDEBUG_DIR) clean
.PHONY: clean

# Clean and remove library target
fclean: clean
	@echo "${RED}Removing archive file...${NC}"
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
ifdef WITH_VAL
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
@echo "<  first argment  : a map format                  >"
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
@echo "<  valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/*.cub      >"
@echo "---------------------------------------------------------------------------"
endef
