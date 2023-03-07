# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druina <druina@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 09:33:07 by druina            #+#    #+#              #
#    Updated: 2023/03/07 11:16:31 by druina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

HEADERS = -I ./src/so_long.h -I libft/src/libft.h -I mlx/include

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MANPATH)
	@cd libft && make
	@cd libft && mv libft.a ..
	@make -C MLX42
	@cd MLX42 && mv libmlx42.a ..
	@cc $(FLAGS) -o $(NAME) $(MANPATH) libft.a libmlx42.a $(HEADERS) -g

clean:
	@cd libft && make clean
	@cd MLX42 && make clean
	@rm -f libft.a
	@rm -f libmlx42.a


fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean
	@cd MLX42 && make fclean



re: fclean all

