/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoldber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:52:17 by tgoldber          #+#    #+#             */
/*   Updated: 2017/12/08 17:52:19 by tgoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_can(t_tetro *tetro, int x, int y, t_grid *solve)
{
	int i;
	int j;

	i = 0;
	while (tetro->str[i])
	{
		j = 0;
		while (tetro->str[i][j])
		{
			if (!solve->grid[y + i] || !solve->grid[y + i][x + j])
				return (0);
			if (solve->grid[y + i][x + j] != '.' && tetro->str[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_place(t_tetro *tetro, int *x, int *y, t_grid *solve)
{
	while (solve->grid[*y])
	{
		while (solve->grid[*y][*x])
		{
			if (ft_can(tetro, *x, *y, solve) == 1)
			{
				ft_setgrid(tetro, *x, *y, solve);
				return (1);
			}
			*x += 1;
		}
		*x = 0;
		*y += 1;
	}
	return (0);
}

int		ft_algo(t_tetro *tetro, t_grid *solve)
{
	int		x;
	int		y;
	char	**save;

	if (tetro == NULL)
		return (1);
	save = ft_save(solve->grid);
	x = 0;
	y = 0;
	while (ft_place(tetro, &x, &y, solve) == 1)
	{
		if (ft_algo(tetro->next, solve) == 1)
			return (1);
		solve->grid = ft_save(save);
		x++;
	}
	return (0);
}

void	ft_print_tab(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		ft_putendl(grid[i]);
		i++;
	}
}

void	ft_fillit(t_tetro *tetro)
{
	int		size;
	t_grid	solve;

	size = 2;
	while (1)
	{
		solve.grid = ft_make_grid(size);
		if (ft_algo(tetro, &solve) == 1)
			break ;
		size++;
	}
	ft_print_tab(solve.grid);
}
