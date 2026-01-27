/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:43:50 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 19:36:01 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_check_player(t_vars *v)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	j = 0;
	while (j < v->map_size)
	{
		i = 0;
		while (v->map[j][i])
		{
			if (v->map[j][i] == 'N' || v->map[j][i] == 'S'
				|| v->map[j][i] == 'W' || v->map[j][i] == 'E')
				n++;
			i++;
		}
		j++;
	}
	if (n != 1)
		return (printf("Error\nThere must be eactly 1 player in the map\n"),
			ft_exitclean(v), 1);
	return (0);
}

static int	ft_is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	ft_check_adjacent(char **map, int x, int y, t_vars *v)
{
	if (x > 0 && ft_is_walkable(map[y][x - 1]))
		v->error_walls = 1;
	if (map[y][x + 1] && ft_is_walkable(map[y][x + 1]))
		v->error_walls = 1;
	if (y > 0 && map[y - 1] && x < (int)ft_strlen(map[y - 1])
		&& ft_is_walkable(map[y - 1][x]))
		v->error_walls = 1;
	if (map[y + 1] && x < (int)ft_strlen(map[y + 1])
		&& ft_is_walkable(map[y + 1][x]))
		v->error_walls = 1;
}

static void	ft_check_spaces(char **map, t_vars *v)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ')
				ft_check_adjacent(map, x, y, v);
			x++;
		}
		y++;
	}
}

static void	ft_printcpymap(t_vars *v)
{
	int	j;

	j = 0;
	while (j < v->map_size + 2)
	{
		printf("%s\n", v->map_cpy[j]);
		j++;
	}
}

int	ft_checkmap(t_vars *v)
{
	ft_check_player(v);
	ft_cpysqrmap(v);
	v->error_walls = 0;
	ft_check_spaces(v->map_cpy, v);
	if (v->error_walls)
		return (printf("Error\nOpen walls or space reachable by player\n"),
			ft_printcpymap(v), ft_exitclean(v), 1);
	return (0);
}

/*
	CHECKS ON MAP:
	DONE	1) only admitted chars
			(ft_check_mapstr(str) before putting the string in the map)
	DONE	2) no chars after map, only empty lines admitted
	DONE	3) in ft_check: there is player one and only one time
	DONE	4) in ft_check: with flodfill closed with walls
			and check if player can reach spaces
*/

/*
   To do the checks 4 we make a copy of the map but squared shaped
   by adding a string made of spaces as first and last string
   a space char at the beginning of each string
   as many spaces as needed at the end of each string to reach max_len + 2
   (at least one space at beginning and end)
   we implement it in mapsqrcpy
   and then we apply floodfill recursively from player start position
   and if we meet any space we exit (clean) with error
   (open walls or space reachable by player)
*/