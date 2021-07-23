/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:37:53 by ctaleb            #+#    #+#             */
/*   Updated: 2021/07/19 14:14:11 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"

typedef struct s_map {
	int		max_x;
	int		max_y;
	int		start_x;
	int		start_y;
	int		file_len;
	int		ratio;
}	t_map;

typedef struct s_input {
	int	forward;
	int	backward;
	int	left;
	int	right;
}	t_input;

typedef struct s_player {
	int	x;
	int	y;
	int	steps;
}	t_player;

typedef struct s_image {
	void		*ptr;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}	t_image;

typedef struct s_texture {
	void	*ptr;
	int		*addr;
	char	*path;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_texture;

typedef struct s_patrol {
	int		x;
	int		y;
	int		type;
	int		mode;
}	t_patrol;

typedef struct s_mlx_params {
	void		*ptr;
	void		*win;
	char		**file;
	int			finished;
	t_patrol	**patrol;
	t_map		*map;
	t_player	*pl;
	t_image		*img;
	t_texture	*ground;
	t_texture	*wall;
	t_texture	*pickup;
	t_texture	*player;
	t_texture	*h_obstacle;
	t_texture	*v_obstacle;
	t_texture	*goal;
	t_input		*input;
}	t_mlx_params;


	//init
t_mlx_params	*data_init(char **av);

	//errors
void			mem_check(void *ptr, t_mlx_params *mlx, int ernum, int stage);
void			free_all(t_mlx_params *mlx, int stage);
void			error_handler(int ernum, t_mlx_params *mlx, int stage);

	//events
int				key_press(int keycode, t_mlx_params *mlx);
int				key_release(int keycode, t_mlx_params *mlx);
int				frame_gen(t_mlx_params *mlx);

	//map
void			map_data_init(t_mlx_params *mlx, char *path);

	//movement
void			movement(t_mlx_params *mlx);
int				check_f_coords(t_mlx_params *mlx);
int				check_b_coords(t_mlx_params *mlx);
int				check_l_coords(t_mlx_params *mlx);
int				check_r_coords(t_mlx_params *mlx);

	//printing
void			put_map(int x, int y, t_mlx_params *mlx);

#endif