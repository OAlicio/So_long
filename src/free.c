/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:20:09 by ofeverei          #+#    #+#             */
/*   Updated: 2025/09/30 15:58:14 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_player_img(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 4)
		{
			if (vars->player.img[i][j])
				mlx_destroy_image(vars->mlx, vars->player.img[i][j]);
			j++;
		}
		i++;
	}
}

void	free_enemy_img(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (vars->patrol_img[i].img)
			mlx_destroy_image(vars->mlx, vars->patrol_img[i].img);
		i++;
	}
}

void	free_img(t_vars *vars)
{
	if (vars->ground.img)
		mlx_destroy_image(vars->mlx, vars->ground.img);
	if (vars->wall.img)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->coin.img)
		mlx_destroy_image(vars->mlx, vars->coin.img);
	if (vars->exit[0].img)
		mlx_destroy_image(vars->mlx, vars->exit[0].img);
	if (vars->exit[1].img)
		mlx_destroy_image(vars->mlx, vars->exit[1].img);
	free_player_img(vars);
	free_enemy_img(vars);
	free(vars->patrol);
}

void	free_all(t_vars *vars, int exit_value)
{
	int	i;

	i = 0;
	free_img(vars);
	if (vars->map_check)
		free(vars->map_check);
	if (vars->map_tiles)
	{
		while (vars->map_tiles[i])
		{
			free(vars->map_tiles[i]);
			i++;
		}
		free(vars->map_tiles);
	}
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(exit_value);
}
