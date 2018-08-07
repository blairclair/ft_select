/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_enter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:32:21 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/07 08:32:24 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int get_del(char *ap, t_select *s_stuff)
{
    int i;
    int num;
    
    clear_scr();
    num = get_row_col(s_stuff);
    i = s_stuff->pos;
    s_stuff->args[i] = NULL;
    while (i < num)
    {
        s_stuff->args[i] = s_stuff->args[i + 1];
        i++;
    }
    i = 0;

    while (i < num)
    {
        reprint_args(i, s_stuff, ap);
        i++;
    }

    return (1);
}

int get_enter(t_select *s_stuff)
{
    int i;

    i = 0;
    while (s_stuff->args[i])
    {
        if (s_stuff->selected[i] == 1)
            ft_printf("%s\n", s_stuff->args[i]);
        i++;
    }
    return (1);
}

int get_space(char *ap, t_select *s_stuff)
{
    int         i;
    int         num;
    
    num = get_row_col(s_stuff);
    i = 0;
    clear_scr();
    if (s_stuff->selected[s_stuff->pos] == 0)
            s_stuff->selected[s_stuff->pos] = 1;
    else
        s_stuff->selected[s_stuff->pos] = 0;
     while (i < num)
    {
        reprint_args(i, s_stuff, ap);
        i++;
    }
    return (1);
}
