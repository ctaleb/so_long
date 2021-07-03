#include "so_long.h"

int	key_press(int keycode, t_mlx_params *mlx)
{
	if (keycode == 53)
	{
		free_all(mlx, 31);
		exit(0);
	}
	if (keycode == 126)
		mlx->input->forward = 1;
	if (keycode == 125)
		mlx->input->backward = 1;
	if (keycode == 123)
		mlx->input->left = 1;
	if (keycode == 124)
		mlx->input->right = 1;
	return (0);
}

int	key_release(int keycode, t_mlx_params *mlx)
{
	if (keycode == 126)
		mlx->input->forward = 0;
	if (keycode == 125)
		mlx->input->backward = 0;
	if (keycode == 123)
		mlx->input->left = 0;
	if (keycode == 124)
		mlx->input->right = 0;
	return (0);
}
