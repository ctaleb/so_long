#include "so_long.h"

int	rgbtoi(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx_params *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < mlx->res_x && y < mlx->res_y)
	{
		dst = mlx->img->addr + (y * mlx->img->len + x
				* (mlx->img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}