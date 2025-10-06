/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:29:42 by ofeverei          #+#    #+#             */
/*   Updated: 2025/09/30 15:58:12 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image(int x, int y, t_vars *vars)
{
	if (vars->map_tiles[y / vars->wall.height][x / vars->wall.width] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, x, y);
	else if (vars->map_tiles[y / vars->wall.height]
		[x / vars->wall.width] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coin.img, x, y);
		vars->coin.total += 1;
	}
	else if (vars->map_tiles[y / vars->wall.height]
		[x / vars->wall.width] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit[vars->can_exit].img, x, y);
	else if (vars->map_tiles[y / vars->wall.height]
		[x / vars->wall.width] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ground.img, x, y);
	else if (vars->map_tiles[y / vars->wall.height]
		[x / vars->wall.width] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ground.img, x, y);
	else if (vars->map_tiles[y / vars->wall.height]
		[x / vars->wall.width] == 'N')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ground.img, x, y);
	else
		invalid_char(vars, x, y);
}

void	create_player_img_in_door(t_vars *vars)
{
	vars->player.img[1][0] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pd1.xpm", &vars->player.img_width,
			&vars->player.img_height);
	if (!vars->player.img[1][0])
		exit_with_error(vars, "Can't create Player image.");
	vars->player.img[1][1] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pu1.xpm", &vars->player.img_width2,
			&vars->player.img_height2);
	if (!vars->player.img[1][1])
		exit_with_error(vars, "Can't create Player image.");
	vars->player.img[1][2] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pl1.xpm", &vars->player.img_width,
			&vars->player.img_height);
	if (!vars->player.img[1][2])
		exit_with_error(vars, "Can't create Player image.");
	vars->player.img[1][3] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pr1.xpm", &vars->player.img_width2,
			&vars->player.img_height2);
	if (!vars->player.img[1][3])
		exit_with_error(vars, "Can't create Player image.");
}

void	create_player_img(t_vars *vars)
{
	vars->player.img[0][0] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pd.xpm", &vars->player.img_width,
			&vars->player.img_height);
	if (!vars->player.img[0][0])
		exit_with_error(vars, "Can't create Player image.");
	vars->player.img[0][1] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pu.xpm", &vars->player.img_width2,
			&vars->player.img_height2);
	if (!vars->player.img[0][1])
		exit_with_error(vars, "Can't create Player image.");
	vars->player.img[0][2] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pl.xpm", &vars->player.img_width,
			&vars->player.img_height);
	if (!vars->player.img[0][2])
		exit_with_error(vars, "Can't create Player image.");
	vars->player.img[0][3] = mlx_xpm_file_to_image(vars->mlx,
			"./textures/pr.xpm", &vars->player.img_width2,
			&vars->player.img_height2);
	if (!vars->player.img[0][3])
		exit_with_error(vars, "Can't create Player image.");
}

void	create_enemy_img(t_vars *vars)
{
	vars->patrol_img[0].img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/e_f0.xpm", &vars->patrol_img[0].width,
			&vars->patrol_img[0].height);
	if (!vars->patrol_img[0].img)
		exit_with_error(vars, "Can't create Enemys Image.");
	vars->patrol_img[1].img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/e_f1_2.xpm", &vars->patrol_img[1].width,
			&vars->patrol_img[1].height);
	if (!vars->patrol_img[1].img)
		exit_with_error(vars, "Can't create Enemys Image.");
	vars->patrol_img[2].img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/e_f1_3.xpm", &vars->patrol_img[2].width,
			&vars->patrol_img[1].height);
	if (!vars->patrol_img[2].img)
		exit_with_error(vars, "Can't create Enemys Image.");
}

void	create_image(t_vars *vars)
{
	create_player_img(vars);
	create_player_img_in_door(vars);
	create_enemy_img(vars);
	vars->ground.img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/01.xpm", &vars->ground.width, &vars->ground.height);
	if (!vars->ground.img)
		exit_with_error(vars, "Can't create Ground image.");
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/00.xpm", &vars->wall.width, &vars->wall.height);
	if (!vars->wall.img)
		exit_with_error(vars, "Can't create Wall image.");
	vars->coin.img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/coin3.xpm", &vars->coin.width, &vars->coin.height);
	if (!vars->coin.img)
		exit_with_error(vars, "Can't create Coin image.");
	vars->exit[0].img = mlx_xpm_file_to_image(vars->mlx, "./textures/door.xpm",
			&vars->exit[0].width, &vars->exit[0].height);
	if (!vars->exit[0].img)
		exit_with_error(vars, "Can't create Exit image.");
	vars->exit[1].img = mlx_xpm_file_to_image(vars->mlx, "./textures/door1.xpm",
			&vars->exit[1].width, &vars->exit[1].height);
	if (!vars->exit[1].img)
		exit_with_error(vars, "Can't create Exit image.");
}
