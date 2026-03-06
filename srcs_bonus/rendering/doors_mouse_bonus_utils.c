/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_mouse_bonus_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:50:05 by mpierant &        #+#    #+#             */
/*   Updated: 2026/03/06 17:50:22 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	is_door(char c)
{
	return (c == 'D' || c == 'O');
}

int	is_door_closed(char c)
{
	return (c == 'D');
}
