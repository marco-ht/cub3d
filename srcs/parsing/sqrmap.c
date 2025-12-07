/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:58:14 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/07 23:12:47 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_maxlen(t_vars *v)
{
	int	j;
	int	max;

	max = 0;
	j = 0;
	while (j < v->map_size)
	{
		if ((int)ft_strlen(v->map[j]) > max)
			max = ft_strlen(v->map[j]);
		j++;
	}
	return (max);
}

static char	*ft_strspace(int len, t_vars *v)
{
	char	*str;
	int		i;

	str = malloc(len + 1);
	if (!str)
		return (printf("Error\nAllocation failed\n"), ft_exitclean(v), NULL);
	i = 0;
	while (i < len)
		str[i++] = ' ';
	str[len] = '\0';
	return (str);
}

static char	*ft_strsqr(char *src, int dst_len)
{
	char	*str;
	int		i;
	int		src_len;

	src_len = ft_strlen(src);
	if (src_len > dst_len)
		return (NULL);
	str = malloc(dst_len + 1);
	if (!str)
		return (NULL);
	str[0] = ' ';
	i = 0;
	while (i < src_len)
	{
		str[i + 1] = src[i];
		i++;
	}
	while (i < dst_len)
		str[i++ + 1] = ' ';
	str[dst_len] = '\0';
	return (str);
}

static void	ft_set_player(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	while (j < v->map_size + 2)
	{
		i = 0;
		while (v->map_cpy[j][i])
		{
			if (v->map_cpy[j][i] == 'N' || v->map_cpy[j][i] == 'S'
				|| v->map_cpy[j][i] == 'W' || v->map_cpy[j][i] == 'E')
			{
				v->map_cpy_x_p = i;
				v->map_cpy_y_p = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

int	ft_cpysqrmap(t_vars *v)
{
	int		i;
	char	*tmp;
	int		max_len;

	max_len = ft_maxlen(v);
	v->map_cpy = ft_calloc((v->map_size + 2), sizeof(char *));
	if (!v->map_cpy)
		return (printf("Error\nAllocation failed\n"), ft_exitclean(v), 1);
	v->map_cpy[0] = ft_strspace(max_len + 2, v);
	v->map_cpy[v->map_size + 1] = ft_strspace(max_len + 2, v);
	i = 0;
	while (i < v->map_size)
	{
		tmp = ft_strsqr(v->map[i], max_len + 2);
		if (!tmp)
			return (printf("Error\nAllocation failed\n"), ft_exitclean(v), 1);
		v->map_cpy[i + 1] = tmp;
		i++;
	}
	ft_set_player(v);
	return (0);
}
