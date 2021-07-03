/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:37:32 by ctaleb            #+#    #+#             */
/*   Updated: 2021/07/03 14:16:07 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(t_mlx_params *mlx)
{
	free_all(mlx, 31);
	exit(0);
}

int	main(int ac, char *av[])
{
	t_mlx_params	*mlx;

	if (ac != 2)
		error_handler(1, NULL, -9);
	mlx = data_init(av);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
	mlx_loop_hook(mlx->ptr, frame_gen, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
