/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 08:42:54 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/16 08:56:57 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	reset_term(void)
{
	char	buf2[30];
	char	*ap;

	ap = buf2;
	tcsetattr(0, TCSANOW, &g_s_stuff.oldterm);
	ft_putstr_fd(tgetstr("ve", &ap), 0);
	ft_putstr_fd(tgetstr("te", &ap), 0);
}

int		choices(unsigned long c, t_select *g_s_stuff)
{
	if (c == LEFT)
		get_left(g_s_stuff);
	else if (c == RIGHT)
		get_right(g_s_stuff);
	else if (c == SPACE)
		get_space(g_s_stuff);
	else if (c == ESCAPE)
		return (-1);
	else if (c == DEL || c == DEL2)
		get_del(g_s_stuff);
	else if (c == ENTER1)
		get_enter(g_s_stuff);
	else
		return (1);
	return (0);
}

int		read_input(t_select *g_s_stuff)
{
	unsigned long	c;
	char			buf2[30];
	char			*ap;

	ap = buf2;
	while (1)
	{
		if (g_s_stuff->wc <= 0)
			return (1);
		rep2(g_s_stuff);
		c = 0;
		read(0, &c, 6);
		if (choices(c, g_s_stuff) == -1)
			return (1);
	}
	return (1);
}

int		first_step(void)
{
	char	*name;
	char	buf[1024];

	name = getenv("TERM");
	if (name == NULL)
	{
		ft_printf("no terminal name\n");
		return (0);
	}
	if (!tgetent(buf, name))
	{
		ft_printf("no terminfo\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	char	buf2[30];
	char	*ap;

	ap = buf2;
	sigrab();
	if (argc <= 1)
	{
		ft_printf("more args please\n");
		return (0);
	}
	if (!first_step())
		return (0);
	initialize_select(&g_s_stuff, argv, argc);
	read_input(&g_s_stuff);
	reset_term();
	return (0);
}
