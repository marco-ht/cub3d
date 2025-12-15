/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:56:29 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 21:03:15 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	v;

	if (argc != 2)
		return (printf("Error\nWrong number of parameters!\n"), 1);
	ft_init(&v);
	v.scene = ft_strdup(argv[1]);
	ft_parse(&v);
	ft_launch(&v);
	ft_cleanup(&v);
}

/*
*********** TESTS ***********
(randomorder.cub has to works)
(spaced name.cub has to works)

./cub3D_bonus
./cub3D_bonus "invalid num of" "parameters"
./cub3D_bonus "maps/wrongextention.cubf"
./cub3D_bonus "maps/nonexistent.cub"
./cub3D_bonus "maps/no_perm.cub"
./cub3D_bonus "maps/spaced name.cub"

// parameters errors
./cub3D_bonus "maps/empty.cub"
./cub3D_bonus "maps/justnewlines.cub"
./cub3D_bonus "maps/incomplete.cub"
./cub3D_bonus "maps/repetition.cub"
./cub3D_bonus "maps/invalidparam.cub"
./cub3D_bonus "maps/randomorder.cub"
./cub3D_bonus "maps/texture_noxpm.cub"
./cub3D_bonus "maps/texture_notexist.cub"
./cub3D_bonus "maps/texture_noperm.cub"
./cub3D_bonus "maps/coloursformat.cub"
./cub3D_bonus "maps/coloursformat2.cub"
./cub3D_bonus "maps/coloursvalues.cub"

// map errors
./cub3D_bonus "maps/map_nomap.cub"
./cub3D_bonus "maps/map_invalidchar.cub"
./cub3D_bonus "maps/map_textafter.cub"
./cub3D_bonus "maps/map_noplayer.cub"
./cub3D_bonus "maps/map_multiplayer.cub"
./cub3D_bonus "maps/map_openwalls.cub"
./cub3D_bonus "maps/map_spaceinside.cub"


*********** MEMORY LEAKS ***********

valgrind ./cub3D_bonus
valgrind ./cub3D_bonus "invalid num of" "parameters"
valgrind ./cub3D_bonus "maps/wrongextention.cubf"
valgrind ./cub3D_bonus "maps/nonexistent.cub"
valgrind ./cub3D_bonus "maps/no_perm.cub"
valgrind ./cub3D_bonus "maps/spaced name.cub"

// parameters errors
valgrind ./cub3D_bonus "maps/empty.cub"
valgrind ./cub3D_bonus "maps/justnewlines.cub"
valgrind ./cub3D_bonus "maps/incomplete.cub"
valgrind ./cub3D_bonus "maps/repetition.cub"
valgrind ./cub3D_bonus "maps/invalidparam.cub"
valgrind ./cub3D_bonus "maps/randomorder.cub"
valgrind ./cub3D_bonus "maps/texture_noxpm.cub"
valgrind ./cub3D_bonus "maps/texture_notexist.cub"
valgrind ./cub3D_bonus "maps/texture_noperm.cub"
valgrind ./cub3D_bonus "maps/coloursformat.cub"
valgrind ./cub3D_bonus "maps/coloursformat2.cub"
valgrind ./cub3D_bonus "maps/coloursvalues.cub"

// map errors
valgrind ./cub3D_bonus "maps/map_nomap.cub"
valgrind ./cub3D_bonus "maps/map_invalidchar.cub"
valgrind ./cub3D_bonus "maps/map_textafter.cub"
valgrind ./cub3D_bonus "maps/map_noplayer.cub"
valgrind ./cub3D_bonus "maps/map_multiplayer.cub"
valgrind ./cub3D_bonus "maps/map_openwalls.cub"
valgrind ./cub3D_bonus "maps/map_spaceinside.cub"
*/

// valgrind --leak-check=full --show-leak-kinds=all
