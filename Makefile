# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druina <druina@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 09:33:07 by druina            #+#    #+#              #
#    Updated: 2023/03/07 14:33:26 by druina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -framework AppKit

HEADER = -I ./src/so_long.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MANPATH)
	@make -C Libft
	@cd Libft && mv libft.a ..
	@cc $(FLAGS) -o $(NAME) $(MANPATH) $(MLXFLAGS) -lmlx libft.a $(HEADERS) -g

clean:
	@cd Libft && make clean
	@rm -f libft.a
	@rm -f libmlx.a


fclean: clean
	@rm -f $(NAME)
	@cd Libft && make fclean



re: fclean all

