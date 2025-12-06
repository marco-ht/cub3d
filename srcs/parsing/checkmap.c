/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:43:50 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/06 18:45:42 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_cpymap(t_vars *v)
{
	int		i;
	char	*tmp;

	v->map_cpy = malloc(sizeof(char *) * v->map_size);
	if (!v->map_cpy)
		return (printf("Error\nAllocation failed\n"), ft_exitclean(v), 1);
	i = 0;
	while (i < v->map_size)
	{
		tmp = ft_strdup(v->map[i]);
		if (!tmp)
			return (printf("Error\nAllocation failed\n"), ft_exitclean(v), 1);
		v->map_cpy[i] = tmp;
		i++;
	}
	return (0);
}

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
			if (v->map[j][i] == 'N' || v->map[j][i] == 'S' || v->map[j][i] == 'W'
				|| v->map[j][i] == 'E')
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

void	ft_checkmap(t_vars *v)
{
	ft_check_player(v);
	ft_cpymap(v);
	// because we use flodfill for checking spaces reachable by user
	// here we'll do the checks
}

/*
	CHECKS ON MAP:
	DONE	1) only admitted chars (ft_check_mapstr(str) direttamente prima di mette la linea nella matrice)
	DONE	2) no chars after map, only empty lines admitted
	DONE	3) in ft_check: there is player one and only one time (appena ho finito di leggere tutte le righe della mappa)
	
	4) in ft_check: closed with walls
	5) in ft_check: (solo dopo verifica chiuso con wall) con flodfill vado a vedere se il giocatore puo raggiungere gli spazi,
		in tal caso errore
 */

 /* 
	To do the checks 4 and 5 we make the map a square by adding a string made of spaces
	as first and last string
	a space char at the beginning of each string
	as many spaces at the end of each string to reach max_len + 2 (at least one space at beginning and end)
	we can just modify mapcpy to mapsqrcpy
	and the we apply floodfill recursively from player start position
	and if we meet any space we clean exit with error (open walls or space reachable by player)
 */