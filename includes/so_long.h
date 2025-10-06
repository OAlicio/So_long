/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:30:59 by ofeverei          #+#    #+#             */
/*   Updated: 2025/10/02 19:11:10 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/my_lib.h"
# include <unistd.h>
# include <mlx.h>
# include <X11/keysym.h>

typedef struct s_verify {
	int		x;
	int		y;
	int		exit_found;
	int		total_coins;
	int		coins_found;
	char	**map_copy;
}	t_verify;	

typedef struct s_entity {
	int		x;
	int		y;
	int		cur;
	int		dir;
	int		coin;
	int		total;
	int		playing;
	int		inmap_x;
	int		inmap_y;
	int		img_width;
	int		img_height;
	int		img_width2;
	int		img_height2;
	int		step_counter;
	void	*img[2][4];
}	t_entity;

typedef struct s_img {
	int		total;
	int		width;
	int		height;
	void	*img;
}	t_img;

typedef struct s_vars {
	int			i;
	int			sc;
	int			mc;
	int			tick;
	int			delay;
	int			enemys;
	int			can_exit;
	int			exit_total;
	int			is_in_door;
	int			tile_size_x;
	int			tile_size_y;
	int			draw_control;
	int			enemy_counter;
	char		*map_check;
	char		**map_tiles;
	t_img		wall;
	t_img		coin;
	t_img		exit[2];
	t_img		ground;
	t_img		patrol_img[4];
	t_entity	player;
	t_entity	*patrol;
	t_verify	verify;
	void		*mlx;
	void		*win;
}	t_vars;

int		update(t_vars *vars);
int		col_counter(t_vars *vars);
int		row_counter(t_vars *vars);
int		is_in_enemy(t_vars *vars);
int		destroy_on_exit(t_vars *vars);
int		key_handler(int keycode, t_vars *vars);
int		validate_map(char **map, t_vars *vars);
void	free_img(t_vars *vars);
void	draw_tiles(t_vars *vars);
void	create_image(t_vars *vars);
void	map_get(int fd, t_vars *vars);
void	put_image(int x, int y, t_vars *vars);
void	free_all(t_vars *vars, int exit_value);
void	invalid_char(t_vars *vars, int x, int y);
void	verify_tiles(int i, int j, t_vars *vars);
void	exit_with_error(t_vars *vars, char *error);
void	verify_params(int argc, char **argv, t_vars *vars);
void	move_up(t_vars *vars, t_entity *entity, int keycode);
void	move_down(t_vars *vars, t_entity *entity, int keycode);
void	move_left(t_vars *vars, t_entity *entity, int keycode);
void	move_right(t_vars *vars, t_entity *entity, int keycode);

#endif
