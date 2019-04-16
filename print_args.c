/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:34:57 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/16 08:52:36 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_select_and_pos(t_select *g_s_stuff, int i, char *ap)
{
	ft_putstr_fd(tgetstr("us", &ap), 0);
	ft_putstr_fd(tgetstr("so", &ap), 0);
	ft_putstr_fd(g_s_stuff->args[i], 0);
	ft_putstr_fd(tgetstr("se", &ap), 0);
	ft_putstr_fd(tgetstr("ue", &ap), 0);
}

void	print_choices(t_select *g_s_stuff, int i, char *ap, char *color)
{
	if (i == g_s_stuff->pos && g_s_stuff->selected[i] == 1)
		print_select_and_pos(g_s_stuff, i, ap);
	else if (i == g_s_stuff->pos && g_s_stuff->selected[i] == 0)
	{
		ft_putstr_fd(tgetstr("us", &ap), 0);
		ft_putstr_fd(g_s_stuff->args[i], 0);
		ft_putstr_fd(tgetstr("ue", &ap), 0);
	}
	else if (i != g_s_stuff->pos && g_s_stuff->selected[i] == 1)
	{
		ft_putstr_fd(tgetstr("so", &ap), 0);
		ft_putstr_fd(g_s_stuff->args[i], 0);
		ft_putstr_fd(tgetstr("se", &ap), 0);
	}
	else if (g_s_stuff->args[i] == NULL)
		return ;
	else
	{
		ft_putstr_fd(color, 0);
		ft_putstr_fd(g_s_stuff->args[i], 0);
		ft_putstr_fd(RESET, 0);
	}
}

void	reprint_args(int i, t_select *g_s_stuff)
{
	char		buf[30];
	char		*ps;
	char		*ap;
	char		*color;
	struct stat	statcheck;

	ap = buf;
	ps = tgetstr("cm", &ap);
	stat(g_s_stuff->args[i], &statcheck);
	if (S_ISDIR(statcheck.st_mode))
		color = GREEN;
	else if (statcheck.st_mode & S_IXUSR)
		color = RED;
	else
		color = BLUE;
	print_choices(g_s_stuff, i, ap, color);
	ft_putstr_fd(" ", 0);
}

int		check_lens(t_select *g_s_stuff, int row, int col, int i)
{
	if (g_s_stuff->row_len > row)
	{
		clear_scr();
		ft_putstr_fd("please expand window\n", 0);
		return (-1);
	}
	else if (g_s_stuff->col_len + (int)ft_strlen(g_s_stuff->args[i]) > col - 1)
	{
		ft_putstr_fd("\n", 0);
		g_s_stuff->row_len++;
		g_s_stuff->col_len = 0;
	}
	else
	{
		reprint_args(i, g_s_stuff);
		g_s_stuff->col_len += ft_strlen(g_s_stuff->args[i]) + 1;
		i++;
	}
	return (i);
}

void	rep2(t_select *g_s_stuff)
{
	int		col;
	char	buf[1024];
	int		row;
	int		i;

	tgetent(buf, getenv("TERM"));
	row = tgetnum("li");
	col = tgetnum("co");
	i = 0;
	g_s_stuff->col_len = 0;
	g_s_stuff->row_len = 1;
	clear_scr();
	while (i < g_s_stuff->wc)
	{
		i = check_lens(g_s_stuff, row, col, i);
		if (i == -1)
			break ;
	}
}
