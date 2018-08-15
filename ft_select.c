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
#define RED   "\x1B[31m"
#define RESET "\x1B[0m"

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
    char    buf2[30];
    char    *ap;
    
    ap = buf2;
    longest = get_longest_arg(argv);
    i = 1;
    j = 0;
    g_collen = 0;
    g_rowlen = 1;
    g_wc = 0;
    s_stuff->pos = 0;
    s_stuff->wpc = 0;
    s_stuff->selected = ft_memalloc(sizeof(int) * argc + 1);
    s_stuff->args = ft_memalloc(longest * sizeof(s_stuff) * (argc));
    tgetent(buf, getenv("TERM"));
    tcgetattr(0, s_stuff->oldterm);
    tcgetattr(0, &newterm);
    newterm.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newterm);
    ft_putstr_fd(tgetstr("vi", &ap), 0);
    ft_putstr_fd(tgetstr("ti", &ap), 0);
    while (i < argc)
    {
        s_stuff->args[j] = argv[i];
        s_stuff->selected[j] = 0;
        i++;
        j++;
        g_wc++;
    }
    return (1);
}

void    reset_term()
{
    char buf2[30];
    char *ap;

    ap = buf2;
    tcsetattr(0, TCSANOW, &*s_stuff.oldterm);
    ft_putstr_fd(tgetstr("ve", &ap), 0);
    ft_putstr_fd(tgetstr("te", &ap), 0);
    clear_scr();
}

int     read_input(t_select *s_stuff)
{
    unsigned long c;
    char buf2[30];
    char    *ap;

    ap = buf2;
    while (1)
    {
 
        rep2(s_stuff);
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
            reset_term();
            get_enter(s_stuff);
            exit(0);
        }
           else
            continue;
    }
    return (1);
}

int     first_step()
{
    char *name;
	char	buf[1024];

    name = getenv("TERM");
    if (name == NULL)
    {
        ft_printf("no terminal name\n");
        return (0);
    }
    if (!tgetent(buf, name))
    {
         ft_printf("no terminfo\n");
        return (0);
    }
    return (1);
}

int    main(int argc, char *argv[])
{
    char buf2[30];
    char *ap;

    ap = buf2;
    sigrab();
    if (argc <= 1)
    {
        ft_printf("more args please\n");
        return (0);
    }
    if (!first_step())
        return (0);
    initialize_select(&s_stuff, argv, argc);
    read_input(&s_stuff);
    

    return (0);
}
