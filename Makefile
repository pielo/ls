# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/30 11:54:21 by mlanglet          #+#    #+#              #
#    Updated: 2014/02/09 19:03:07 by mlanglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_ls.a

SRC = ft_list_dir.c \
	  ft_aff_lst.c \
	  ft_add_lst.c \
	  ft_remp_one.c \

SRCLIB = ft_atoi.c \
		 ft_bzero.c \
		 ft_isalnum.c \
		 ft_isalpha.c \
		 ft_isascii.c \
		 ft_isdigit.c \
		 ft_isprint.c \
		 ft_itoa.c \
		 ft_memalloc.c \
		 ft_memccpy.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_memcpy.c \
		 ft_memdel.c \
		 ft_memmove.c \
		 ft_memset.c \
		 ft_putchar.c \
		 ft_putchar_fd.c \
		 ft_putendl.c \
		 ft_putendl_fd.c \
		 ft_putnbr.c \
		 ft_putnbr_fd.c \
		 ft_putstr.c \
		 ft_putstr_fd.c \
		 ft_strcat.c \
		 ft_strchr.c \
		 ft_strclr.c \
		 ft_strcmp.c \
		 ft_strcpy.c \
		 ft_strdel.c \
		 ft_strdup.c \
		 ft_strequ.c \
		 ft_striter.c \
		 ft_striteri.c \
		 ft_strjoin.c \
		 ft_strlcat.c \
		 ft_strlen.c \
		 ft_strmap.c \
		 ft_strmapi.c \
		 ft_strncat.c \
		 ft_strncmp.c \
		 ft_strncpy.c \
		 ft_strnequ.c \
		 ft_strnew.c \
		 ft_strnstr.c \
		 ft_strtrim.c \
		 ft_strrchr.c \
		 ft_strsplit.c \
		 ft_strstr.c \
		 ft_strsub.c \
		 ft_tolower.c \
		 ft_toupper.c \
		 ft_lstnew.c \
		 ft_lstdelone.c \
		 ft_lstdel.c \
		 ft_lstadd.c \
		 ft_lstiter.c \
		 ft_lstmap.c \
		 get_next_line.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I. -I./libft/includes/

RM = /bin/rm -f

MAKE = make

all: $(NAME)

%.o: %.c
	@ (gcc -c -o $@ $^ $(CFLAGS))

$(NAME): $(OBJ)
	@ $(MAKE) -C libft
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

comp:
	gcc $(CFLAGS) $(SRC) test.c $(SRCLIB)

clean:
	@ $(MAKE) clean -C libft
	@ $(RM) $(OBJ)

fclean: clean
	@ $(MAKE) fclean -C libft
	@ $(RM) $(NAME)

re: fclean all
