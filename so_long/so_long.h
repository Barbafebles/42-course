/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbafebles <barbafebles@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 07:52:20 by bfebles-          #+#    #+#             */
/*   Updated: 2024/04/06 14:04:33 by barbafebles      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// // # include "ft_printf.h"
// # include "get_next_line.h"
// # include "libft.h"
# include <fcntl.h> // file control ( entrada/ salida)
# include <limits.h> // limite de numeros INT_MAX INT_MIN (compromaciones de desbordamiento)
# include <mlx.h>    // interfaz grafica MiniLibX 
# include <stdlib.h> // Standar library memoria dinamica 
#endif

typedef struct s_player
{
    int x;
    int y;
    void *img;
}              t_player;

typedef struct s_win
{
    int width;
    int height;
    void *window;
}              t_win;

typedef struct s_data
{
    void *mlx;
    t_player player;
    t_win    win;
    void *imgsuelo;
    void *galleta;
}              t_data;
