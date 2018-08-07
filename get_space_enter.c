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

int get_space(char *ap, t_select *s_stuff)
{
    int         i;
    int         num;
    
    num = get_row_col(s_stuff);
    i = 0;
    s_stuff->selected[s_stuff->pos] = 1;
    clear_scr();
    while (i < num)
    {
        if (s_stuff->selected[i] == 1)
        {
            ft_printf("%s",tgetstr("so", &ap));
            ft_printf("%s", s_stuff->args[i]);
            ft_printf("%s",tgetstr("se", &ap));
            ft_printf(" ");
        }
        else
        {
            ft_printf("%s",tgetstr("se", &ap));
            ft_printf("%s", s_stuff->args[i]);
            ft_printf(" ");
        }
        i++;
    }
    return (1);
}
