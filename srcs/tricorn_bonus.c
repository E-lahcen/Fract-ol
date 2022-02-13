/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:55:03 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/13 11:11:59 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_iteration_tricorn(t_complex z, int x, int y, t_display *mlx)
{
	t_complex	result;
	t_complex	c;

	mlx->it = 0;
	c.real = ((x * mlx->xscale) - mlx->zoom_x);
	c.imag = ((y * mlx->yscale) - mlx->zoom_y);
	while (((z.real * z.real) + (z.imag * z.imag) < 4) && mlx->it < mlx->max_it)
	{
		result.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		result.imag = -1 * (2 * z.imag * z.real) + c.imag;
		z = result;
		mlx->it++;
	}
	return (mlx->it);
}

void	lighting_pixels_tricorn(t_display *mlx)
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
			mlx->it = ft_iteration_tricorn(z, x, y, mlx);
			pixels_image(mlx, x, y, coloring_pixels(mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->img.init, mlx->img.win, mlx->img.img, 0, 0);
	mlx_string_put(mlx->img.init, mlx->img.win, 5, 0, \
		0xffffff, "Press space for help");
	if (mlx->help)
		ft_help(mlx);
}
