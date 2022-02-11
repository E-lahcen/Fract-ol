/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:27:47 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/11 11:50:52 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

unsigned long   ft_rgb2hex(t_color *color)
{
    return (((int)color->r & 0xff) << 16) + (((int)color->g & 0xff) << 8) + ((int)color->b & 0xff);
}

int	coloring_pixels(t_display *mlx)
{
	double			n;
	int				res;

	if (mlx->it == mlx->max_it && mlx->fract != 2)
		return (0x000000);
	n = (double)mlx->it / (double)mlx->max_it;
	mlx->color->r = mlx->color->startr * (1 - n) + mlx->color->endr * n;
	mlx->color->g = mlx->color->startg * (1 - n) + mlx->color->endg * n;
	mlx->color->b = mlx->color->startb * (1 - n) + mlx->color->endb * n;
	res = ft_rgb2hex(mlx->color);
	return (res);
}
