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
    s_stuff->col_len = 0;
    s_stuff->pos = 0;
    s_stuff->selected = ft_memalloc(sizeof(int) * argc + 1);
    s_stuff->args = ft_memalloc(longest * sizeof(s_stuff) * (argc));
    s_stuff->rn = 1;
    s_stuff->wc = 0;
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
    longest = get_longest_arg(argv);
    tgetent(buf, getenv("TERM"));
    tcgetattr(0, &newterm);
    newterm.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSANOW, &newterm);
    initialize_s_stuff(s_stuff, longest, argc);
    while (i < argc)
    {
        s_stuff->args[j] = ft_memalloc(ft_strlen(argv[i]));
        s_stuff->args[j] = argv[i];
        s_stuff->col_len += ft_strlen(s_stuff->args[j]);
        s_stuff->selected[j] = 0;
        i++;
        j++;
        s_stuff->wc++;
    }
    return (1);
}


int     read_input(t_select *s_stuff)
{
    unsigned long c;
    char buf[1024];
    char buf2[30];
    char    *ap;
    int     num;
    
    num = get_row_col(s_stuff);
    ap = buf2;
    rep2(s_stuff, num, ap);
    tgetent(buf, getenv("TERM"));
    while (c = 0, (read(0, &c, 6)) != 0)
    {
        if (c == LEFT)
            get_left(ap, s_stuff);
        else if (c == RIGHT)
            get_right(ap, s_stuff);
        else if (c == UP)
            ft_printf("up\n");
        else if (c == DOWN)
            ft_printf("down\n");
        else if (c == SPACE)
            get_space(ap, s_stuff);
        else if (c == ESCAPE)
            break ;
        else if (c == 0 || c == DEL || c== DEL2)
        {
            if (get_del(ap, s_stuff) == 0)
                return (1);
        }
        else if (c == ENTER1)
        {
            get_enter(s_stuff);
            break ;
        }
        else
            break ;
    }
    tgetstr("ue", &ap);
    return (1);
}

int    check_size(t_select *s_stuff)
{
    int     col;
    char    buf[1024];
    static int check = 0;

    tgetent(buf, getenv("TERM"));
    col = tgetnum("co");
    if (s_stuff->col_len > col)
    {
        while (s_stuff->col_len > col)
        {
            s_stuff->rn *= 2;
            s_stuff->col_len /= 2;
            s_stuff->wc /= 2;
        }
        check = 1;
    }
    if (s_stuff->col_len < col && check == 1)
    {
        while (s_stuff->col_len < col)
        {
            s_stuff->col_len *= 2;
            s_stuff->wc *= 2;
            s_stuff->rn /=2;
        }
        check = 0;
    }
    return (col);
}

int    main(int argc, char *argv[])
{
    t_select s_stuff;

    if (argc <= 1)
    {
        ft_printf("more args please\n");
        return (0);
    }
    initialize_select(&s_stuff, argv, argc);
    clear_scr();
    check_size(&s_stuff);
    read_input(&s_stuff);
    printf("rn: %d\n", s_stuff.rn);
    printf("row: %d\n", tgetnum("li"));
    printf("col: %d\n", s_stuff.col_len);
    return (0);
}
