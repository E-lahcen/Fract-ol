/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:27:47 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/12 20:35:20 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// unsigned long   ft_rgb2hex(t_color *color)
// {
//     return (((int)color->r & 0xff) << 16) + (((int)color->g & 0xff) << 8) + ((int)color->b & 0xff);
// }

// int	coloring_pixels(t_display *mlx)
// {
// 	double			n;
// 	int				res;

// 	if (mlx->it == mlx->max_it && mlx->fract != 2)
// 		return (0x000000);
// 	n = (double)mlx->it / (double)mlx->max_it;
// 	mlx->color.r = mlx->color.startr * (1 - n) + mlx->color.endr * n;
// 	mlx->color.g = mlx->color.startg * (1 - n) + mlx->color.endg * n;
// 	mlx->color.b = mlx->color.startb * (1 - n) + mlx->color.endb * n;
// 	res = ft_rgb2hex(&mlx->color);
// 	return (res);
// }

int	coloring_pixels(t_display *frctl)
{
	return (frctl->color_scheme[frctl->it]);
}

void	set_color_array(t_display *frctl)
{
	int	i;

	i = 0;
	while (i <= frctl->max_it)
	{
		frctl->color_scheme[i] = calc_color(frctl, i);
		i++;
	}
}

int	calc_color(t_display *frctl, size_t i)
{
	uint8_t	cs;
	uint8_t	rgb[3];
	double	div;

	cs = frctl->color_shift;
	div = (double)i / frctl->max_it;
	if (frctl->color_shift < 3)
	{
		rgb[cs % 3] = 9 * (1 - div) * pow(div, 3) * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * pow((1 - div), 3) * div * 255;
	}
	else
	{
		cs -= 3;
		rgb[cs % 3] = 9 * pow((1 - div), 3) * div * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * (1 - div) * pow(div, 3) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
