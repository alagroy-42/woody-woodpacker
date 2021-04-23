# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 17:52:36 by alagroy-          #+#    #+#              #
#    Updated: 2021/04/02 13:06:50 by alagroy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

SRCS = ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
	   ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strncpy.c ft_strnstr.c \
	   ft_strrchr.c ft_strstr.c ft_strncat.c ft_atoi.c ft_isalpha.c \
	   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	   ft_tolower.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	   ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	   ft_strsub.c ft_strstrjoin.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	   ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putull.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	   ft_memalloc.c ft_memdel.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstsort.c ft_strrev.c ft_strlowcase.c \
	   ft_strupcase.c ft_strndup.c ft_lstsize.c ft_lstend.c ft_lstmid.c \
	   get_next_line.c aux.c edit_string.c fill_content.c flags.c ft_printf.c \
	   itoa.c precision_min_size.c tools.c ft_2dstrdel.c ft_print_2da.c \
	   ft_str2ddel.c ft_strreplace.c ft_print_strlist.c ft_expend_2dstr.c \
	   ft_2dstrlen.c ft_2dstrjoin.c ft_strichr.c ft_strirchr.c gnl_nl.c \
	   vct_create.c vct_destroy.c vct_strdup.c vct_print.c vct_cat.c vct_realloc.c \
	   vct_vctdup.c vct_insertstr.c vct_strcpy.c vct_sub.c vct_delpart.c \
	   vct_replace.c vct_strstr.c vct_cmp.c vct_gnl.c vct_append.c vct_chr.c \
	   vct_split.c vct_rev.c vct_push.c vct_apply.c vct_gnc.c

OBJ = $(patsubst %.c, $(OBJ_PATH)%.o, $(SRCS))

vpath %.c srcs/vector/
vpath %.c srcs/2dstr/
vpath %.c srcs/str/
vpath %.c srcs/mem/
vpath %.c srcs/print/
vpath %.c srcs/lst/
vpath %.c srcs/gnl/
vpath %.c srcs/printf/

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

INCLUDES = ./includes/
HEADER += $(INCLUDES)libft.h 
HEADER += $(INCLUDES)ft_printf.h 
HEADER += $(INCLUDES)vector.h 


OBJ_PATH = ./.obj/

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
	printf "\n\033[0;32m[libft] Linking [OK]\n"

$(OBJ_PATH):
	mkdir $@

$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@
	printf "\033[0;32m[libft] Compilation [$<]                 \r\033[0m"

clean:
	$(RM) -R $(OBJ_PATH)
	printf "\033[0;31m[libft] Clean [OK]\n"

fclean: clean
	$(RM) $(NAME)
	printf "\033[0;31m[libft] Fclean [OK]\n"

re: fclean all

.PHONY: fclean clean all re
.SILENT:
