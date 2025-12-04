/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:09:32 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/04 23:26:42 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_parse(t_vars *v)
{
	int	fd;

	ft_extension(v);
	fd = open(v->scene, O_RDONLY);
	if (fd == -1)
		return (printf("Error opening .cub file\n"), ft_exitclean(v), 1);
	ft_parse_fields(v, fd);
	// here ft_parse_map after parsing the other fields
	close(fd);
	return (0);
}

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
        parse_value(v, str);
        i++;
    }
    /* if (!v->no || !v->so || !v->we || !v->ea || !v->fl || !v->ce)
        return (printf("Error: repeated parameters in .cub file\n"), close(fd),
			ft_exitclean(v), 1); */
    // ft_convert to convert ce and fl to int, if format invalid -> error
	return (0);
}

void	parse_value(t_vars *v, char *str)
{
    (void)v;
	printf("%s", str);
	free(str);
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
