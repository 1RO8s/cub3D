# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 14:39:52 by kamitsui          #+#    #+#              #
#    Updated: 2024/12/20 17:30:37 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SRCS_DIR = srcs \
		  srcs/process_utils \
		  srcs/conversion_utils \
		  srcs/conversion_utils/unsigned_arg \
		  srcs/conversion_utils/signed_arg \
		  srcs/formalize_utils
OBJ_DIR = objs
INC_DIR = includes
DEP_DIR = .deps
LIBFT_DIR = ../libft
PROJECT_DIR = $(notdir $(CURDIR))

# Source files
SRCS = \
	   ft_printf.c \
	   initialize.c \
	   process.c \
	   conversion.c \
	   join_to_out.c \
	   \
	   letter.c \
	   flag.c \
	   field.c \
	   width.c \
	   precision.c \
	   get_field_nbr.c \
	   prefix.c \
	   type.c \
	   error.c \
	   add_to_buff.c \
	   \
	   decimal.c \
	   unsign_decimal.c \
	   octal.c \
	   hexadecimal.c \
	   pointer.c \
	   character.c \
	   string.c \
	   percent.c \
	   itoa_buff.c \
	   \
	   unsign_va_arg.c \
	   unsign_hh.c \
	   unsign_ll.c \
	   unsign_h.c \
	   unsign_l.c \
	   unsign_int.c \
	   \
	   sign_va_arg.c \
	   sign_hh.c \
	   sign_ll.c \
	   sign_h.c \
	   sign_l.c \
	   sign_int.c \
	   \
	   formalize.c \
	   adjust.c \
	   adjust_width.c \
	   adjust_prec.c \
	   adjust_number.c \
	   adjust_string.c \
	   adjust_sign.c \
	   adjust_hash.c \
	   pad_str.c \
	   pad_n_str.c \
	   pad_width.c \
	   pad_prec.c \
	   sequence_unsigned.c \
	   sequence_signed.c

# Object files and dependency files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Library name
NAME = libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
CF_ASAN = -g -fsanitize=address
CF_THSAN = -g -fsanitize=thread
CF_GENERATE_DEBUG_INFO = -g
CF_INC = -I$(INC_DIR)
CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) $(CF_INC) $(CF_DEP) -c $< -o $@

$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: start $(NAME) end
.PHONY: all

start:
	@echo "${YELLOW}Starting build process for '${PROJECT_DIR}'...${NC}"

end:
	@echo "${YELLOW}Build process completed.${NC}"

# Library target
$(NAME): $(LIBFT) $(DEPS) $(OBJS)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)
	@echo "${GREEN}Successfully created archive: $@${NC}"

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "Error: LIBFT_DIR directory does not exist."; \
		exit 1; \
	fi
	make -C $(LIBFT_DIR)

bonus: $(NAME)
.PHONY: bonus

# Address sanitizer mode make rule
asan: fclean
	make WITH_ASAN=1
.PHONY: asan

# Thread sanitizer mode make rule
thsan: fclean
	make WITH_THSAN=1
.PHONY: thsan

# Leak check
check: fclean
	make WITH_G_INFO=1
.PHONY: check

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

# Generate debug infomation for Enabel valgrind or leaks tool
ifdef WITH_G_INFO
CFLAGS += $(CF_GENERATE_DEBUG_INFO)
endif

# Color Definitions
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color
