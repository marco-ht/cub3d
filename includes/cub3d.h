/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierant & luevange <marvin@student.42r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:00:04 by mpierant          #+#    #+#             */
/*   Updated: 2025/12/15 19:01:07 by mpierant &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

// Keysym definitions for macOS/Linux compatibility
# ifdef __APPLE__
#  define XK_Escape 53
#  define XK_w 13
#  define XK_s 1
#  define XK_a 0
#  define XK_d 2
#  define XK_Left 123
#  define XK_Right 124
# else
#  include <X11/keysym.h>
# endif

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1024
# define PLAYER_SIZE 3
# define SPEED 110.0
# define ANGLE_SPEED 1.0
# define BLOCK 64
# define PI 3.14159265358979
# define DEBUG 0

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;

	float		speed;
	float		angle_speed;
	float		move_x;
	float		move_y;

	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;
	int			key_rotleft;
	int			key_rotright;

	long		start_sec;
	float		prev_time;
	float		time_diff;
}				t_player;

typedef struct s_texture
{
	char		*path;
	void		*img;
	int			height;
	int			width;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct s_ray
{
	float		x;
	float		y;
	float		angle;
	float		dir_x;
	float		dir_y;
	int			map_x;
	int			map_y;
	double		delta_x;
	double		delta_y;
	int			step_x;
	int			step_y;
	double		dist_x;
	double		dist_y;
	int			side;
	t_texture	*current_texture;
	int			current_pixel[3];
	int			dist_real;
	int			tex_x;
	int			tex_y;
}				t_ray;

typedef struct s_vars
{
	char		*scene;
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	char		*fl;
	char		*ce;
	int			f[3];
	int			c[3];
	int			map_size;
	char		**map;
	char		**map_cpy;
	int			map_cpy_x_p;
	int			map_cpy_y_p;
	int			error_walls;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
	t_ray		ray;
}				t_vars;

// Initialization
void			ft_init(t_vars *v);

// Parsing
int				ft_parse(t_vars *v);
int				ft_parse_fields(t_vars *v, int fd);
int				ft_parse_value(t_vars *v, char *str, int fd);
int				ft_parse_map(t_vars *v, int fd);

// Parsing utils
void			ft_extension(t_vars *v);
char			*ft_skip_emptylines(int fd);
void			ft_skip_spaces(int *i, int *j, char *str);
char			*get_next_line(int fd);
void			ft_free_gnl(int fd);
int				ft_isno(int i, int j, char *str);
int				ft_isso(int i, int j, char *str);
int				ft_iswe(int i, int j, char *str);
int				ft_isea(int i, int j, char *str);
int				ft_isf(int i, int j, char *str);
int				ft_isc(int i, int j, char *str);
int				ft_convert(t_vars *v, int fd);
void			ft_free_matrix(char **matrix);
void			ft_check_format(t_vars *v, int fd);
int				ft_check_values(t_vars *v, int fd);
int				ft_checkmap(t_vars *v);
int				ft_cpysqrmap(t_vars *v);
void			ft_check_textures(t_vars *v, int fd);

// Rendering
void			ft_launch(t_vars *v);
void			init_player(t_player *player, char **map);
int				loop_rendering(t_vars *v);
void			move_player(t_player *player, char **map);
void			put_pixel(t_vars *v, float x, float y, int color);
void			put_pixel_nohex(t_vars *v, float x, float y, int *color);
void			gettime(float *prev_time, float *time_diff, long *start_sec);
void			set_texture(t_vars *v);
void			get_pixel_color_from_texture(t_vars *v, int tx, int ty);

// Rendering utils
void			clear_image(t_vars *v);
int				touch(char **map, float new_x, float new_y);
int				stouch(char **map, int map_x, int map_y);
void			draw_ceiling(t_vars *v, int x, int y, int end);
void			draw_floor(t_vars *v, int x, int y, int end);

// Raycasting
void			set_ray(t_vars *v);
void			advance_ray(t_vars *v);

// DEBUG MODE
void			draw_player(t_vars *v, int color);
void			draw_map(t_vars *v);
void			draw_rays(t_vars *v, int color);

// Cleanup and exit
void			ft_cleanup(t_vars *v);
void			ft_exitclean(t_vars *v);
void			ft_free_map(char **map, int size);
void			ft_freemapcpy(t_vars *v);
int				ft_exitsucces(t_vars *v);

#endif