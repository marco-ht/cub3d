/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:04:27 by mpierant &        #+#    #+#             */
/*   Updated: 2025/12/15 20:22:18 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static float	get_player_angle(char c)
{
	if (c == 'N')
		return (PI * 3 / 2);
	if (c == 'S')
		return (PI / 2);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (PI);
	return (0);
}

static void	set_player_pos(t_player *player, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'W'
				|| map[j][i] == 'E')
			{
				player->angle = get_player_angle(map[j][i]);
				player->x = i * BLOCK + BLOCK / 2;
				player->y = j * BLOCK + BLOCK / 2;
				return ;
			}
			i++;
		}
		j++;
	}
}

void	init_player(t_player *player, char **map)
{
	set_player_pos(player, map);
	player->key_up = 0;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->key_rotleft = 0;
	player->key_rotright = 0;
	player->start_sec = 0;
	player->prev_time = 0;
}
