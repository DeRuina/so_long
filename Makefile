# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druina <druina@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 09:33:07 by druina            #+#    #+#              #
#    Updated: 2023/04/06 09:25:21 by druina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c main.c check_map_content.c valid_path.c check_map_utils.c valid_path_utils.c so_long_utils.c

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit

HEADER = -I ./src/so_long.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MANPATH)
	@make -C Libft
	@cd Libft && mv libft.a ..
	@cc $(FLAGS) -o $(NAME) $(MANPATH) -lmlx $(MLXFLAGS) libft.a $(HEADERS)

clean:
	@cd Libft && make clean
	@rm -f libft.a
	@rm -f libmlx.a


fclean: clean
	@rm -f $(NAME)
	@cd Libft && make fclean



re: fclean all

