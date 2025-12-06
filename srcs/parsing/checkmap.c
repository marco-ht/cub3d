/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 21:43:50 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/06 15:37:48 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int ft_cpymap(t_vars *v)
{
	int		i;
	//char	**map_cpy;
    char    *tmp;

	printf("v->map_size=%d\n", v->map_size);
	printf("v->map[v->map_size - 1]=%s\n", v->map[v->map_size - 1]);
	v->map_cpy = malloc(sizeof(char *) * v->map_size);
	if (!v->map_cpy)
		return (printf("Error\nAllocation failed\n"), ft_exitclean(v), 1);
	i = 0;
	while (i < v->map_size)
    {
        tmp = ft_strdup(v->map[i]);
		printf("tmp =%s\n", tmp);
        if (!tmp)
		    return (printf("Error\nAllocation failed\n"), ft_exitclean(v), 1);
        v->map_cpy[i] = tmp;
		i++;
    }
    return (0);
}

void	ft_checkmap(t_vars *v)
{
	ft_cpymap(v); // because we use flodfill for checking spaces reachable by user

	//test
	printf("v->map[0] = %s\n", v->map[0]);
	printf("v->map_cpy[0] = %s\n", v->map_cpy[0]);
	//here we'll do the checks
}

/*
	CHECKS ON MAP:
	1) only admitted chars (ft_check_mapstr(str) direttamente prima di mette la linea nella matrice)
    2) no chars after map, only empty lines admitted
    
	3) in ft_check: there is player one and only one time (appena ho finito di leggere tutte le righe della mappa)
	4) in ft_check: closed with walls
	5) in ft_check: (solo dopo verifica chiuso con wall) con flodfill vado a vedere se il giocatore puo raggiungere gli spazi,
		in tal caso errore
 */