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


void reprint_args(int i, t_select *s_stuff, char *ap)
{
    char    *ps;

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
        //ft_putstr_fd("weird: %s", s_stuff->args[i]);
        return ;
    }
    else
        ft_putstr_fd(s_stuff->args[i], 0);
    ft_putstr_fd(" ", 0);
}

void    rep2(t_select *s_stuff, int num, char *ap)
{
    int i;
    int j;
    int arg;
    int row;

    //check_size(s_stuff);
    clear_scr();
    row = tgetnum("li");
    arg = 0;
    j = 0;
    i = 0;
    if (g_rowlen > row)
    {
        ft_putstr_fd("please expand window\n", 0);
        return ;
    }
    if (g_rowlen == 1)
    {
        while (i < num)
        {
            reprint_args(i, s_stuff, ap);
            i++;
        }
    }
    else
    {
        while (j < g_rowlen)
        {
            i = 0;
            while (i < s_stuff->wc)
            {
                reprint_args(arg, s_stuff, ap);
                i++;
                arg++;
            }
            ft_putstr_fd("\n", 0);
            j++;
        }
    }
}
