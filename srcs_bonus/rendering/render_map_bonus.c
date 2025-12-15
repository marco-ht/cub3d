/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:06:39 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 21:11:42 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	draw_miniplayer(t_vars *v, int color)
{
	int	x;
	int	y;
	int	idx;
	int	px;
	int	py;

	px = (int)((v->player.x / BLOCK) * 5) - PLAYER_SIZE / 2;
	py = (int)((v->player.y / BLOCK) * 5) - PLAYER_SIZE / 2;
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			if (py + y > 0 && px + x > 0 && py + y < HEIGHT && px + x < WIDTH)
			{
				idx = (py + y) * v->size_line + (px + x) * v->bpp / 8;
				v->data[idx] = color & 0xFF;
				v->data[idx + 1] = (color >> 8) & 0xFF;
				v->data[idx + 2] = (color >> 16) & 0xFF;
			}
			x++;
		}
		y++;
	}
}

static void	draw_minisqr(t_vars *v, int pos_x, int pos_y, int color)
{
	int	x;
	int	y;
	int	idx;

	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
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

void	draw_minimap(t_vars *v)
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
				draw_minisqr(v, i * 5, j * 5, 0x676767);
			else
				draw_minisqr(v, i * 5, j * 5, 0xFFFFFF);
			i++;
		}
		j++;
	}
}
