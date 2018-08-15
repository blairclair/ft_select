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
    else
        s_stuff->pos++;
    return (1);
}

