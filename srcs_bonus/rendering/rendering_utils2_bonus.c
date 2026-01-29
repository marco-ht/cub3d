/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:19:20 by mpierant &        #+#    #+#             */
/*   Updated: 2026/01/29 17:29:08 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_valid(char **map, float new_x, float new_y)
{
	int	dim_y;
	int	dim_x;
	int	grid_x;
	int	grid_y;

	grid_x = (int)new_x / BLOCK;
	grid_y = (int)new_y / BLOCK;
	if (grid_x < 0 || grid_y < 0)
		return (0);
	dim_y = 0;
	while (map[dim_y])
		dim_y++;
	if (grid_y >= dim_y)
		return (0);
	dim_x = ft_strlen(map[grid_y]);
	if (grid_x >= dim_x)
		return (0);
	return (1);
}

static int	is_s_valid(char **map, int map_x, int map_y)
{
	int	dim_y;
	int	dim_x;

	if (map_x < 0 || map_y < 0)
		return (0);
	dim_y = 0;
	while (map[dim_y])
		dim_y++;
	if (map_y >= dim_y)
		return (0);
	dim_x = ft_strlen(map[map_y]);
	if (map_x >= dim_x)
		return (0);
	return (1);
}

int	touch(char **map, float new_x, float new_y)
{
	char	c;

	if (!is_valid(map, new_x, new_y))
		return (1);
	c = map[(int)new_y / BLOCK][(int)new_x / BLOCK];
	if (c == '1' || c == 'D')
		return (1);
	return (0);
}

int	stouch(char **map, int map_x, int map_y)
{
	char	c;

	if (!is_s_valid(map, map_x, map_y))
		return (1);
	c = map[map_y][map_x];
	if (c == '1' || c == 'D')
		return (1);
	return (0);
}