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

int get_right(t_select *s_stuff)
{
   
   
    if (s_stuff->pos >= g_wc - 1 || s_stuff->pos < 0)
        s_stuff->pos = 0;
  //  else if (g_collen + (int)ft_strlen(s_stuff->args[s_stuff->pos + 1]) >= col)
    //    clear_scr();   
    else
        s_stuff->pos++;
    return (1);
}

int get_down(t_select *s_stuff)
{
    if (s_stuff->pos >= g_wc - 1)
        s_stuff->pos -= (g_rowlen * s_stuff->wpc);
    else
        s_stuff->pos += s_stuff->wpc;
    return (1);    
}

int get_up(t_select *s_stuff)
{dgfxf//write get up function
    if (s_stuff->pos >= g_wc - 1)
        s_stuff->pos += (g_rowlen * s_stuff->wpc);
    else
        s_stuff->pos -= s_stuff->wpc;
    return (1);    
}
