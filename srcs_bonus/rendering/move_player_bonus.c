/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:58:58 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 20:19:57 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	move_rot(t_player *player)
{
	if (player->key_rotleft)
		player->angle -= player->angle_speed;
	if (player->key_rotright)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
}

static void	move_along(t_player *player)
{
	if (player->key_up)
	{
		player->move_x += cos(player->angle) * player->speed;
		player->move_y += sin(player->angle) * player->speed;
	}
	if (player->key_down)
	{
		player->move_x -= cos(player->angle) * player->speed;
		player->move_y -= sin(player->angle) * player->speed;
	}
}

static void	move_ort(t_player *player)
{
	if (player->key_left)
	{
		player->move_x += sin(player->angle) * player->speed;
		player->move_y -= cos(player->angle) * player->speed;
	}
	if (player->key_right)
	{
		player->move_x -= sin(player->angle) * player->speed;
		player->move_y += cos(player->angle) * player->speed;
	}
}

void	move_player(t_player *player, char **map)
{
	player->speed = SPEED * player->time_diff;
	player->angle_speed = ANGLE_SPEED * player->time_diff;
	move_rot(player);
	player->move_x = 0;
	player->move_y = 0;
	move_along(player);
	move_ort(player);
	if (!touch(map, player->x + player->move_x, player->y))
		player->x += player->move_x;
	if (!touch(map, player->x, player->y + player->move_y))
		player->y += player->move_y;
}
