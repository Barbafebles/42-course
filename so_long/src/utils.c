/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfebles- <bfebles-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 20:58:34 by bfebles-          #+#    #+#             */
/*   Updated: 2025/04/07 19:21:23 by bfebles-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(const char *msg)
{
	if (msg)
	{
		perror(msg);
	}
	perror("Error");
	exit(EXIT_FAILURE);
}
