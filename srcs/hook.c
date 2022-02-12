/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:29:46 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/12 20:33:46 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_event(int keysym, t_display *mlx)
{	
	if (keysym == 53)
		destroy(mlx);
	if (keysym == 49)
		mlx->help = !mlx->help;
	hundle_key_event(keysym, mlx);
	hundle_no_event(mlx);
	return (0);
}

int	mouse_event(int button, int x, int y, t_display *mlx)
{
	if (button == 1)
	{
		mlx->fix_julia_pos = !mlx->fix_julia_pos;
		return (0);
	}
	else if (button == 2)
	{
		color_shift(mlx);
		hundle_no_event(mlx);
		return (0);
	}
	if (button == 5 || button == 4)
		hundle_mouse_event(button, x, y, mlx);
	hundle_no_event(mlx);
	return (0);
}

int	mouse_cord(int x, int y, t_display *mlx)
{
	if (!mlx->fix_julia_pos)
	{
		if ((x <= WIDTH && x >= 0) || (y <= HEIGHT && y >= 0))
		{
			mlx->xcord = ((x * mlx->xscale) - mlx->zoom_x);
			mlx->ycord = ((y * mlx->yscale) - mlx->zoom_y);
		}
		lighting_pixels_julia(mlx);
	}
	return (0);
}

void	hundle_key_event(int keysym, t_display *mlx)
{
	// if (keysym == 15)
	// 	mlx->color.endr -= 100;
	// else if (keysym == 5)
	// 	mlx->color.endg -= 100;
	// else if (keysym == 11)
	// 	mlx->color.endb -= 100;
	// else if (keysym == 17)
	// 	mlx->color.endr += 100;
	// else if (keysym == 4)
	// 	mlx->color.endg += 100;
	// else if (keysym == 45)
	// 	mlx->color.endb += 100;
	if (keysym == 124)
		mlx->zoom_x -= 20 * mlx->xscale;
	else if (keysym == 123)
		mlx->zoom_x += 20 * mlx->xscale;
	else if (keysym == 126)
		mlx->zoom_y += 20 * mlx->yscale;
	else if (keysym == 125)
		mlx->zoom_y -= 20 * mlx->yscale;
}

void	hundle_mouse_event(int button, int x, int y, t_display *mlx)
{
	if (button == 5)
	{
		mlx->max_it += 15;
		mlx->xscale *= 0.5;
		mlx->yscale *= 0.5;
		mlx->zoom_x = mlx->zoom_x - (x * mlx->xscale);
		mlx->zoom_y = mlx->zoom_y - (y * mlx->yscale);
	}
	else if (button == 4)
	{
		mlx->max_it -= 15;
		mlx->zoom_x = mlx->zoom_x + (x * mlx->xscale);
		mlx->zoom_y = mlx->zoom_y + (y * mlx->yscale);
		mlx->yscale /= 0.5;
		mlx->xscale /= 0.5;
	}
}
