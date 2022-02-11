/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:52 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/10 11:01:13 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_iteration_julia(t_complex c, int x, int y, t_display *mlx)
{
	t_complex	result;
	t_complex	z;

	mlx->it = 0;
	z.real = ((x * mlx->xscale) - mlx->zoom_x);
	z.imag = ((y * mlx->yscale) - mlx->zoom_y);
	while (((z.real * z.real) + (z.imag * z.imag) < 4) && mlx->it < mlx->max_it)
	{
		result.real = ((z.real * z.real) - (z.imag * z.imag)) + c.real;
		result.imag = (2 * z.imag * z.real) + c.imag;
		z = result;
		mlx->it++;
	}
	return (mlx->it);
}

void	lighting_pixels_julia(t_display *mlx)
{
	int			start_x;
	int			start_y;
	t_complex	c;

	c.real = mlx->xcord;
	c.imag = mlx->ycord;
	start_y = 0;
	while (start_y < HEIGHT)
	{
		start_x = 0;
		while (start_x < WIDTH)
		{
			mlx->it = ft_iteration_julia(c, start_x, start_y, mlx);
			pixels_image(mlx, start_x, start_y, coloring_pixels(mlx));
			coloring_pixels(mlx);
			start_x++;
		}
		start_y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img->img, 0, 0);
	mlx_string_put(mlx->init, mlx->win, 5, 0, 0xffffff, "Press space for help");
	mlx_string_put(mlx->init, mlx->win, 5, 20, 0xffffff, "Left click to fix julia");
	if (mlx->help)
		ft_help(mlx);
}
