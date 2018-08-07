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
  //  int         col;
    int         num;

    num = get_row_col(s_stuff);
     printf("num: %d", num);
    i = 0;
    clear_scr();
    if (s_stuff->pos <= 0 || s_stuff->pos == 2000)
        s_stuff->pos = get_row_col(s_stuff) - 1;
    else
        s_stuff->pos--;
    while (i < num)
    {
        reprint_args(i, s_stuff, ap);
        i++;
    }
    return (1);
}