/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:40:01 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/06 15:50:37 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// in parsefield if there are spaces after the value
// the error will emerge in the grafic part
// while trying to open the textures.
// there might be valid spaces inside the filename itself

static int	ft_check_mapstr(char *str, int fd, t_vars *v)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			return (printf("Error\nInvalid character '%c' in the map\n",
					str[i]), ft_free_gnl(fd), close(fd), free(str),
				ft_exitclean(v), 1);
		i++;
	}
	if (str[i] == '\n')
		str[i] = '\0';
	return (0);
}

static int	ft_checkfinished(t_vars *v, int fd)
{
	char	*str;

	str = ft_skip_emptylines(fd);
	if (str)
		return (printf("Error\nThere's something after the map\n"),
			ft_free_gnl(fd), close(fd), free(str), ft_exitclean(v), 1);
	return (0);
}

char	**ft_reallocmap(char **oldmap, int old_size, int new_size)
{
	int		i;
	char	**newmap;

	if (new_size < old_size)
		return (NULL);
	newmap = malloc(sizeof(char *) * new_size);
	if (!newmap)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		newmap[i] = oldmap[i];
		i++;
	}
	free(oldmap);
	return (newmap);
}

int	ft_parse_map(t_vars *v, int fd)
{
	char	*str;
	char	**tmp;
	int		size;

	size = 0;
	str = ft_skip_emptylines(fd);
	if (!str)
		return (printf("Error\nMap missing in .cub file\n"), close(fd),
			ft_exitclean(v), 1);
	while (str && ft_strncmp(str, "\n", ft_strlen(str)) != 0)
	{
		ft_check_mapstr(str, fd, v);
		tmp = ft_reallocmap(v->map, size, size + 1);
		if (!tmp)
			return (printf("Error\nAllocation failed\n"), ft_free_gnl(fd),
				close(fd), free(str), ft_exitclean(v), 1);
		v->map = tmp;
		v->map[size] = str;
		size++;
		str = get_next_line(fd);
	}
	free(str);
	ft_checkfinished(v, fd);
	v->map_size = size;
	return (0);
}

/*
--------------------------------------------------------------------------------------------------------------------
	reasoning on parse_map
int	ft_parse_map(t_vars *v, int fd)
{
	char *str;
	char *tmp;
	int size;

	size = 0;
	str = ft_skip_emptylines(fd);
	if (!str)
		return (printf("Error\nMap missing in .cub file\n"), close(fd),
			ft_exitclean(v), 1);
	// ft_free_gnl(fd) not needed because file is finished
	while (str)
	{
		ft_check_mapstr(str, fd, v);
		// controlla se solo caratteri ammesi altrimenti esce clean

		// SAFE REALLOC
		tmp = ft_reallocmap(v->map, size + 1);
		// v->map sara NULL alla prima chiamata
		if (!tmp)
			return (printf("Error\nAllocation failed\n"), ft_free_gnl(fd),
				close(fd), free(str), ft_exitclean(v), 1);
		// il free di v->map lo fara' exitclean con ft_cleanup
		v->map = tmp;
		// in caso di successo realloc fa il free di v->map

		v->map[size] = str;
		size++;

		// free(str); no,
		//I assign it to map(I don 't need to use ft_strdup because I don't cut it,
		//		I keep all the string allocated by getnextline) str = get_next_line(fd);
	}
	v->map_size = size;
	// ft_cpymap(); because we use flodfill for checking spaces
	// ft_checkmap();
	return (0);
} */