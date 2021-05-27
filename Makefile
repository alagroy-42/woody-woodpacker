# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 13:46:17 by alagroy-          #+#    #+#              #
#    Updated: 2021/05/27 15:30:12 by alagroy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = woody_woodpacker

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
CFLAGS += $(addprefix -I , $(INCLUDES))
NASM = nasm -f elf64

INCLUDES_DIR = ./includes/
LIB_DIR = ./libft/
SRCS_DIR = ./srcs/
INCLUDES = $(INCLUDES_DIR) $(LIB_DIR)includes/
OBJS_DIR = ./.objs/
LIBFT = $(LIB_DIR)libft.a

SRC_FILES = main.c check_file.c error.c endian.c sections.c encryption.c decryption.c \
			segment.c injection.c
ASM_FILES = encrypt.s
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES += $(ASM_FILES:.s=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
HEADERS = $(INCLUDES_DIR)woody.h

all: $(OBJS_DIR) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L $(LIB_DIR) -lft 
	printf "\n\033[0;32m[$(NAME)] Linking [OK]\n\033[0;0m"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<
	printf "\033[0;32m[$(NAME)] Compilation [$<]                 \r\033[0m"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.s $(HEADERS) Makefile
	$(NASM) -o $@ $<
	printf "\033[0;32m[$(NAME)] Compilation [$<]                 \r\033[0m"

$(LIBFT):
	make -C $(LIB_DIR)

$(OBJS_DIR):
	mkdir -p $@

clean:
	$(RM) -Rf $(OBJS_DIR)
	make -C $(LIB_DIR) $@
	printf "\033[0;31m[$(NAME)] Clean [OK]\n"

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_DIR) $@
	printf "\033[0;31m[$(NAME)] Fclean [OK]\n"

re: fclean all

.PHONY: clean re fclean all
.SILENT: