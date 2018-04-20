/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:34:50 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/08 20:34:51 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_setgrid(t_tetro *tetro, int x, int y, t_grid *solve)
{
	int i;
	int j;

	i = 0;
	while (tetro->str[i])
	{
		j = 0;
		while (tetro->str[i][j])
		{
			if (tetro->str[i][j] == '#')
				solve->grid[y + i][x + j] = tetro->c;
			j++;
		}
		i++;
	}
}

int		ft_len(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
		i++;
	return (i);
}

char	**ft_save(char **grid)
{
	int		i;
	char	**save;

	if ((save = (char**)malloc(sizeof(char*) * (ft_len(grid) + 1))) == NULL)
		ft_error("error");
	i = 0;
	while (grid[i])
	{
		if ((save[i] = ft_strdup(grid[i])) == NULL)
			ft_error("error");
		i++;
	}
	save[i] = 0;
	return (save);
}

char	**ft_make_grid(int size)
{
	int		i;
	char	**grid;

	if ((grid = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		ft_error("error");
	i = 0;
	while (i < size)
	{
		if ((grid[i] = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
			ft_error("error");
		grid[i][size] = 0;
		ft_memset(grid[i], '.', size);
		i++;
	}
	grid[i] = 0;
	return (grid);
}
