/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:40:01 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 08:19:41 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* static void ft_reallocmap(t_vars v, char *str, int size, int fd)
{
    int i;
    char **newmap;
    
    newmap = malloc(sizeof(char *) * (size + 1));
    if (!newmap)
        return(...);
    i = 0;
    while (i < size)
    {
        newmap[i] = v->map[i];
        free(v->map[i]);
        i++;
    }
    newmap[i] = str;
    free(v->map);
    v->map = newmap;
}

int	ft_parse_map(t_vars *v, int fd)
{
	char *str;
	int size;

	size = 0;
	str = ft_skip_emptylines(fd);
	while (str)
	{
        ft_reallocmap(v, str, size, fd);
        size++;
		free(str);
		str = get_next_line(fd);
	}
    //ft_checkmap();
	return (0);
} */
