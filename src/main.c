/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:20:15 by ofeverei          #+#    #+#             */
/*   Updated: 2025/10/03 12:20:18 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(vars));
	verify_params(argc, argv, &vars);
	vars.patrol = malloc(sizeof(t_entity) * vars.enemys);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit_with_error(&vars, "Can't initialize Mlx.");
	vars.sc = 0x00F2B705;
	vars.mc = 0x00FFFFFF;
	create_image(&vars);
	vars.tile_size_x = row_counter(&vars);
	vars.tile_size_y = col_counter(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.wall.width * vars.tile_size_x,
			vars.wall.height * vars.tile_size_y, "So_long");
	update(&vars);
	if (vars.coin.total == 0)
		exit_with_error(&vars, "No coin found.");
	if (!validate_map(vars.map_tiles, &vars))
		exit_with_error(&vars, "Unplayable Map.");
	mlx_hook(vars.win, 17, 0, destroy_on_exit, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_loop_hook(vars.mlx, update, &vars);
	mlx_loop(vars.mlx);
}
