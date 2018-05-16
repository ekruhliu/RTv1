# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 10:02:22 by ekruhliu          #+#    #+#              #
#    Updated: 2018/04/26 10:02:23 by ekruhliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

FLAGS = -c -Wall -Wextra -Werror -O3

SDL = -rpath @loader_path/libSDL/ -I libSDL/SDL2.framework/Headers -I libSDL/SDL2_image.framework/Headers -lm -framework SDL2 -framework SDL2_image -F ./libSDL

HEADER = ./rtv1.h

LIBFT = libft/libft.a

SRCS = ./srcs/initialization.c ./srcs/cleaner.c ./srcs/render.c ./srcs/main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ make -C libft/
		@ gcc -o $(NAME) $(OBJ) $(LIBFT) $(SDL)
		@ echo "\033[1m\033[32mCompile!\033[0m"

%.o: %.c $(HEADER)
		@ gcc $(FLAGS) -o  $@ $<

clean:
		@ /bin/rm -f $(OBJ)
		@ make -C libft/ clean
		@ echo "\033[1m\033[31mAll the object files have been deleted.\033[0m"

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean
		@ echo "\033[1m\033[31m$(NAME) has been deleted.\033[0m"

re: fclean all
