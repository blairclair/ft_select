/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:01:55 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/06 09:01:56 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void    clear_scr()
{
 
    char    buf2[30];
    char    *ap;
    char    *clearstr;
    
    ap = buf2;
   // tgetent(buf, getenv("TERM"));
    clearstr = tgetstr("cl", &ap);
    ft_printf("%s", clearstr);
}

int get_row_col(t_select *s_stuff)
{
    int i;

    i = 0;
    while (s_stuff->args[i])
        i++;
    s_stuff->col_len = 0;
    i = 0;
    while (s_stuff->args[i])
    {
        s_stuff->col_len += ft_strlen(s_stuff->args[i]);
        i++;
    }
    s_stuff->col_len += i;
    s_stuff->row_len = i;
    return (i);
}