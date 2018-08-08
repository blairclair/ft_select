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

    ps = tgetstr("cm", &ap);
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
    {
        //printf("weird: %s", s_stuff->args[i]);
        return ;
    }
    else
        ft_printf("%s", s_stuff->args[i]);
    ft_printf(" ");
}

void    rep2(t_select *s_stuff, int num, char *ap)
{
    int i;
    int j;
    int rn;

    rn = num / s_stuff->rn;
    j = 0;
    i = 0;
    if (s_stuff->rn == 1)
    {
        while (i < num)
        {
            reprint_args(i, s_stuff, ap);
            i++;
        }
    }
    else
    {
        while (j < s_stuff->rn)
        {
            while (i < rn)
            {
                reprint_args(i, s_stuff, ap);
                i++;
            }
            ft_printf("\n");
            rn *= 2;
            j++;
        }
    }
}