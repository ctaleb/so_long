#include "so_long.h"

void	check_start(t_mlx_params *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->file[i])
	{
		j = 0;
		while (mlx->file[j])
		{
			if (mlx->file[i][j] = 'P')
			{
				if (mlx->map->start_x < 0 && mlx->map->start_y < 0)
				{
					mlx->map->start_x = j;
					mlx->map->start_y = i;
				}
				else
					error_handler(12, NULL, -9);
			}
			j++;
		}
		i++;
	}
}

void	check_border(t_mlx_params *mlx)
{
	int	i;

	i = 0;
	while (mlx->file[0][i])
	{
		if (mlx->file[0][i] != '1' || mlx->file[mlx->map->max_y - 1][i] != '1')
			error_handler(10, NULL, -9);
		i++;
	}
	i = 0;
	while (mlx->file[i][0])
	{
		if (mlx->file[i][0] != '1' || mlx->file[i][mlx->map->max_x - 1] != '1')
			error_handler(10, NULL, -9);
		i++;
	}
	check_start(mlx);
}

void	map_check(t_mlx_params *mlx)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (mlx->file[i])
	{
		j = 0;
		while (mlx->file[i][j])
		{
			if (mlx->file[i][j] != '0' || mlx->file[i][j] != '1' || mlx->file[i][j] != 'C'
				|| mlx->file[i][j] != 'P' || mlx->file[i][j] != 'E'
				|| mlx->file[i][j] != 'H' || mlx->file[i][j] != 'V')
				error_handler(9, NULL, 5);
			j++;
		}
		if (i == 0)
			min = j;
		else if (min != j )
			error_handler(11, NULL, -9);
		i++;
	}
	mlx->map->max_x = j;
	mlx->map->max_y = i;
	check_border(mlx);
}

void	map_open(char *path, t_mlx_params *mlx)
{
	int		fd;
	int		i;
	char	*line;

	mlx->map = malloc(sizeof(t_map));
	mem_check(mlx->map, mlx, 2, 1);
	map_data_init(mlx, path);
	fd = open(path, O_RDWR);
	if (fd < 0)
		error_handler(11, mlx, 3);
	i = 0;
	while (ft_get_next_line(fd, 10, &line))
	{
		mlx->file[i] = ft_strdup(line);
		mem_check(mlx->file[i], mlx, 2, 1);
		free(line);
		line = NULL;
		i++;
	}
	mlx->file[i] = ft_strdup(line);
	mem_check(mlx->file[i], mlx, 2, 1);
	free(line);
	if (close(fd) < 0)
		error_handler(12, mlx, 4);
	map_check(mlx);
}

t_mlx_params	*data_init(char **av)
{
	t_mlx_params	*mlx;

	mlx = malloc(sizeof(t_mlx_params));
	mem_check(mlx, mlx, 2, 0);
	map_open(av[1], mlx);
	return (mlx);
}