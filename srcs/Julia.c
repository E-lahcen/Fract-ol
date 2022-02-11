/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:52 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/11 17:26:33 by lelhlami         ###   ########.fr       */
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
	return (mlx->it * 10);
}

t_complex    julia_orient(t_display *mlx, int par)
{
    t_complex c;

    if (!par)
		c = (t_complex) {.real = -0.4, .imag = 0.6 };
    else if (par == 1)
		c = (t_complex) {.real = -0.8, .imag = 0.156 };
	else if (par == 2)
		c = (t_complex) {.real = -0.7269, .imag = 0.1889 };
	else if (par == 3)
		c = (t_complex) {.real = -0.203333, .imag = -0.696667 };
	else if (par == 4)
		c = (t_complex) {.real = 0.0, .imag = -0.8 };
	else if (par == 5)
		c = (t_complex) {.real = 0.371504, .imag = -0.153893 };
	else
		c = (t_complex) {.real = mlx->xcord, .imag = mlx->ycord };
    return (c);
}

void	lighting_pixels_julia(t_display *mlx)
{
	int			start_x;
	int			start_y;
	t_complex	c;

	c = julia_orient(mlx, mlx->julia_static);
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
