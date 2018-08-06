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
    static struct termios newterm;
    
    tcgetattr(0, &newterm);
    newterm.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSANOW, &newterm);
    i = 0;
    longest = get_longest_arg(argv);
    s_stuff->args = ft_memalloc(longest * sizeof(s_stuff) * (argc - 1));
    while (i < argc)
    {
        s_stuff->args[i] = ft_memalloc(ft_strlen(argv[i]) + 1);
        s_stuff->args[i] = argv[i];
        i++;
    }
    return (1);
}

int     read_input()
{
    unsigned int c;
    char buf[1024];

    tgetent(buf, getenv("TERM"));
    read(0, &c, 5);
    if (c == LEFT)
        ft_printf("left\n");
    else if (c == RIGHT)
        ft_printf("right\n");
    else if (c == UP)
        ft_printf("up\n");
    else if (c == DOWN)
        ft_printf("down\n");
    else
        ft_printf("c: %ud\n", c);
    return (1);
}
/*
int     get_term_info()
{
  
    char *ap;
    //char    *col;
  //  char    *pos;



   // col = tgetstr("cm", &ap);
  //  pos = tgoto(col, tgetnum("co"), 60);
   // ft_printf("%s", pos);
    return (1);
}*/

int    main(int argc, char *argv[])
{
    t_select s_stuff;

    if (argc <= 1)
    {
        ft_printf("more args please\n");
        return (0);
    }
    initialize_select(&s_stuff, argv, argc);
    print_select_args(&s_stuff);
  //  get_term_info();
    read_input();
    return (0);
}
