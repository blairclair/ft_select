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

    i = 0;
    longest = get_longest_arg(argv);
    s_stuff->args = ft_memalloc(longest * sizeof(s_stuff) * (argc - 1));
    while (i < argc - 1)
    {
        s_stuff->args[i] = ft_memalloc(ft_strlen(argv[i]) + 1);
        i++;
    }
    return (1);
}

int     read_input()
{
    unsigned int c;
    static struct termios oldterm, newterm;

    tcgetattr(STDIN_FILENO, &oldterm);
    newterm = oldterm;
    newterm.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
    while (1)
    {
        read(0, &c, 5);
        if (c == (unsigned)ft_atoi("4479771d"))
        {
            ft_printf("yay\n");
            break ;
        }
        ft_printf("c: %ud\n", c);
    }
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
    read_input();
    return (0);
}
