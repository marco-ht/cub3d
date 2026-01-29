/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_mouse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:00:00 by luevange &            #+#    #+#             */
/*   Updated: 2025/01/27 16:00:00 by luevange &           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	is_door(char c)
{
	return (c == 'D' || c == 'O');
}

int	is_door_closed(char c)
{
	return (c == 'D');
}

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
	int		player_map_x;
	int		player_map_y;
	float	check_x;
	float	check_y;
	int		check_map_x;
	int		check_map_y;

	player_map_x = (int)(v->player.x / BLOCK);
	player_map_y = (int)(v->player.y / BLOCK);
	check_x = v->player.x + cos(v->player.angle) * BLOCK;
	check_y = v->player.y + sin(v->player.angle) * BLOCK;
	check_map_x = (int)(check_x / BLOCK);
	check_map_y = (int)(check_y / BLOCK);
	if (check_map_x != player_map_x || check_map_y != player_map_y)
		try_toggle_door_at(v, check_map_x, check_map_y);
}

int	mouse_move(int x, int y, t_vars *v)
{
	int	delta_x;

	(void)y;
	if (!v->mouse_enabled)
		return (0);
	delta_x = x - v->mouse_x;
	v->player.angle += delta_x * MOUSE_SENSITIVITY;
	if (v->player.angle > 2 * PI)
		v->player.angle -= 2 * PI;
	if (v->player.angle < 0)
		v->player.angle += 2 * PI;
	v->mouse_x = x;
	return (0);
}
