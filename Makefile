# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngonzo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 15:52:50 by ngonzo            #+#    #+#              #
#    Updated: 2020/11/01 15:52:52 by ngonzo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
FLG = -Wall -Werror -Wextra
SRC = ft_strlen.s ft_write.s ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s
OBJ = $(SRC:%.s=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	nasm -f macho64 $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) test _test.txt

re: fclean all

test: $(NAME)
	gcc $(FLG) -L. -lasm -o test main.c
	./test < Makefile

.PHONY: all clean fclean re test