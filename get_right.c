/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:16:54 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/06 17:16:57 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int get_right(char *ap, t_select *s_stuff)
{
    int         i;
    int         num;
    int         rn;
    int         j;
    
    num = get_row_col(s_stuff);
    i = 0;
    j = 0;
    rn = num / s_stuff->rn;
    clear_scr();
    if (s_stuff->pos >= num - 1 || s_stuff->pos == 2000 || s_stuff->pos < 0)
        s_stuff->pos = 0;
    else
        s_stuff->pos++;
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
    return (1);
}
