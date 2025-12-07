/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:46:51 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/07 23:52:21 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_cleanup(t_vars *v)
{
    if (v->scene)
        free(v->scene);
    if (v->no)
        free(v->no);
    if (v->so)
        free(v->so);
    if (v->we)
        free(v->we);
    if (v->ea)
        free(v->ea);
    if (v->fl)
        free(v->fl);
    if (v->ce)
        free(v->ce);
    if (v->map)
        ft_free_map(v->map, v->map_size);
    if (v->map_cpy)
        ft_freemapcpy(v);
    printf("DEBUG: cleanup done.\n");
}
void    ft_exitclean(t_vars *v)
{
    printf("DEBUG: exit clean called.\n");
    ft_cleanup(v);
    exit(1);
}

void    ft_init(t_vars *v)
{
    v->scene = NULL;
    v->no = NULL;
    v->so = NULL;
    v->we = NULL;
    v->ea = NULL;
    v->fl = NULL;
	v->ce = NULL;
    v->map = NULL;
    v->map_cpy = NULL;
}
 
void    ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
    free(matrix);
}

void    ft_free_gnl(int fd)
{
    char	*str;
    
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}