/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:56:29 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/04 22:09:05 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_vars	v;
    
    if (argc != 2)
        return (printf("Wrong number of parameters!\n"), 1);
    ft_init(&v);
    v.scene = ft_strdup(argv[1]);
    ft_parse(&v);
    //Here ft_launch to run the game if parsing is succesful
    ft_cleanup(&v);
    printf("DEBUG: succes.\n");
}
