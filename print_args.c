/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:34:57 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/06 10:34:59 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


void reprint_args(int i, t_select *s_stuff)
{
    char    *ps;
    char    *ap;

    ap = ft_memalloc(30);
    ps = tgetstr("cm", &ap);
    if (i == s_stuff->pos && s_stuff->selected[i] == 1)
    {
        ft_putstr_fd(tgetstr("us", &ap), 0);
        ft_putstr_fd(tgetstr("so", &ap), 0);
        ft_putstr_fd(s_stuff->args[i], 0);
        ft_putstr_fd(tgetstr("se", &ap), 0);
        ft_putstr_fd(tgetstr("ue", &ap), 0);
    }
    else if (i == s_stuff->pos && s_stuff->selected[i] == 0)
    {
        ft_putstr_fd(tgetstr("us", &ap), 0);
        ft_putstr_fd(s_stuff->args[i], 0);
        ft_putstr_fd(tgetstr("ue", &ap), 0);
    }
    else if (i != s_stuff->pos && s_stuff->selected[i] == 1)
    {
        ft_putstr_fd(tgetstr("so", &ap), 0);
        ft_putstr_fd(s_stuff->args[i], 0);
        ft_putstr_fd(tgetstr("se", &ap), 0);
    }
    else if (s_stuff->args[i] == NULL)
    {
        return ;
    }
    else
        ft_putstr_fd(s_stuff->args[i], 0);
    ft_putstr_fd(" ", 0);
}

void    rep2(t_select *s_stuff)
{
    int     col;
    char    buf[1024];
    int     row;
    int     i;

    tgetent(buf, getenv("TERM"));
    row = tgetnum("li");
    col = tgetnum("co");
    i = 0;
    g_collen = 0;
    g_rowlen = 1;
    clear_scr();
    while (i < g_wc)
    {
         if (g_rowlen > row)
        {
            clear_scr();
            ft_putstr_fd("please expand window\n", 0);
        }
        if (g_collen + (int)ft_strlen(s_stuff->args[i]) > col)
        {
            ft_putchar_fd('\n', 0);
            g_rowlen++;
            g_collen = 0;
        }
        else
        {
            reprint_args(i, s_stuff);
            g_collen += ft_strlen(s_stuff->args[i]);
        }
        i++;
    }
}
