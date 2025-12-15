/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:46:19 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 19:49:40 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_freemapcpy(t_vars *v)
{
	int	i;

	i = 0;
	while (i < v->map_size + 2)
	{
		if (v->map_cpy[i])
			free(v->map_cpy[i]);
		i++;
	}
	free(v->map_cpy);
}

void	ft_init(t_vars *v)
{
	ft_memset(v, 0, sizeof(t_vars));
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_free_gnl(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}
