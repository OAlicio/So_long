/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:24:50 by ofeverei          #+#    #+#             */
/*   Updated: 2025/10/01 13:00:34 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map, int map_length, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < map_length)
	{
		free(map[i]);
		i++;
	}
	free(map);
	if (vars->verify.coins_found == 0 && vars->coin.total > 0)
		exit_with_error(vars, "No coin path found.");
}

static void	verify_map(char *map, t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->exit_total == 0)
		exit_with_error(vars, "No exit found.");
	if (vars->exit_total > 1)
		exit_with_error(vars, "More than 1 exit.");
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n'))
			exit_with_error(vars, "There is a leak on the map.");
		i++;
	}
}

void	map_get(int fd, t_vars *vars)
{
	char	buff[2];
	char	*map;
	char	*aux;
	int		rsize;

	map = ft_strdup("");
	rsize = 1;
	while (rsize > 0)
	{
		rsize = read(fd, buff, 1);
		buff[rsize] = '\0';
		aux = ft_strjoin(map, buff);
		free(map);
		map = aux;
		if (buff[0] == 'N')
			vars->enemys++;
		if (buff[0] == 'E')
			vars->exit_total++;
	}
	verify_map(map, vars);
	vars->map_tiles = (ft_split(map, '\n'));
	free(map);
}

static void	flood_fill(char **map, int x, int y, t_vars *vars)
{
	if (x < 0 || y < 0
		|| x >= vars->tile_size_x || y >= vars->tile_size_y)
		return ;
	if (map[y][x] == '1'
			|| map[y][x] == 'X' || map[y][x] == 'N')
		return ;
	if (map[y][x] == 'C')
		vars->verify.coins_found++;
	if (map[y][x] == 'E')
		vars->verify.exit_found++;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, vars);
	flood_fill(map, x - 1, y, vars);
	flood_fill(map, x, y + 1, vars);
	flood_fill(map, x, y - 1, vars);
}

int	validate_map(char **map, t_vars *vars)
{
	int	i;

	i = 0;
	vars->verify.map_copy = malloc(vars->tile_size_y * sizeof(char *));
	while (i < vars->tile_size_y)
	{
		vars->verify.map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	if (vars->player.x == 0)
	{
		exit_with_error(vars, "No Player spawn.");
		return (1);
	}
	vars->verify.x = vars->player.x / vars->wall.width;
	vars->verify.y = vars->player.y / vars->wall.height;
	flood_fill(vars->verify.map_copy, vars->verify.x, vars->verify.y, vars);
	free_map(vars->verify.map_copy, vars->tile_size_y, vars);
	if (vars->verify.exit_found > 1)
		exit_with_error(vars, "More than 1 exit.");
	else if (vars->verify.exit_found < 1)
		exit_with_error(vars, "No exit path found.");
	return (vars->verify.coins_found == vars->coin.total
		&& vars->verify.exit_found == 1);
}
