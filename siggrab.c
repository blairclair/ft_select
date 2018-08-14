/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   siggrab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:35:22 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/13 09:35:29 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void sighandle(int i)
{
    i++;
    rep2(&s_stuff);
}

void    sigrab()
{
    //signal(SIGINT, sighandle);
   // signal(SIGABRT, sighandle);
   // signal(SIGFPE, sighandle);
   // signal(SIGILL, sighandle);
   // signal(SIGINT, sighandle);
   // signal(SIGSEGV, sighandle);
  //  signal(SIGTERM, sighandle);
    signal(SIGWINCH, sighandle);
}
