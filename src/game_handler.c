/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:25:05 by ofeverei          #+#    #+#             */
/*   Updated: 2025/10/03 13:02:51 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	finish_game(t_vars *vars)
{
	char	*steps;

	if (is_in_enemy(vars))
	{
		steps = ft_itoa(vars->player.step_counter);
		mlx_string_put(vars->mlx, vars->win, 0, 15, vars->mc, "STEPS = ");
		mlx_string_put(vars->mlx, vars->win, 9 * 5, 15, vars->sc, steps);
		free(steps);
		ft_printf("You Lose.\n");
		free_all(vars, 0);
	}
	if ((vars->map_tiles[vars->player.inmap_y][vars->player.inmap_x] == 'E'
		&& vars->player.coin == vars->verify.coins_found))
	{
		steps = ft_itoa(vars->player.step_counter);
		mlx_string_put(vars->mlx, vars->win, 0, 15, vars->mc, "STEPS = ");
		mlx_string_put(vars->mlx, vars->win, 9 * 5, 15, vars->sc, steps);
		free(steps);
		ft_printf("You Win!\n");
		free_all(vars, 0);
	}
}

void	update_coin(t_vars *vars)
{
	if (vars->map_tiles[vars->player.inmap_y][vars->player.inmap_x] == 'C')
	{
		vars->map_tiles[vars->player.inmap_y][vars->player.inmap_x] = '0';
		vars->player.coin++;
	}
	if (vars->map_tiles[vars->player.inmap_y][vars->player.inmap_x] == 'E' &&
			vars->player.coin != vars->verify.coins_found)
	{
		vars->is_in_door = 1;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player.img[vars->is_in_door][vars->player.dir],
			vars->player.x, vars->player.y);
	}
	else
	{
		vars->is_in_door = 0;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player.img[vars->is_in_door][vars->player.dir],
			vars->player.x, vars->player.y);
	}
	if (vars->player.coin == vars->verify.coins_found && vars->player.coin > 0)
		vars->can_exit = 1;
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		ft_printf("Exited Early.\n");
		free_all(vars, 0);
		return (1);
	}
	if (keycode == XK_w || keycode == XK_Up || keycode == XK_a
		|| keycode == XK_Left || keycode == XK_s || keycode == XK_Down
		|| keycode == XK_d || keycode == XK_Right)
	{
		vars->draw_control = 0;
		move_up(vars, &vars->player, keycode);
		move_right(vars, &vars->player, keycode);
		move_down(vars, &vars->player, keycode);
		move_left(vars, &vars->player, keycode);
		return (0);
	}
	return (1);
}

void	an_enemy(t_vars *vars)
{
	if (vars->i >= vars->enemys)
		vars->i = 0;
	if (vars->tick > 2)
		vars->tick = 0;
	if (vars->enemys > 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->patrol_img[vars->tick].img, vars->patrol[vars->i].x,
			vars->patrol[vars->i].y);
	}
	if (vars->delay == 0)
	{
		vars->delay = 10000 + (10000 * (2 - vars->tick));
		vars->draw_control = 0;
		vars->tick++;
	}
	vars->i++;
}

int	update(t_vars *vars)
{
	char	*steps;

	vars->player.inmap_x = vars->player.x / vars->wall.width;
	vars->player.inmap_y = vars->player.y / vars->wall.height;
	steps = ft_itoa(vars->player.step_counter);
	mlx_string_put(vars->mlx, vars->win, 0, 15, vars->mc, "STEPS = ");
	mlx_string_put(vars->mlx, vars->win, 9 * 5, 15 + 1, vars->sc, steps);
	free(steps);
	if (vars->draw_control == 0)
	{
		mlx_clear_window(vars->mlx, vars->win);
		draw_tiles(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player.img[vars->is_in_door][vars->player.dir],
			vars->player.x, vars->player.y);
		vars->draw_control = 1;
	}
	update_coin(vars);
	finish_game(vars);
	vars->draw_control = 1;
	an_enemy(vars);
	vars->delay--;
	return (0);
}
