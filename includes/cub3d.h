/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:00:04 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 00:57:34 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	char	*scene;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*fl;
	char	*ce;
	int		f[3];
	int		c[3];
	char	**map;
	char	**map_cpy;
}			t_vars;

void		ft_init(t_vars *v);

// Parsing
int			ft_parse(t_vars *v);
void		ft_extension(t_vars *v);
int			ft_parse_fields(t_vars *v, int fd);
int			ft_parse_value(t_vars *v, char *str, int fd);

// Parsing utils
char		*ft_skip_emptylines(int fd);
void		ft_skip_spaces(int *i, int *j, char *str);
char		*get_next_line(int fd);
int			ft_isno(int i, int j, char *str);
int			ft_isso(int i, int j, char *str);
int			ft_iswe(int i, int j, char *str);
int			ft_isea(int i, int j, char *str);
int			ft_isf(int i, int j, char *str);
int			ft_isc(int i, int j, char *str);

// Cleanup and exit
void		ft_cleanup(t_vars *v);
void		ft_exitclean(t_vars *v);

#endif