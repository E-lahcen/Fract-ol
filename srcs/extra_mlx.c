/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:13:02 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/12 17:42:25 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	pixels_image(t_display *mlx, int x, int y, int color)
{
	*(unsigned int *)&mlx->img.addr[((y * mlx->img.line_len) + x * (mlx->img.bpp / 8))] = color;
}

void	init_values(t_display *mlx)
{
	mlx->xscale = 4.0 / WIDTH;
	mlx->yscale = 4.0 / HEIGHT;
	mlx->zoom_x = 2.0;
	mlx->zoom_y = 2.0;
	mlx->xcord = 0.0;
	mlx->ycord = 0.0;
	mlx->max_it = 60;
	mlx->fix_julia_pos = 0;
	mlx->help = 0;
	// mlx->color.startr = 0;
	// mlx->color.endr = 255;
	// mlx->color.startg = 0;
	// mlx->color.endg = 255;
	// mlx->color.startb = 0;
	// mlx->color.endb = 255;
	mlx->color_shift = 5;
}

int	hundle_no_event(t_display *mlx)
{
	if (mlx->fract == 1)
		lighting_pixels_man(mlx);
	else if (mlx->fract == 2)
		lighting_pixels_julia(mlx);
	else if (mlx->fract == 3)
		lighting_pixels_fern(mlx);
	else if (mlx->fract == 4)
		lighting_pixels_tricorn(mlx);
	return (1);
}

void	color_shift(t_display *mlx)
{
	mlx->color_shift = (mlx->color_shift + 1) % 6;
	set_color_array(mlx);
}