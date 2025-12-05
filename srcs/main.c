/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant <mpierant@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:56:29 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/05 06:26:37 by mpierant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_vars	v;
    
    if (argc != 2)
        return (printf("Error\nWrong number of parameters!\n"), 1);
    ft_init(&v);
    v.scene = ft_strdup(argv[1]);
    ft_parse(&v);
    //Here ft_launch to run the game if parsing is succesful
    ft_cleanup(&v);
    printf("DEBUG: succes.\n");
}


/*
TESTS: (randomorder.cub has to works)
./cub3D
./cub3D "invalid num of" "parameters"
./cub3D "maps/wrongextention.cubf"
./cub3D "maps/nonexistent.cub"
./cub3D "maps/empty.cub"
./cub3D "maps/justnewlines.cub"
./cub3D "maps/incomplete.cub"
./cub3D "maps/repetition.cub"
./cub3D "maps/invalidparam.cub"
./cub3D "maps/randomorder.cub"
./cub3D "maps/coloursformat.cub"
./cub3D "maps/coloursvalues.cub"
*/