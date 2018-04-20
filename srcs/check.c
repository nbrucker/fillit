/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoldber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:06:09 by tgoldber          #+#    #+#             */
/*   Updated: 2017/12/08 16:06:11 by tgoldber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		ft_check_file(int fd)
{
	char	*str;
	int		ret;
	char	buf[1000];
	int		i;

	str = ft_strnew(1);
	while ((ret = read(fd, buf, 999)) > 0)
	{
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
	}
	if (ret == -1)
		ft_error("error");
	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != '\n' || (str[i - 1] != '.' && str[i - 1] != '#'))
		ft_error("error");
}

void		ft_check_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			ft_error("error");
		i++;
	}
	if (i != 4)
		ft_error("error");
}

void		ft_reset(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'K')
				str[i][j] = '#';
			j++;
		}
		i++;
	}
}

int			ft_check_around(char **str, int i, int j, int first)
{
	int x;

	if (str[i][j] != '#')
		return (0);
	x = 1;
	str[i][j] = 'K';
	if (i != 0)
		x += ft_check_around(str, i - 1, j, 0);
	if (i != 3)
		x += ft_check_around(str, i + 1, j, 0);
	if (j != 0)
		x += ft_check_around(str, i, j - 1, 0);
	if (j != 3)
		x += ft_check_around(str, i, j + 1, 0);
	if (first == 1 && x != 4)
		ft_error("error");
	if (first == 1)
		ft_reset(str);
	return (x);
}

void		ft_check_tetro(t_tetro *tetro)
{
	int i;
	int j;
	int x;

	while (tetro)
	{
		i = 0;
		x = 0;
		while (tetro->str[i])
		{
			j = 0;
			while (tetro->str[i][j])
			{
				if (tetro->str[i][j] == '#')
					x++;
				ft_check_around(tetro->str, i, j, 1);
				j++;
			}
			i++;
		}
		if (x != 4)
			ft_error("error");
		tetro = tetro->next;
	}
}
