/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:35:36 by druina            #+#    #+#             */
/*   Updated: 2023/03/28 08:59:31 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/src/libft.h"
# include "mlx.h"
# include <fcntl.h>
# define ESC_MAC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define SHOOT 49

typedef enum bool
{
	false = 3,
	true = 4
}				bool;

typedef struct map_check
{
	int			empty_space;
	int			collectible;
	int			exit;
	int			player;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;

}				t_map_check;

typedef struct player
{
	int			y;
	int			x;
	int			exit_y;
	int			exit_x;
	int			collect;
	int			pixel_player_y;
	int			pixel_player_x;
	void		*player_image;
	void		*exit_image;
	void		*tile_image;
	void		*exit_granted;
	int			pixel_exit_y;
	int			pixel_exit_x;
}				t_player;

typedef struct program
{
	void		*mlx;
	void		*win;
	int			height;
	int			lenght;
	char		*map;
	int			**map_2d;
	int			width;
	int			elevation;
	int			row_len;
	int			rows;
	t_player	player;
}				t_program;

int				main(int argc, char **argv);
int				check_map_content(char *map);
int				first_and_last_row(char *line);
int				map_rows(char *map);
int				check_surrounding_wall(char *line);
int				check_rows_lenght(char *map, int flag);
void			check_P_E_X(int *player, int *exit, int *collectible,
					char *line);
t_map_check		map_check_init(void);
int				free_close_exit(int fd, char *line, int flag);
int				check_valid_path(char *map, int rows, char *item, int amount);
void			check_P_E_locations(int *location_x, int *location_y,
					char *map_lines[], char *letter);
bool			check_path_recursion(char *map_lines[], int rows, int lenght,
					int amount);
bool			is_a_path(char *map_lines[], int i, int j,
					int *visited_block[]);
bool			check_boundaries(char *map_lines[], int i, int j);
void			free_arrays(char *array[], int *array_int[], int rows);
int				so_long(int x, int y, char *map);
char			*join_and_free_item_and_amount(char *item, int amount,
					char *line);
int				**read_map_to_nbr(char *map);
void			free_program(t_program *program);
void			draw_map_bigger_than_screen(t_program *program, int width,
					int height);

#endif
