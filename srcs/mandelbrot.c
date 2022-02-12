/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:27:34 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/12 20:31:03 by lelhlami         ###   ########.fr       */
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
	return (mlx->it);
}

int	lighting_pixels_man(t_display *mlx)
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
	mlx_put_image_to_window(mlx->img.init, mlx->img.win, mlx->img.img, 0, 0);
	mlx_string_put(mlx->img.init, mlx->img.win, 5, 0, 0xffffff, "Press space for help");
	if (mlx->help)
		ft_help(mlx);
	return (0);
}

void ft_help(t_display *mlx)
{
	mlx_clear_window(mlx->img.init, mlx->img.win);
	mlx_string_put(mlx->img.init, mlx->img.win, 220, 200, 0xFFFF00, "---------- Fract'ol !! ---------");
	mlx_string_put(mlx->img.init, mlx->img.win, 200, 250, 0xffffff, "Use the mouse wheel to zoom in & out");
	mlx_string_put(mlx->img.init, mlx->img.win, 200, 300, 0xffffff, "Hey you can change the color");
	mlx_string_put(mlx->img.init, mlx->img.win, 200, 350, 0xffffff, "		Change Red with r/t");
	mlx_string_put(mlx->img.init, mlx->img.win, 200, 400, 0xffffff, "		Change Green with g/h");
	mlx_string_put(mlx->img.init, mlx->img.win, 200, 450, 0xffffff, "		Change Blue with b/n");
	mlx_string_put(mlx->img.init, mlx->img.win, 200, 500, 0xffffff, "Use the arrows to move the image ");
	mlx_string_put(mlx->img.init, mlx->img.win, 200, 550, 0xffffff, "Close help by pressing the space bar");
	mlx_string_put(mlx->img.init, mlx->img.win, 220, 600, 0xFFFF00, "----------- Fract'ol !! ---------");
}
