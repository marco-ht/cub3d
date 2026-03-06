/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:51:50 by mpierant &        #+#    #+#             */
/*   Updated: 2026/03/06 16:52:18 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	ft_check_player(t_vars *v)
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
