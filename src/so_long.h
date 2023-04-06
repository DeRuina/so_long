/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:35:36 by druina            #+#    #+#             */
/*   Updated: 2023/04/06 08:34:20 by druina           ###   ########.fr       */
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
}				t_bool;

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
	int			up_down;
	int			left_right;
	int			up;
	int			down;
	int			right;
	int			left;
	int			pixel_player_y;
	int			pixel_player_x;
	void		*player_image;
	void		*grass;
	void		*tree;
	void		*player_right;
	void		*player_left;
	void		*player_up;
	void		*player_down;
	void		*exit_image;
	void		*tile_image;
	void		*water_image;
	void		*exit_granted;
	void		*enemy;
	void		*fire_up;
	void		*fire_down;
	void		*fire_right;
	void		*fire_left;
	void		*poop;
	int			pixel_exit_y;
	int			pixel_exit_x;
	int			**collect_array;
	void		*game_over;
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
	void		***map_print;
	int			**visited_block;
	int			dir;
	int			count;
	int			flag;
	t_player	player;
}				t_program;

int				main(int argc, char **argv);
int				check_map_content(char *map);
int				first_and_last_row(char *line);
int				map_rows(char *map);
int				check_surrounding_wall(char *line);
int				check_rows_lenght(char *map, int flag);
void			check_p_e_x(int *player, int *exit, int *collectible,
					char *line);
t_map_check		map_check_init(void);
int				free_close_exit(int fd, char *line, int flag);
int				check_valid_path(char *map, int rows, char *item, int amount);
void			check_p_e_locations(int *location_x, int *location_y,
					char *map_lines[], char *letter);
t_bool			check_path_recursion(char *map_lines[], int rows, int lenght,
					int amount);
t_bool			is_a_path(char *map_lines[], int i, int j,
					int *visited_block[]);
t_bool			check_boundaries(char *map_lines[], int i, int j);
void			free_arrays(char *array[], int *array_int[], int rows,
					int *flag);
int				so_long(int x, int y, char *map);
char			*join_and_free_item_and_amount(char *item, int amount,
					char *line);
int				**read_map_to_nbr(char *map);
void			free_program(t_program *program);
void			***draw_map(t_program *program, int width, int height);
void			print_map(t_program *program, void ***map_tiles, int i, int l);
void			draw_base(t_program *program, int width, int height);
void			***map_tiles_array(t_program *program, int width, int height);
void			enemy_movement(t_program **program, int y, int x);
int				assign(t_map_check *check, char *map, int *fd,
					int *map_rows_count);
int				check_quanity_and_path(int fd, char *map, int map_rows_count,
					t_map_check *check);
t_bool			visiting_blocks(char *map_lines[], int i, int j,
					int *visited_block[]);
int				**calloc_array(int rows, int lenght);

#endif
