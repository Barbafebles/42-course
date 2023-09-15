/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbarafebles <barbarafebles@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:46:09 by bfebles-          #+#    #+#             */
/*   Updated: 2023/09/14 18:52:29 by barbarafebl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_validmap(const char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = malloc(sizeof(char) * BUFFER_SIZE);
		i = get_next_line(fd, line);
		if (i == -1)
			return (0);
		if (i == 0)
			break;
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}

int	main(char arg, char *argv[])
{
	char	**maps;
	int		fd;

	if (arg == 2)
	{
		if (ft_validmap(argv[1]))
		{
			fd = open(argv[1], O_RDONLY);
			maps = ft_readmaps(fd);
			while (*maps != NULL)
			{
				ft_printf("%s\n", *maps);
				maps++;
			}
			close(fd);
		}
		return (0);
	}
	return(0);
}
*/
