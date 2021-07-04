#include "so_long.h"

int	check_f_coords(t_mlx_params *mlx)
{
	if (mlx->file[mlx->pl->y][mlx->pl->x + 1]
		&& mlx->file[mlx->pl->y][mlx->pl->x + 1] != 1)
		return (1);
	return (0);
}

int	check_b_coords(t_mlx_params *mlx)
{
	if (mlx->file[mlx->pl->y][mlx->pl->x - 1]
		&& mlx->file[mlx->pl->y][mlx->pl->x - 1] != 1)
		return (1);
	return (0);
}

int	check_l_coords(t_mlx_params *mlx)
{
	if (mlx->file[mlx->pl->y - 1][mlx->pl->x]
		&& mlx->file[mlx->pl->y - 1][mlx->pl->x] != 1)
		return (1);
	return (0);
}

int	check_f_coords(t_mlx_params *mlx)
{
	if (mlx->file[mlx->pl->y + 1][mlx->pl->x]
		&& mlx->file[mlx->pl->y + 1][mlx->pl->x] != 1)
		return (1);
	return (0);
}