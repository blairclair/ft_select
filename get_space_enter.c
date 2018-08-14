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
    int         i;
    static int  num = 0;
    int         j;
    int         rn;
    
    num = get_row_col(s_stuff);
    if (num <= 0)
        return (0);
     j = 0;
    rn = num / g_rowlen;
    i = s_stuff->pos;
    s_stuff->args[i] = NULL;
    s_stuff->selected[i] = '\0';
    while (i < num)
    {
        s_stuff->args[i] = s_stuff->args[i + 1];
        s_stuff->selected[i] = s_stuff->selected[i + 1];
        i++;
    }
    num--;
    if (s_stuff->pos > 0)
        s_stuff->pos--;
    rep2(s_stuff, num, ap);
    return (1);
}

int get_enter(t_select *s_stuff)
{
    int i;

    i = 0;
    ft_printf("\n");
    while (s_stuff->args[i])
    {
        if (s_stuff->selected[i] == 1)
        {
            ft_printf("%s ", s_stuff->args[i]);
        }
        i++;
    }
    ft_printf("\n");
    return (1);
}

int get_space(char *ap, t_select *s_stuff)
{
    int         num;
    
    num = get_row_col(s_stuff);
    if (s_stuff->selected[s_stuff->pos] == 0)
            s_stuff->selected[s_stuff->pos] = 1;
    else
        s_stuff->selected[s_stuff->pos] = 0;
    rep2(s_stuff, num, ap);
    return (1);
}
