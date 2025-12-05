/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:46:19 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 22:30:07 by mpierant         ###   ########.fr       */
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
 