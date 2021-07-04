#include "so_long.h"

static void	move_pl(int keycode, t_mlx_params *mlx)
{
	if (keycode == 13 && check_f_coords(mlx))
		mlx->pl->x += 1;
	else if (keycode == 1 && check_b_coords(mlx))
		mlx->pl->x -= 1;
	else if (keycode == 0 && check_l_coords(mlx))
		mlx->pl->y -= 1;
	else if (keycode == 2 && check_r_coords(mlx))
		mlx->pl->y += 1;
}

void	movement(t_mlx_params *mlx)
{
	if (mlx->input->forward && !mlx->input->backward)
		move_pl(13, mlx);
	else if (mlx->input->backward && !mlx->input->forward)
		move_pl(1, mlx);
	if (mlx->input->left && !mlx->input->right)
		move_pl(0, mlx);
	else if (mlx->input->right && !mlx->input->left)
		move_pl(2, mlx);
}

