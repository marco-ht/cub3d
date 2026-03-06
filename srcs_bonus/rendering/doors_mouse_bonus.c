/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:39:33 by mpierant &        #+#    #+#             */
/*   Updated: 2026/03/06 17:50:26 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	try_toggle_door_at(t_vars *v, int map_x, int map_y)
{
	if (map_y < 0 || map_y >= v->map_size)
		return ;
	if (map_x < 0 || !v->map[map_y] || map_x >= (int)ft_strlen(v->map[map_y]))
		return ;
	if (v->map[map_y][map_x] == 'D')
		v->map[map_y][map_x] = 'O';
	else if (v->map[map_y][map_x] == 'O')
		v->map[map_y][map_x] = 'D';
}

void	toggle_door(t_vars *v)
{
	t_doors	d;

	d.player_map_x = (int)(v->player.x / BLOCK);
	d.player_map_y = (int)(v->player.y / BLOCK);
	d.check_x = v->player.x + cos(v->player.angle) * BLOCK;
	d.check_y = v->player.y + sin(v->player.angle) * BLOCK;
	d.check_map_x = (int)(d.check_x / BLOCK);
	d.check_map_y = (int)(d.check_y / BLOCK);
	if (d.check_map_x != d.player_map_x || d.check_map_y != d.player_map_y)
		try_toggle_door_at(v, d.check_map_x, d.check_map_y);
}

int	mouse_move(int x, int y, t_vars *v)
{
	int	delta_x;

	(void)y;
	if (!v->mouse_enabled)
		return (0);
	delta_x = x - (WIDTH / 2);
	if (delta_x == 0)
		return (0);
	v->player.angle += delta_x * MOUSE_SENSITIVITY;
	if (v->player.angle > 2 * PI)
		v->player.angle -= 2 * PI;
	if (v->player.angle < 0)
		v->player.angle += 2 * PI;
	mlx_mouse_move(v->mlx, v->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	mouse_click(int button, int x, int y, t_vars *v)
{
	(void)button;
	(void)x;
	(void)y;
	if (!v->mouse_enabled)
	{
		v->mouse_enabled = 1;
		mlx_mouse_hide(v->mlx, v->win);
		mlx_mouse_move(v->mlx, v->win, WIDTH / 2, HEIGHT / 2);
	}
	return (0);
}
