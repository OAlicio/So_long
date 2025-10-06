/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:27:20 by ofeverei          #+#    #+#             */
/*   Updated: 2025/09/30 15:58:10 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_vars *vars, t_entity *entity, int keycode)
{
	if ((keycode == XK_w || keycode == XK_Up))
	{
		if (entity->dir == 1 && entity->y >= 0
			&& (vars->map_tiles[entity->inmap_y - 1]
				[entity->inmap_x] != '1'))
		{
			entity->y -= vars->wall.height;
			entity->step_counter++;
			ft_printf("Steps: %d\n", vars->player.step_counter);
		}
		else
			entity->dir = 1;
	}
}

void	move_down(t_vars *vars, t_entity *entity, int keycode)
{
	int	y;
	int	max_y;

	y = vars->wall.height + entity->y;
	max_y = vars->wall.height * vars->tile_size_y;
	if ((keycode == XK_s || keycode == XK_Down))
	{
		if (entity->dir == 0 && (y < max_y)
			&& (vars->map_tiles[entity->inmap_y + 1]
				[entity->inmap_x] != '1'))
		{
			entity->y += vars->wall.height;
			entity->step_counter++;
			ft_printf("Steps: %d\n", vars->player.step_counter);
		}
		else
			entity->dir = 0;
	}
}

void	move_left(t_vars *vars, t_entity *entity, int keycode)
{
	if ((keycode == XK_a || keycode == XK_Left))
	{
		if (entity->dir == 2 && entity->x > 0
			&& (vars->map_tiles[entity->inmap_y]
				[entity->inmap_x - 1] != '1'))
		{
			entity->x -= vars->wall.width;
			entity->step_counter++;
			ft_printf("Steps: %d\n", vars->player.step_counter);
		}
		else
			entity->dir = 2;
	}
}

void	move_right(t_vars *vars, t_entity *entity, int keycode)
{
	int	x;
	int	max_x;

	x = vars->wall.width + entity->x;
	max_x = vars->wall.width * vars->tile_size_x;
	if ((keycode == XK_d || keycode == XK_Right))
	{
		if (entity->dir == 3 && (x < max_x)
			&& (vars->map_tiles[entity->inmap_y]
				[entity->inmap_x + 1] != '1'))
		{
			entity->x += vars->wall.width;
			entity->step_counter++;
			ft_printf("Steps: %d\n", vars->player.step_counter);
		}
		else
			entity->dir = 3;
	}
}
