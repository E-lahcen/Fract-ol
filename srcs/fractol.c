/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:27:23 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/12 14:56:27 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	destroy(t_display *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	free(mlx->color);
	free(mlx->img);
	free(mlx);
	exit(0);
}

void	mandelbrot(t_display *mlx)
{
	mlx = mlx_initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
	&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx_hook(mlx->win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 1;
	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
	mlx_loop(mlx->init);
}

void	julia(t_display *mlx, int par)
{
	mlx = mlx_initialization();
	mlx->julia_static = par;
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
	&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx_hook(mlx->win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->win, 6, KeyPressMask, &mouse_cord, mlx);
	mlx_hook(mlx->win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 2;
	par += 10;
	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
	mlx_loop(mlx->init);
}

// void	julia(t_display *mlx)
// {
// 	mlx = mlx_initialization();
// 	mlx->init = mlx_init();
// 	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fract'ol");
// 	mlx->img->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
// 	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
// 	&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
// 	mlx_hook(mlx->win, 2, KeyPressMask, &key_event, mlx);
// 	mlx_hook(mlx->win, 4, ButtonPressMask, &mouse_event, mlx);
// 	mlx_hook(mlx->win, 6, KeyPressMask, &mouse_cord, mlx);
// 	mlx_hook(mlx->win, 17, NoEventMask, &destroy, NULL);
// 	mlx->fract = 2;
// 	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
// 	mlx_loop(mlx->init);
// }

void	fern(t_display *mlx)
{
	mlx = mlx_initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
	&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx_hook(mlx->win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 3;
	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
	mlx_loop(mlx->init);
}

void	tricorn(t_display *mlx)
{
	mlx = mlx_initialization();
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
	&mlx->img->bpp, &mlx->img->line_len, &mlx->img->endian);
	mlx_hook(mlx->win, 2, KeyPressMask, &key_event, mlx);
	mlx_hook(mlx->win, 4, ButtonPressMask, &mouse_event, mlx);
	mlx_hook(mlx->win, 17, NoEventMask, &destroy, mlx);
	mlx->fract = 4;
	mlx_loop_hook(mlx->init, &hundle_no_event, mlx);
	mlx_loop(mlx->init);
}
