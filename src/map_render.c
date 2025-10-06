/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:26:12 by ofeverei          #+#    #+#             */
/*   Updated: 2025/09/30 11:33:38 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	col_counter(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_tiles[i])
		i++;
	return (i);
}

static void	verify_tiles2(int i, int j, int c_checker, t_vars *vars)
{
	if (c_checker != j)
		exit_with_error(vars, "Not a supported map.");
	if (vars->map_tiles[i][c_checker - 1] != '1')
		exit_with_error(vars, "Map must be surrounded by walls.");
}

void	verify_tiles(int i, int j, t_vars *vars)
{
	if (vars->map_tiles[0][j] != '1' || vars->map_tiles[i][0] != '1')
		exit_with_error(vars, "Map must be surrounded by walls.");
	else if (vars->map_tiles[i][j] == 'P')
	{
		vars->player.total += 1;
		if (vars->player.total > 1)
			exit_with_error(vars, "More than 1 player spawn.");
		else if (vars->player.total == 0)
			exit_with_error(vars, "No player spawn.");
		if (vars->player.total == 1)
		{
			vars->player.x = j * vars->wall.width;
			vars->player.y = i * vars->wall.height;
		}
	}
	else if (vars->map_tiles[i][j] == 'N'
			&& vars->enemy_counter <= vars->enemys)
	{
		vars->patrol[vars->enemy_counter].x = j * vars->wall.width;
		vars->patrol[vars->enemy_counter].y = i * vars->wall.height;
		vars->enemy_counter++;
	}
}

int	row_counter(t_vars *vars)
{
	int	i;
	int	j;
	int	c_checker;

	i = 0;
	while (vars->map_tiles[i])
	{
		j = 0;
		while (vars->map_tiles[i][j])
		{
			verify_tiles(i, j, vars);
			j++;
		}
		if (i == 0)
			c_checker = j;
		verify_tiles2(i, j, c_checker, vars);
		i++;
	}
	return (j);
}

void	draw_tiles(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->wall.height * vars->tile_size_y)
	{
		x = 0;
		while (x < vars->wall.width * vars->tile_size_x)
		{
			put_image(x, y, vars);
			x += vars->wall.width;
		}
		y += vars->wall.height;
	}
}
