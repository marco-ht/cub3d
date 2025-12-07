/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:43:50 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/07 23:45:55 by mpierant         ###   ########.fr       */
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

static void	ft_flodfill(t_point p, char **map, t_vars *v)
{
	if (map[p.y][p.x] == ' ')
	{
		v->error_walls = 1;
		return ;
	}
	if (map[p.y][p.x] == '1' || map[p.y][p.x] == '*')
		return ;
	if (map[p.y][p.x] == '0')
		map[p.y][p.x] = '*';
	ft_flodfill((t_point){p.x + 1, p.y}, map, v);
	ft_flodfill((t_point){p.x - 1, p.y}, map, v);
	ft_flodfill((t_point){p.x, p.y + 1}, map, v);
	ft_flodfill((t_point){p.x, p.y - 1}, map, v);
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
	t_point	p;

	ft_check_player(v);
	ft_cpysqrmap(v);
	p.x = v->map_cpy_x_p;
	p.y = v->map_cpy_y_p;
	v->error_walls = 0;
	ft_flodfill(p, v->map_cpy, v);
	if (v->error_walls)
		return (printf("Error\nOpen walls or space reachable by player\n"),
			ft_printcpymap(v), ft_exitclean(v), 1);
	return (0);
}

/*
	CHECKS ON MAP:
	DONE	1) only admitted chars (ft_check_mapstr(str) before putting the string in the map)
	DONE	2) no chars after map, only empty lines admitted
	DONE	3) in ft_check: there is player one and only one time
	DONE	4) in ft_check: with flodfill closed with walls and check if player can reach spaces
*/

/*
   To do the checks 4 we make a copy of the map but squared shaped
   by adding a string made of spaces as first and last string
   a space char at the beginning of each string
   as many spaces as needed at the end of each string to reach max_len + 2
   (at least one space at beginning and end)
   we implement it in mapsqrcpy
   and then we apply floodfill recursively from player start position
   and if we meet any space we exit (clean) with error (open walls or space reachable by player)
*/