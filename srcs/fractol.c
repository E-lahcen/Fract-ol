/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:27:23 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/13 11:50:24 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	destroy(t_display *mlx)
{
	mlx_destroy_image(mlx->img.init, mlx->img.img);
	mlx_destroy_window(mlx->img.init, mlx->img.win);
	exit(0);
}

void	common_init(t_display *mlx)
{
	init_values(mlx);
	mlx->img.init = mlx_init();
	mlx->img.win = mlx_new_window(mlx->img.init, WIDTH, HEIGHT, "Fract'ol");
	mlx->img.img = mlx_new_image(mlx->img.init, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, \
	&mlx->img.bpp, &mlx->img.line_len, &mlx->img.endian);
	set_color_array(mlx);
	mlx_hook(mlx->img.win, 2, 1L << 0, key_event, mlx);
	mlx_hook(mlx->img.win, 4, 1L << 2, mouse_event, mlx);
	mlx_hook(mlx->img.win, 17, 0L, destroy, mlx);
}

void	mandelbrot(t_display *mlx)
{
	common_init(mlx);
	mlx->fract = 1;
	hundle_no_event(mlx);
	mlx_loop(mlx->img.init);
}

void	julia(t_display *mlx, int par)
{
	mlx->julia_static = par;
	common_init(mlx);
	mlx_hook(mlx->img.win, 6, 1L << 0, &mouse_cord, mlx);
	mlx->fract = 2;
	hundle_no_event(mlx);
	mlx_loop(mlx->img.init);
}

void	tricorn(t_display *mlx)
{
	common_init(mlx);
	mlx->fract = 4;
	hundle_no_event(mlx);
	mlx_loop(mlx->img.init);
}
