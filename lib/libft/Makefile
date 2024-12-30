# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:14:33 by kamitsui          #+#    #+#              #
#    Updated: 2024/12/18 03:29:50 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Build target
NAME = libft.a

# Directories
PROJECT_DIR = $(notdir $(CURDIR))
OBJ_DIR = objs
DEP_DIR = .deps

# Source files
SRCS = \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   \
	   ft_calloc.c \
	   ft_strdup.c \
	   \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   \
	   ft_isupper.c \
	   ft_islower.c \
	   ft_strncat.c \
	   ft_strnlen.c \
	   ft_strtol.c \
	   ft_strndup.c \
	   ft_count_words.c \
	   \
	   ft_isxdigit.c \
	   ft_strjoin_free.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_itoa_binary.c \
	   \
	   ft_strtok.c \
	   \
	   ft_abs.c \
	   \
	   ft_isinteger.c \
	   ft_isint.c \
	   ft_qsort.c \
	   \
	   ft_realloc_tentative.c \
	   \
	   ft_isspace.c \
	   \
	   get_next_line.c

SRCS_B = \
	     ft_lstnew.c \
	     ft_lstadd_front.c \
	     ft_lstsize.c \
	     ft_lstlast.c \
	     ft_lstadd_front.c \
	     ft_lstadd_back.c \
	     ft_lstdelone.c \
	     ft_lstclear.c \
	     ft_lstiter.c \
	     ft_lstmap.c

# Object files and dependency files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))
OBJS_B = $(addprefix $(OBJ_DIR)/, $(SRCS_B:.c=.o))
DEPS_B = $(addprefix $(DEP_DIR)/, $(SRCS_B:.c=.d))

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
CF_ASAN = -g -fsanitize=address
CF_THSAN = -g -fsanitize=thread
CF_GENERATE_DEBUG_INFO = -g
CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) $(CF_DEP) -c $< -o $@

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
	ar -r $@ $(OBJS)
	@echo "${GREEN}Successfully created archive: $@${NC}"

# Bonus mode make rule
bonus:
	make WITH_BONUS=1
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
#re: fclean bonus all
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

# Enabel valgrind tool
ifdef WITH_G_INFO
CFLAGS += $(CF_GENERATE_DEBUG_INFO)
endif

# Color Definitions
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color
