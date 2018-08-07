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

int     initialize_select(t_select *s_stuff, char **argv, int argc)
{
    int longest;
    int i;
    int j;
    static struct termios newterm;
    char    buf[1024];
    
    tgetent(buf, getenv("TERM"));
    tcgetattr(0, &newterm);
    newterm.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSANOW, &newterm);
    i = 1;
    j = 0;
    longest = get_longest_arg(argv);
    s_stuff->args = ft_memalloc(longest * sizeof(s_stuff) * (argc));
    while (i < argc)
    {
        s_stuff->args[j] = ft_memalloc(ft_strlen(argv[i]));
        s_stuff->args[j] = argv[i];
        i++;
        j++;
    }
    s_stuff->pos = 2000;
    i = 0;
    s_stuff->selected = ft_memalloc(sizeof(int) * argc + 1);
    while (s_stuff->selected[i])
    {
        s_stuff->selected[i] = 0;
        i++;
    }
    return (1);
}

int     read_input(t_select *s_stuff)
{
    unsigned int c;
    char buf[1024];
    char buf2[30];
    char    *ap;

    ap = buf2;
    print_select_args(s_stuff);
    tgetent(buf, getenv("TERM"));
    while (1)
    {
        read(0, &c, 5);
        if (c == LEFT)
            get_left(ap, s_stuff);
        else if (c == RIGHT)
            get_right(ap, s_stuff);
        else if (c == UP)
            ft_printf("up\n");
        else if (c == DOWN)
            ft_printf("down\n");
        else if (c == SPACE || c == SPACE2)
            get_space(ap, s_stuff);
        else
            {
                ft_printf("%ud\n", c);//delete before submit
                break ;
            }
    }
   tgetstr("ue", &ap);
    return (1);
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
    read_input(&s_stuff);
    return (0);
}
