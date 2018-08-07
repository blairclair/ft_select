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
    int         col;
    int         num;
    
    num = get_row_col(s_stuff);
    i = 0;
    clear_scr();
    if (s_stuff->pos > num - 1|| s_stuff->pos == 2000 || s_stuff->pos < 0)
        s_stuff->pos = 0;
    ft_printf("pos: %d\n", s_stuff->pos);
    col = s_stuff->col_len - ft_strlen(s_stuff->args[i]);
    ft_printf("%s",tgoto(tgetstr("cm", &ap), col, 0));  
    while (i < num)
    {
        if (i == s_stuff->pos)
             ft_printf("%s",tgetstr("us", &ap));
        else
            ft_printf("%s",tgetstr("ue", &ap));
        ft_printf(s_stuff->args[i]);
        i++;
    }
    s_stuff->pos++;
    return (1);
}