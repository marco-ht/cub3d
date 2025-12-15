/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:46:19 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 01:14:57 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_free_map(char **map, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void    ft_freemapcpy(t_vars *v)
{
    int i;

    i = 0;
    while (i < v->map_size + 2)
    {
        if (v->map_cpy[i])
            free(v->map_cpy[i]);
        i++;
    }
    free(v->map_cpy);
}
 