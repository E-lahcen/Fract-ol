/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:13 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/10 17:55:58 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_iteration_fern(t_complex *c, t_display *mlx)
{
	float 		rng;
	t_complex	d;

	rng =((float)rand()) / RAND_MAX;
	mlx->it = 0;
	while (++mlx->it < mlx->max_it * 100)
	{
		rng = ((float)rand()) / RAND_MAX;
		if (rng <= 0.01f)
		{
			c->real = 0;
			c->imag = 0.16f * c->imag;
		}
		else if (rng <= 0.06f)
		{
			c->real = -0.15f * c->real + 0.28f * c->imag;
			c->imag = 0.26f * c->real + 0.24f * c->imag + 0.44f;
		}
		else if (rng <= 0.15f)
		{
			c->real = 0.2f * c->real + -0.26f * c->imag;
			c->imag = 0.23f * c->real + 0.22f * c->imag + 1.6f;
		}
		else
		{
			c->real = 0.85f * c->real + 0.04f * c->imag;
			c->imag = -0.04f * c->real + 0.85f * c->imag + 1.6f;
		}
		d = (t_complex) {.real = (c->real + 3) * 70, .imag = 800 - c->imag * 70};
		pixels_image(mlx, d.real + 300, d.imag - 50, 0x00FF00);
	}
}

void	lighting_pixels_fern(t_display *mlx)
{
	t_complex	z;

	z.real = 0.0;
	z.imag = 0.0;
	ft_iteration_fern(&z, mlx);
	ft_iteration_fern(&z, mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img->img, -(WIDTH / 4), 0);
}
