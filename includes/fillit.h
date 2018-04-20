/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:32:21 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/08 09:32:21 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

typedef	struct	s_grid
{
	char **grid;
}				t_grid;

typedef struct	s_tetro
{
	char			c;
	char			**str;
	struct s_tetro	*next;
	struct s_tetro	*previous;
}				t_tetro;

t_tetro			*ft_read_file(int fd);
void			ft_check_file(int fd);
void			ft_check_line(char *str);
void			ft_check_tetro(t_tetro *tetro);
void			ft_cut_around(t_tetro *tetro);
void			ft_fillit(t_tetro *tetro);
void			ft_setgrid(t_tetro *tetro, int x, int y, t_grid *solve);
char			**ft_save(char **grid);
char			**ft_make_grid(int size);

#endif
