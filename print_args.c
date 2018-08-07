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

void    print_select_args(t_select *s_stuff)
{
    int i;

    i = 0;
    while (s_stuff->args[i])
    {
        ft_printf("%s ", s_stuff->args[i]);
        i++;
    }
}

void reprint_args(int i, t_select *s_stuff, char *ap)
{
    char    *ps;
   // int     ln;
  //  static int  lpos = 0;

    ps = tgetstr("cm", &ap);
//    tputs(tgoto(ps, lpos, 4), 1, putchar);
    if (i == s_stuff->pos && s_stuff->selected[i] == 1)
    {
        ft_printf("%s",tgetstr("us", &ap));
        ft_printf("%s",tgetstr("so", &ap));
        ft_printf("%s", s_stuff->args[i]);
        ft_printf("%s",tgetstr("se", &ap));
        ft_printf("%s",tgetstr("ue", &ap));
    }
    else if (i == s_stuff->pos && s_stuff->selected[i] == 0)
    {
        ft_printf("%s",tgetstr("us", &ap));
        ft_printf("%s", s_stuff->args[i]);
        ft_printf("%s",tgetstr("ue", &ap));
    }
    else if (i != s_stuff->pos && s_stuff->selected[i] == 1)
    {
        ft_printf("%s",tgetstr("so", &ap));
        ft_printf("%s", s_stuff->args[i]);
        ft_printf("%s",tgetstr("se", &ap));
    }
    else if (s_stuff->args[i] == NULL)
        ;
    else
        ft_printf("%s", s_stuff->args[i]);
    ft_printf(" ");
}