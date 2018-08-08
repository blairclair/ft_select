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
    int         j;
    int         i;
    int         num;
    int         rn;

    num = get_row_col(s_stuff);
    i = 0;
    j = 0;
    rn = num / s_stuff->rn;
    clear_scr();
    if (s_stuff->pos <= 0 || s_stuff->pos == 2000)
        s_stuff->pos = get_row_col(s_stuff) - 1;
    else
        s_stuff->pos--;
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
            rn++;
            j++;
        }
    }
    return (1);
}