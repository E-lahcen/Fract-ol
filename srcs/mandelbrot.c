/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:27:34 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/11 09:28:50 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_iteration_man(t_complex z, int x, int y, t_display *mlx)
{
	t_complex	result;
	t_complex	c;

	mlx->it = 0;
	c.real = ((x * mlx->xscale) - mlx->zoom_x);
	c.imag = ((y * mlx->yscale) - mlx->zoom_y);
	while (((z.real * z.real) + (z.imag * z.imag) < 4) && mlx->it < mlx->max_it)
	{
		result.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		result.imag = (2 * z.imag * z.real) + c.imag;
		z = result;
		mlx->it++;
	}
	return (mlx->it * 1000);
}

void	lighting_pixels_man(t_display *mlx)
{
	int			x;
	int			y;
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->it = ft_iteration_man(z, x, y, mlx);
			pixels_image(mlx, x, y, coloring_pixels(mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img->img, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 5, 0, 0xffffff, "Press space for help");
	if (mlx->help)
		ft_help(mlx);
}

void ft_help(t_display *mlx)
{
	mlx_clear_window(mlx->init, mlx->win);
	mlx_string_put(mlx->init, mlx->win, 220, 200, 0xFFFF00, "---------- Fract'ol !! ---------");
	mlx_string_put(mlx->init, mlx->win, 200, 250, 0xffffff, "use the mouse wheel to zoom in & out");
	mlx_string_put(mlx->init, mlx->win, 200, 300, 0xffffff, "hey you can change the color");
	mlx_string_put(mlx->init, mlx->win, 200, 350, 0xffffff, "to change the value of Red use r/t");
	mlx_string_put(mlx->init, mlx->win, 200, 400, 0xffffff, "to change the value of Green use g/h");
	mlx_string_put(mlx->init, mlx->win, 200, 450, 0xffffff, "to change the value of Blue use b/n");
	mlx_string_put(mlx->init, mlx->win, 200, 500, 0xffffff, "use the arrows to move the image ");
	mlx_string_put(mlx->init, mlx->win, 200, 550, 0xffffff, "close help by pressing the space bar");
	mlx_string_put(mlx->init, mlx->win, 220, 600, 0xFFFF00, "----------- Fract'ol !! ---------");
}
