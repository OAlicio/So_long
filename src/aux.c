/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofeverei <ofeverei@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:57:07 by ofeverei          #+#    #+#             */
/*   Updated: 2025/09/30 11:57:09 by ofeverei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_params(int argc, char **argv, t_vars *vars)
{
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nUsage: ./so_long maps/<file.ber>.", 2);
		exit(0);
	}
	vars->map_check = ft_substr(ft_strrchr(argv[1], '/'),
			0, ft_strlen(ft_strrchr(argv[1], '/')));
	if (!vars->map_check)
		exit_with_error(vars, "Map need to be in a folder <maps/map.ber>.");
	if ((vars->map_check[1] == '.' && vars->map_check[2] != '.')
		|| (ft_memcmp(ft_strrchr(vars->map_check, '.'), ".ber", 4) != 0))
		exit_with_error(vars, "Map name: map.ber");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_with_error(vars, "Map File not found.");
	map_get(fd, vars);
	close(fd);
}

int	destroy_on_exit(t_vars *vars)
{
	ft_printf("Exited Early.\n");
	free_all(vars, 0);
	return (0);
}

int	is_in_enemy(t_vars *vars)
{
	if (vars->map_tiles[vars->player.inmap_y][vars->player.inmap_x] == 'N')
		return (1);
	return (0);
}

void	exit_with_error(t_vars *vars, char *error)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	free_all(vars, 1);
}

void	invalid_char(t_vars *vars, int x, int y)
{
	ft_putendl_fd("Error\nInvalid char: ", 2);
	ft_putchar_fd(vars->map_tiles[y / vars->wall.height]
	[x / vars->wall.width], 2);
	ft_putchar_fd('\n', 2);
	free_all(vars, 1);
}
