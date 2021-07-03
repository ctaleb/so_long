#include "so_long.h"

void	free_all(t_mlx_params *mlx, int stage)
{
	// int	i;

	if (stage == -9)
		return ;
	// i = mlx->stage;
	// if (mlx->stage >= mlx->d_stage && mlx->d_stage)
	// {
	// 	free_mandatory(mlx);
	// 	free_bonus_sprites(mlx);
	// 	free_bonus_textures(mlx);
	// }
	// if (mlx->stage >= mlx->w_stage + 1 && mlx->w_stage)
	// 	mlx_destroy_image(mlx->ptr, mlx->img->ptr);
	// while (i > 0)
	// {
	// 	free(mlx->memory[i]);
	// 	i--;
	// }
	// if (mlx->stage >= mlx->w_stage && mlx->w_stage && !mlx->save)
	// 	mlx_destroy_window(mlx->ptr, mlx->win);
}

void	mem_check(void *ptr, t_mlx_params *mlx, int ernum, int stage)
{
	if (!ptr)
		error_handler(ernum, mlx, stage);
}

void	error_handler(int ernum, t_mlx_params *mlx, int stage)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("errors.txt", O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		if (i == ernum)
		{
			printf("Error\nCode %s\n", line);
			free(line);
			close(fd);
			free_all(mlx, stage);
			exit(-1 * ernum);
		}
		free(line);
		i++;
	}
	close(fd);
	printf("Unexpected Error\n");
	exit(-99);
}
