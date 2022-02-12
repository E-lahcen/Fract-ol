/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:27:23 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/12 18:52:15 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	destroy(t_display *mlx)
{
	mlx_destroy_image(mlx->img.init, mlx->img.img);
	mlx_destroy_window(mlx->img.init, mlx->img.win);
	exit(0);
}

void	mandelbrot(t_display *mlx)
{
	init_values(mlx);
	mlx->img.init = mlx_init();
	mlx->img.win = mlx_new_window(mlx->img.init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img.img = mlx_new_image(mlx->img.init, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
	&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	mlx_hook(mlx->img.win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->img.win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->img.win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 1;
	// mlx_loop_hook(mlx->img.init, &hundle_no_event, mlx);
	hundle_no_event(mlx);
	mlx_loop(mlx->img.init);
}

void	julia(t_display *mlx, int par)
{
	init_values(mlx);
	mlx->julia_static = par;
	mlx->img.init = mlx_init();
	mlx->img.win = mlx_new_window(mlx->img.init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img.img = mlx_new_image(mlx->img.init, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
	&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	mlx_hook(mlx->img.win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->img.win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->img.win, 6, KeyPressMask, &mouse_cord, mlx);
	mlx_hook(mlx->img.win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 2;
	par += 10;
	mlx_loop_hook(mlx->img.init, &hundle_no_event, mlx);
	mlx_loop(mlx->img.init);
}

void	fern(t_display *mlx)
{
	init_values(mlx);
	mlx->img.init = mlx_init();
	mlx->img.win = mlx_new_window(mlx->img.init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img.img = mlx_new_image(mlx->img.init, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
	&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	mlx_hook(mlx->img.win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->img.win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->img.win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 3;
	mlx_loop_hook(mlx->img.init, &hundle_no_event, mlx);
	mlx_loop(mlx->img.init);
}

void	tricorn(t_display *mlx)
{
	init_values(mlx);
	mlx->img.init = mlx_init();
	mlx->img.win = mlx_new_window(mlx->img.init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img.img = mlx_new_image(mlx->img.init, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
	&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	mlx_hook(mlx->img.win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->img.win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->img.win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 4;
	mlx_loop_hook(mlx->img.init, &hundle_no_event, mlx);
	mlx_loop(mlx->img.init);
}
