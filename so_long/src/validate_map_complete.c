/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_complete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:49:56 by bfebles-          #+#    #+#             */
/*   Updated: 2025/05/06 18:49:32 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_map_complete(t_map *map)
{
	check_empty_map(map);
	check_map_size(map);
	check_recta(map);
	check_wall(map);
	check_map(map);
	check_map_char(map);
	save_exit_position(map);
	if (!check_path(map))
		ft_error("There is no valid way to complete the level");
}
