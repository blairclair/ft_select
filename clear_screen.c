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

void    clear_str()
{
    char    buf[1024];
    char    buf2[30];
    char    *ap;
    char    *clearstr;
    
    ap = buf2;
    tgetent(buf, getenv("TERM"));
    clearstr = tgetstr("cl", &ap);
    ft_printf("%s", clearstr);
}
