/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:16:50 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 17:41:34 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_vars *v, int color)
{
	int	x;
	int	y;
	int	idx;

	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			if ((int)v->player.y + y > 0 && (int)v->player.x + x > 0
				&& (int)v->player.y + y < HEIGHT && (int)v->player.x
				+ x < WIDTH)
			{
				idx = ((int)v->player.y + y) * v->size_line + ((int)v->player.x
						+ x) * v->bpp / 8;
				v->data[idx] = color & 0xFF;
				v->data[idx + 1] = (color >> 8) & 0xFF;
				v->data[idx + 2] = (color >> 16) & 0xFF;
			}
			x++;
		}
		y++;
	}
}

static void draw_sqr(t_vars *v, int pos_x, int pos_y, int color)
{
	int	x;
	int	y;
	int	idx;

	y = 0;
	while (y < BLOCK)
	{
		x = 0;
		while (x < BLOCK)
		{
			if (pos_y + y > 0 && pos_x + x > 0 && pos_y + y < HEIGHT && pos_x
				+ x < WIDTH)
			{
				idx = (pos_y + y) * v->size_line + (pos_x + x) * v->bpp / 8;
				v->data[idx] = color & 0xFF;
				v->data[idx + 1] = (color >> 8) & 0xFF;
				v->data[idx + 2] = (color >> 16) & 0xFF;
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_vars *v)
{
	int		j;
	int		i;
	char	**map;

	map = v->map;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				draw_sqr(v, i * BLOCK, j * BLOCK, 0x676767);
			i++;
		}
		j++;
	}
}

static void	draw_ray(t_vars *v, float angle, int color)
{
	float	x;
	float	y;
	float	cos_angle;
	float	sen_angle;

	x = v->player.x;
	y = v->player.y;
	cos_angle = cos(angle);
	sen_angle = sin(angle);
	while (!touch(v->map, x, y))
	{
		put_pixel(v, x, y, color);
		x += cos_angle;
		y += sen_angle;
	}
}

void	draw_rays(t_vars *v, int color)
{
	float	ray_angle;
	float	fraction;
	int		i;

	ray_angle = v->player.angle - PI / 6;
	fraction = PI / 3 / WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		draw_ray(v, ray_angle, color);
		ray_angle += fraction;
		i++;
	}
}
