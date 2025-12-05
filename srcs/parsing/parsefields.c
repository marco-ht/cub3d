/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsefields.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:38:49 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 05:53:33 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_parse_fields(t_vars *v, int fd)
{
	char	*str;
	int		i;

	i = 0;
	while (i < 6)
	{
		str = ft_skip_emptylines(fd);
		if (!str && i == 0)
			return (printf("Error: empty .cub file\n"), close(fd),
				ft_exitclean(v), 1);
		if (!str)
			return (printf("Error: unexpected end of .cub file\n"), close(fd),
				ft_exitclean(v), 1);
		ft_parse_value(v, str, fd);
		i++;
	}
	if (!v->no || !v->so || !v->we || !v->ea || !v->fl || !v->ce)
		return (printf("Error: allocation failed\n"), ft_free_gnl(fd),
			close(fd), ft_exitclean(v), 1);
	/* printf("no: %s", v->no);
	printf("so: %s", v->so);
	printf("we: %s", v->we);
	printf("ea: %s", v->ea);
	printf("fl: %s", v->fl);
	printf("ce: %s", v->ce); */
	// ft_convert to convert ce and fl to int, if format invalid -> error
	ft_convert(v, fd);
	/* printf("f[r]:%d, f[g]:%d, f[b]:%d\n", v->f[0], v->f[1], v->f[2]);
	printf("c[r]:%d, c[g]:%d, c[b]:%d\n", v->c[0], v->c[1], v->c[2]); */
	return (0);
}

int	ft_parse_value(t_vars *v, char *str, int fd)
{
	int	i;
	int	j;

	ft_skip_spaces(&i, &j, str);
	if (!v->no && ft_isno(i, j, str))
		v->no = ft_strdup(&str[i]);
	else if (!v->so && ft_isso(i, j, str))
		v->so = ft_strdup(&str[i]);
	else if (!v->we && ft_iswe(i, j, str))
		v->we = ft_strdup(&str[i]);
	else if (!v->ea && ft_isea(i, j, str))
		v->ea = ft_strdup(&str[i]);
	else if (!v->fl && ft_isf(i, j, str))
		v->fl = ft_strdup(&str[i]);
	else if (!v->ce && ft_isc(i, j, str))
		v->ce = ft_strdup(&str[i]);
	else if (ft_isno(i, j, str) || ft_isso(i, j, str) || ft_iswe(i, j, str)
		|| ft_isea(i, j, str) || ft_isf(i, j, str) || ft_isc(i, j, str))
		return (printf("Error: repeated parameters in .cub file\n"),
			ft_free_gnl(fd), close(fd), free(str), ft_exitclean(v), 1);
	else
		return (printf("Error: unexpected character in .cub file\n"),
			ft_free_gnl(fd), close(fd), free(str), ft_exitclean(v), 1);
	return (free(str), 0);
}

char	*ft_skip_emptylines(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str && ft_strncmp(str, "\n", ft_strlen(str)) == 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	return (str);
}

void	ft_skip_spaces(int *i, int *j, char *str)
{
	*i = 0;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	*j = *i;
	while (str[*i] && str[*i] != ' ')
		(*i)++;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}

int	ft_convert(t_vars *v, int fd)
{
	char	**rgb;

	ft_check_format(v, fd);
	rgb = ft_split(v->fl, ',');
	if (!rgb)
		return (printf("Error: allocation failed\n"), ft_free_gnl(fd),
			close(fd), ft_exitclean(v), 1);
	v->f[0] = ft_atoi(rgb[0]);
	v->f[1] = ft_atoi(rgb[1]);
	v->f[2] = ft_atoi(rgb[2]);
	ft_free_matrix(rgb);
	rgb = ft_split(v->ce, ',');
	if (!rgb)
		return (printf("Error: allocation failed\n"), ft_free_gnl(fd),
			close(fd), ft_exitclean(v), 1);
	v->c[0] = ft_atoi(rgb[0]);
	v->c[1] = ft_atoi(rgb[1]);
	v->c[2] = ft_atoi(rgb[2]);
	ft_free_matrix(rgb);
	ft_check_values(v, fd);
	return (0);
}
