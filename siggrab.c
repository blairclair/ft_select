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

void    siggon(int i)
{
    reset_term();
    i++;
    exit(0);
}
/*
void    sigz(int i)
{
 //   reset_term();
 //   char buf2[30];
   // char *ap;

    //ap = buf2;
    //tcsetattr(0, TCSANOW, &*s_stuff.oldterm);
    //ft_putstr_fd(tgetstr("ve", &ap), 0);
    //ft_putstr_fd(tgetstr("te", &ap), 0);
    signal(SIGTSTP, SIG_DFL);
    i++;
}*/

void    sigfg(int i)
{
   
    i++;
}

void    sigrab()
{
    signal(SIGINT, siggon);
    signal(SIGABRT, siggon);
    signal(SIGFPE, siggon);
    signal(SIGILL, siggon);
    signal(SIGINT, siggon);
    signal(SIGSEGV, siggon);
    signal(SIGTERM, siggon);
    signal(SIGWINCH, sighandle);
   // signal(SIGTSTP, sigz);
  //  signal(SIGTTOU, sigfg);
}
