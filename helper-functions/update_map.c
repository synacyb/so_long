/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:42:43 by ayadouay          #+#    #+#             */
/*   Updated: 2025/03/07 21:52:45 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finish_game(t_map *data)
{
	if (data->map[data->new_y][data->new_x] == 'E')
	{
		if (data->check_c == data->c)
		{
			custom_error("u win");
			close_window(data);
			exit(0);
		}
	}
}

void	check_win(t_map *data)
{
	if (data->map[data->new_y][data->new_x] == 'C')
		data->check_c++;
	finish_game(data);
}

void	print_moves(t_map *data)
{
	if (data->map[data->new_y][data->new_x] == '0'
		|| data->map[data->new_y][data->new_x] == 'C')
	{
		data->moves++;
		ft_putstr_fd("moves :", 1);
		ft_putnbr_fd(data->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	if (data->map[data->new_y][data->new_x] == 'E')
	{
		if (data->check_c == data->c)
		{
			data->moves++;
			ft_putstr_fd("moves :", 1);
			ft_putnbr_fd(data->moves, 1);
			ft_putstr_fd("\n", 1);
		}
	}
}

void	edit_map(int keycode, t_map *data)
{
	if (keycode == 65307 || keycode == 17)
		close_window(data);
	if (keycode == 0xff51 || keycode == 97)
	{
		data->new_x -= 1;
		print_moves(data);
	}
	if (keycode == 0xff52 || keycode == 119)
	{
		data->new_y -= 1;
		print_moves(data);
	}
	if (keycode == 0xff53 || keycode == 100)
	{
		data->new_x += 1;
		print_moves(data);
	}
	if (keycode == 0xff54 || keycode == 115)
	{
		data->new_y += 1;
		print_moves(data);
	}
}

int	update_map(int keycode, t_map *data)
{
	data->new_x = data->pos_x;
	data->new_y = data->pos_y;
	edit_map(keycode, data);
	check_win(data);
	if (data->map[data->new_y][data->new_x] != '1'
		&& data->map[data->new_y][data->new_x] != 'E')
	{
		data->map[data->pos_y][data->pos_x] = '0';
		data->map[data->new_y][data->new_x] = 'P';
		data->pos_x = data->new_x;
		data->pos_y = data->new_y;
		rendre_map(data->data, data);
	}
	return (0);
}
