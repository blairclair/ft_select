/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:02:50 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/16 12:02:56 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		gla(char **argv)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (argv[i])
	{
		if ((int)ft_strlen(argv[i]) > num)
		{
			num = ft_strlen(argv[i]);
		}
		i++;
	}
	return (num);
}

void	set_environ(void)
{
	static struct termios	newterm;
	char					buf[1024];
	char					buf2[30];
	char					*ap;

	ap = buf2;
	tgetent(buf, getenv("TERM"));
	tcgetattr(0, &*g_s_stuff.oldterm);
	tcgetattr(0, &newterm);
	newterm.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &newterm);
	ft_putstr_fd(tgetstr("vi", &ap), 0);
	ft_putstr_fd(tgetstr("ti", &ap), 0);
}

int		initialize_select(t_select *g_s_stuff, char **argv, int argc)
{
	int		i;
	int		j;
	char	buf2[30];
	char	*ap;

	ap = buf2;
	i = 1;
	j = 0;
	g_s_stuff->col_len = 0;
	g_s_stuff->row_len = 1;
	g_s_stuff->wc = 0;
	g_s_stuff->pos = 0;
	g_s_stuff->wpc = 0;
	g_s_stuff->selected = ft_memalloc(sizeof(int) * argc + 1);
	g_s_stuff->args = ft_memalloc(gla(argv) * sizeof(g_s_stuff) * (argc));
	set_environ();
	while (i < argc)
	{
		g_s_stuff->args[j] = argv[i];
		g_s_stuff->selected[j] = 0;
		i++;
		j++;
		g_s_stuff->wc++;
	}
	return (1);
}
