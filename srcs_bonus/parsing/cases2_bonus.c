/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:36:06 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 20:20:55 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	ft_isf(int i, int j, char *str)
{
	return (str[i] && str[i] != '\n' && str[j] && str[j + 1] && str[j] == 'F'
		&& str[j + 1] == ' ');
}

int	ft_isc(int i, int j, char *str)
{
	return (str[i] && str[i] != '\n' && str[j] && str[j + 1] && str[j] == 'C'
		&& str[j + 1] == ' ');
}
