/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:46:51 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/08 04:27:43 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_cleanup(t_vars *v)
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
	if (v->mlx_img)
		mlx_destroy_image(v->mlx, v->mlx_img);
	if (v->mlx_win)
		mlx_destroy_window(v->mlx, v->mlx_win);
	if (v->mlx)
	{
		mlx_destroy_display(v->mlx);
		free(v->mlx);
	}
	printf("DEBUG: cleanup done.\n");
}
void	ft_exitclean(t_vars *v)
{
	printf("DEBUG: exit clean called.\n");
	ft_cleanup(v);
	exit(1);
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
	char *str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
}