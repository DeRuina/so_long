/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/03/09 16:03:41 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct  s_program
	{
    	void *mlx;
   		void *win;
		t_img img;
	}               t_program;

void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int key_handler(int key, t_program *temp)
{
	int i;



	i = 100;
	if (key == 124)
	{
	 while (i-- != 0)
		img_pix_put(&temp->img, i, 100, 0x2E9E2A);
	}
	if (key == 125)
	{
	while (i++ != 200)
		img_pix_put(&temp->img, 50, i, 0x2E9E2A);
	}
	return (0);
}

int mouse_handler(int key, void *param)
{


	param = NULL;
	if (key == 1)
		ft_printf("BOOM\n");
	if (key == 2)
		ft_printf("CHAKALAK\n");
	return(0);
}

int mouse_movement_handler(int x, int y, t_program *temp)
{

	img_pix_put(&temp->img, x, y, 0xE8F70E);
	ft_printf("location is %d.%d\n", x, y);
	return(0);
}

void	render_background(t_img *img, int color)
	{
	int	i;
	int	j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
			img_pix_put(img, j++, i, color);
		++i;
	}
	}

t_img create_image(t_program *program)
{
	t_img image;

	image->mlx_img = mlx_new_image(program->mlx, 1000, 1000);
	image->addr = mlx_get_data_addr(image->addr, &image->bpp, &image->line_len, &image->endian);
	return (image);
}

int render(t_program *program)
{
	if (program->win == NULL)
		return (1);
	program->img = create_image(program);
	render_background(&program->img, 0x3B18EC);
	mlx_put_image_to_window(program->mlx, program->win, program->img.mlx_img, 0, 0);
	// mlx_destroy_image(program->mlx, program->img.mlx_img);
	// program->img = create_image(program);
	// render_background(&program->img, 0xE8F70E);
	// mlx_put_image_to_window(program->mlx, program->win, program->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{

	t_program program;


	program.mlx  = mlx_init();
	program.win = mlx_new_window(program.mlx, 1000, 1000, "so long");
	// program.img.mlx_img = mlx_new_image(program.mlx, 1000, 1000);
	// program.img.addr = mlx_get_data_addr(program.img.mlx_img, &program.img.bpp, &program.img.line_len, &program.img.endian);

	// mlx_key_hook(program.win, &key_handler, &program);
	mlx_mouse_hook(program.win, &mouse_handler, &program);
	// mlx_hook(program.win, 6, 1L<<6, mouse_movement_handler, &program);
	mlx_loop_hook(program.mlx, &render, &program);
	mlx_loop(program.mlx);
	return (0);
}
