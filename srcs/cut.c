/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoldber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:51:46 by tgoldber          #+#    #+#             */
/*   Updated: 2017/12/08 16:51:47 by tgoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_cut_colonne(char **str, int i)
{
	while (str[0][i])
	{
		str[0][i] = str[0][i + 1];
		str[1][i] = str[1][i + 1];
		str[2][i] = str[2][i + 1];
		str[3][i] = str[3][i + 1];
		i++;
	}
}

void	ft_cut_ligne(char **str, int i)
{
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
}

void	ft_cut_around(t_tetro *tetro)
{
	int i;

	while (tetro)
	{
		i = 0;
		while (tetro->str[0][i])
		{
			if (tetro->str[0][i] != '#' && tetro->str[1][i] != '#' &&
				tetro->str[2][i] != '#' && tetro->str[3][i] != '#')
				ft_cut_colonne(tetro->str, i);
			else
				i++;
		}
		i = 0;
		while (tetro->str[i])
		{
			if (tetro->str[i][0] != '#' && tetro->str[i][1] != '#' &&
				tetro->str[i][2] != '#' && tetro->str[i][3] != '#')
				ft_cut_ligne(tetro->str, i);
			else
				i++;
		}
		tetro = tetro->next;
	}
}
