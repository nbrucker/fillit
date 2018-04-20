/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:36:07 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/08 13:41:50 by tgoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_tetro	*tetro;

	if (argc != 2)
		ft_error("usage: fillit source_file");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("error");
	tetro = ft_read_file(fd);
	if (close(fd) == -1)
		ft_error("error");
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error("error");
	ft_check_file(fd);
	if (close(fd) == -1)
		ft_error("error");
	ft_check_tetro(tetro);
	ft_cut_around(tetro);
	ft_fillit(tetro);
	return (0);
}
