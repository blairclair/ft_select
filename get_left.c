/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:13:06 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/06 16:13:07 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int get_left(char *ap, t_select *s_stuff)
{
    int         i;
    static int  numtimes = 0;
    int         col;
    int         j;

    i = 0;
    while (s_stuff->args[i])
        i++;
    i--;
    get_row_col(s_stuff);
    col = s_stuff->col_len - ft_strlen(s_stuff->args[i]);
    ft_printf("%s",tgoto(tgetstr("cm", &ap), col, 0));
    ft_printf("%s",tgetstr("us", &ap));
    ft_printf("%s", s_stuff->args[i]);
    if (numtimes != i)
    {
        j = i - numtimes;
        while (j < i)
        {
            ft_printf(s_stuff->args[j]);
            j++;
        }
    }
    numtimes++;
    return (1);
}