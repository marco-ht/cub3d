/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:55:47 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/04 20:11:49 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_extension(t_vars *v)
{
    int i;

    i = 0;
    while (v->scene[i])
        i++;
    if (i >= 5 && v->scene[i - 4] == '.' && v->scene[i - 3] == 'c'
        && v->scene[i - 2] == 'u' && v->scene[i - 1] == 'b')
        return;
    printf("Error: extension must be .cub\n");
    ft_exitclean(v);
}
