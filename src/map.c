#include "so_long.h"

void	print_minimap(t_mlx_params *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y / mlx->map->ratio < mlx->map->max_y)
	{
		x = 0;
		while (x / mlx->map->ratio < mlx->map->max_x)
		{
			put_map(x, y, mlx);
			x++;
		}
		y++;
	}
}

void	put_map(int x, int y, t_mlx_params *mlx)
{
	if (x / mlx->map->ratio >= mlx->map->max_x
		|| y / mlx->map->ratio >= mlx->map->max_y)
		return ;
	else if (mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == ' ')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 38, 38, 38));
	else if (mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == '1'
		|| mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == '3')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 80, 80, 80));
	else if (mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == '0')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 255, 255, 255));
	else if ((mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] >= '2'
		&& mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] <= '9')
		|| mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == 'K')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 65, 105, 225));
	else if (mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == 'N'
		|| mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == 'S'
		|| mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == 'E'
		|| mlx->file[y / mlx->map->ratio][x / mlx->map->ratio] == 'W')
		my_mlx_pixel_put(mlx, x, y, rgbtoi(0, 255, 215, 0));
}
