/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarrene <dbarrene@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:45:36 by dbarrene          #+#    #+#             */
/*   Updated: 2024/02/14 15:45:37 by dbarrene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
/* ************************************************************************** */
/*  Macros & Window size                                                      */
/* ************************************************************************** */
# define WIDTH 1920
# define HEIGHT 1080
# define MISSING_MAP "Error\nNo Map Was Provided"
# define INVALID_FORMAT "Error\nFormat of the Map Provided was Invalid"
# define INVALID_MAP "Error\nMap Provided Was Not Valid"
# define DUPLICATE_EXIT "Error\nMap Contains An Invalid Number of Exits"
# define DUPLICATE_PLAYERS "Error\nMap Contains An Invalid Number of Players"
# define NO_COLLECTIBLES "Error\nMap Does Not Contain Collectibles"
# define INVALID_SHAPE "Error\nMap Is Not Rectangular"
# define INVALID_ELEMENT "Error\nMap Contains an Invalid Element"
# define FAKE_MAP "Error\nNo Map With That Name Found"
# define INVALID_PATH "Error\nMap Does Not Contain a Valid Path to Objective"
# define CHAR_PATH "./assets/facing_right.png"
# define CHAR_M_PATH "./assets/facing_left.png"
# define EXIT_PATH "./assets/swat_exit.png"
# define COLLEC_PATH "./assets/stonks.png"
# define FLOOR_PATH "./assets/background.png"
# define WALL_PATH "./assets/wall.png"
# define WINNING_MSG "Congratulations!\nYou Have Executed a Crypto Scam\
 Successfully!\n"
/* ************************************************************************** */
/*  Structs                                                                   */
/* ************************************************************************** */
typedef struct s_temp
{
	int		current_x;
	int		current_y;
	char	**map;
	size_t	height;
	size_t	width;
}		t_temp;

typedef struct s_txt
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*player_m;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit;
}		t_txt;

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*player_m;
	mlx_image_t	**collec;
	mlx_image_t	*exit;
}		t_img;

typedef struct s_map
{
	int			x_start;
	int			y_start;
	int			x_pos;
	int			y_pos;
	size_t		height;
	size_t		width;
	size_t		collect_count;
	size_t		player_count;
	size_t		exit_count;
	char		**map;
	mlx_t		*mlx;
	t_txt		*txtrs;
	t_img		*imgs;
	size_t		xs;
	size_t		ys;
	int			**collec_xy;
	size_t		move_count;
	size_t		sq_sz;
}		t_map;
/* ************************************************************************** */
/*  General Struct Modifiers                                                  */
/* ************************************************************************** */
void	update_elements(t_map *map_struct);
void	update_start(t_map *map_struct, char **arr);
void	free_split(char **arguments);
/* ************************************************************************** */
/*  Arg Validation & Map Reading                                              */
/* ************************************************************************** */
int		check_map_args(int argc, char **argv);
int		ft_map_is_closed(t_map *map_struct);
void	open_map(t_map *map_struct, int fd);
int		ft_check_shape(t_map *map_struct);
int		ft_check_elements(t_map *map_struct);
int		find_element(char **arr, char element);
int		parse_map(char **arr);
int		obtain_fd(char *map_name);
void	ft_error_exit(int errcode);
int		is_valid_element(char *str);
/* ************************************************************************** */
/*  Path Validation                                                           */
/* ************************************************************************** */
t_temp	make_temp_struct(t_map *map_struct);
char	**copy_map(char **map, size_t height);
int		path_validity(t_map *map_struct);
void	fill(t_temp temp, int current_x, int current_y);
int		is_valid_path(t_temp temp);
int		ft_get_height(char **arr);
int		check_validity(t_map *map_struct);
int		parse_line(char *line, char *total);
/* ************************************************************************** */
/*  Player Movement                                                           */
/* ************************************************************************** */
void	move_left(t_map *map);
void	move_up(t_map *map);
void	move_right(t_map *map);
void	move_down(t_map *map);
/* ************************************************************************** */
/*  MLX Loading and Freeing                                                   */
/* ************************************************************************** */
void	hooks_function(mlx_key_data_t data, void *param);
void	init_game(t_map *map);
void	load_textures(t_map *map);
void	load_images(t_map *map);
void	resize_images(t_map *map);
void	place_images(t_map *map);
void	place_components(t_map	*map);
void	load_collectibles(t_map *map);
void	hide_collectible(t_map *map);
void	remove_images(t_map *map);
void	delete_txtrs(t_map *map);
void	ft_free_mlx(t_map *map, int errcode);
void	update_positions(t_map *map);
void	place_floor(t_map *map);
void	place_wall(t_map *map);
void	place_player_models(t_map *map);
void	place_exit(t_map *map);
#endif