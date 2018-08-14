/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 08:42:54 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/06 08:42:55 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int     get_longest_arg(char **argv)
{
    int i;
    int num;

    num = 0;
    i = 0;
    while (argv[i])
    {
        if ((int)ft_strlen(argv[i]) > num)
        {
            num = ft_strlen(argv[i]);
        }
        i++;
    }
    return (num);
}

void    initialize_s_stuff(t_select *s_stuff, int longest, int argc)
{
    g_collen = 0;
    s_stuff->pos = 0;
    s_stuff->selected = ft_memalloc(sizeof(int) * argc + 1);
    s_stuff->args = ft_memalloc(longest * sizeof(s_stuff) * (argc));
    g_rowlen = 1;
    g_wc = 0;
}

int     initialize_select(t_select *s_stuff, char **argv, int argc)
{
    int longest;
    int i;
    int j;
    static struct termios newterm;
    char    buf[1024];
    
    i = 1;
    j = 0;
    g_collen = 0;
    g_rowlen = 1;
    longest = get_longest_arg(argv);
    tgetent(buf, getenv("TERM"));
    tcgetattr(0, s_stuff->oldterm);
    tcgetattr(0, &newterm);
    newterm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newterm);
    initialize_s_stuff(s_stuff, get_longest_arg(argv), argc);
    while (i < argc)
    {
      //  s_stuff->args[j] = ft_memalloc(ft_strlen(argv[i]));
        s_stuff->args[j] = argv[i];
        g_collen += ft_strlen(s_stuff->args[j]);
        s_stuff->selected[j] = 0;
        i++;
        j++;
        g_wc++;
    }
    return (1);
}

int     read_input(t_select *s_stuff)
{
    unsigned long c;
    char buf2[30];
    char    *ap;
    int     num;

    num = get_row_col(s_stuff);
    ap = buf2;
    while (1)
    {
        sigrab();
        rep2(s_stuff, ap);
        c = 0;
        read(STDERR_FILENO, &c, 6);
        if (c == LEFT)
            get_left(s_stuff);
        else if (c == RIGHT)
            get_right(s_stuff);
        else if (c == SPACE)
            get_space(s_stuff);
        else if (c == ESCAPE)
            break ;
        else if (c == 0 || c == DEL || c== DEL2)
        {
            if (get_del(s_stuff) == 0)
                return (1);
        }
        else if (c == ENTER1)
        {
            get_enter(s_stuff);
            break ;
        }
           else
            continue;
        clear_scr();
    }
    tgetstr("ue", &ap);
    return (1);
}


int    main(int argc, char *argv[])
{
    sigrab();
    if (argc <= 1)
    {
        ft_printf("more args please\n");
        return (0);
    }
    initialize_select(&s_stuff, argv, argc);
    read_input(&s_stuff);
    tcsetattr(0, TCSANOW, &*s_stuff.oldterm);
    return (0);
}
