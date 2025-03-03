#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <string.h>
#include <stdio.h>

//count valid character!
typedef	struct v_char
{
	int  p;
	int  c;
	int	 e;
	int  n;
}	t_vchar;

//simple data
typedef struct s_data
{
	int	len;
	int i;
	int j;
	char *res;
	int pos_y;
	int pos_x;
}t_sdata;

typedef struct textures
{
	void    *wall_img;
	void    *floor_img;
	void    *player_img;
	void    *exit_img;
	void    *coin_img;
	int     img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*window;
}t_textur;

// strcut for read map
typedef struct s_map
{
	int  c;
	int	check_c;
	char    **map;
	char    **copy_map;
	int     rows;
	int     columns;
	int pos_y;
	int pos_x;
	int new_y;
	int new_x;
	t_textur *data;
}t_map;
// Textures!



int custom_error(char *msg, int exit_code);
int check_map_name(char *str);
int	check_map(char *file_name, t_map *data);
void    free_matrix(t_map *data);
int 	check_all_cases(t_map *data);
int 	effective_length(char *str);
int check_valid_character(t_map *data);
int validate_map_elements(t_map *data);
void    floodfill(char  **tab, int x, int y, t_map *data);
void    get_pos_of_player(t_map *mdata, t_sdata *data);
int validate_reachability(char **tab);
int    update_map(int key, t_map *data);
void	rendre_map(t_textur *data, t_map *mdata);
#endif