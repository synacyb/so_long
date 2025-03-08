CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
M_SRC = helper-functions/check_all_cases.c helper-functions/check_fl_colums.c helper-functions/check_map_name.c helper-functions/check_map.c helper-functions/custom_error.c \
		helper-functions/effective_length.c helper-functions/floodfill.c helper-functions/free_matrix.c helper-functions/get_pose_player.c helper-functions/img_to_win.c \
		helper-functions/set_img.c helper-functions/update_map.c helper-functions/set_map.c helper-functions/validate_map_elements.c helper-functions/validate_reachability.c get_next_line/get_next_line.c \
		so_long.c

M_OBJ = $(M_SRC:.c=.o)
NAME = so_long
MLXFLAGS = -lmlx -lXext -lX11
DELETE = rm -f

all: $(NAME) 

$(NAME): $(M_OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(M_OBJ) $(LIBFTDIR)/libft.a $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	$(DELETE) $(M_OBJ)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(DELETE) $(NAME) $(M_OBJ)

re: fclean all

.PHONY: all clean fclean re