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
    int     col;
    char    buf[1024];
    static int check = 0;
    int     row;
     char buf2[30];
    char    *ap;
    int     num;

    num = get_row_col(&s_stuff);
    ap = buf2;

    
    tgetent(buf, getenv("TERM"));
    row = tgetnum("li");
    col = tgetnum("co");
    if (g_rowlen > row)
    {
        clear_scr();
        ft_putstr_fd("please expand window\n", 0);
    }
    if (g_collen > col)
    {
        while (g_collen > col)
        {
            g_rowlen *= 2;
            g_collen /= 2;
          //  s_stuff->wc /= 2;
        }
        check = 1;
    }
    if (g_collen < col && check == 1)
    {
        while (g_collen < col)
        {
            g_collen *= 2;
            //s_stuff->wc *= 2;
            g_rowlen /=2;
        }
        check = 0;
    } 
  i++;
    rep2(&s_stuff, num, ap);
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
