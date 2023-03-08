/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/03/08 10:11:35 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct  s_program
	{
    	void *mlx;
   		 void *win;
	}               t_program;

int key_handler(int key, void *param)
{
	int i;
	t_program *temp;

	temp = param;


	i = 100;
	if (key == 124)
	{
	 while (i-- != 0)
		mlx_pixel_put(temp->mlx, temp->win, i, 100, 0x2E9E2A);
	}
	if (key == 125)
	{
	while (i++ != 200)
		mlx_pixel_put(temp->mlx, temp->win, 50, i, 0x2E9E2A);
	}
	return (0);
}

int	main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	// int i;

	// i = 100;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "so long");
	// while (i-- != 0)
	t_program program;
	program.mlx = mlx_ptr;
	program.win = win_ptr;
	// 	mlx_pixel_put(mlx_ptr, win_ptr, i, 100, 0x2E9E2A);
	// i = 100;
	// while (i++ != 200)
	// 	mlx_pixel_put(mlx_ptr, win_ptr, 50, i, 0x2E9E2A);
	// mlx_pixel_put(mlx_ptr, win_ptr, 1, 1, 0xffffff);
	// mlx_pixel_put(mlx_ptr, win_ptr, 101, 100, 0xffffff);
	// mlx_pixel_put(mlx_ptr, win_ptr, 100, 101, 0xffffff);
	mlx_string_put(mlx_ptr, win_ptr, 20, 20, 0xF22727, "hello");
	mlx_key_hook(win_ptr, &key_handler, &program);
	mlx_loop(mlx_ptr);
	return (0);
}
