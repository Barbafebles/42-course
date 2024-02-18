/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:23:55 by bfebles-          #+#    #+#             */
/*   Updated: 2023/06/14 15:37:54 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_player
{
    int x;
    int y;
    void *img;
}              t_player;

typedef struct s_win
{
    int wi;
    int height;
    void *ptr_win;
}              t_win;

typedef struct s_data
{
    void *mlx;
    t_player player;
    t_win    win;
}              t_data;
