/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:43:00 by jaacosta          #+#    #+#             */
/*   Updated: 2024/11/11 19:57:07 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error");
		return (1);
	}
	printf("Lineas del Archivo: \n");
	line = get_next_line(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
