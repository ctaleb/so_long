#include "so_long.h"

int	frame_gen(t_mlx_params *mlx)
{
	movement(mlx);
	put_minimap(mlx);
	put_objects(mlx);
	patrol(mlx);
	put_steps(mlx);
	if (mlx->finished)
		ending(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->ptr, 0, 0);
	return (0);
}
