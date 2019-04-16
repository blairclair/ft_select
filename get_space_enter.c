/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_enter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:32:21 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/16 08:15:38 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	get_del(t_select *g_s_stuff)
{
	int	i;

	i = g_s_stuff->pos;
	g_s_stuff->args[i] = NULL;
	g_s_stuff->selected[i] = '\0';
	while (i < g_s_stuff->wc)
	{
		g_s_stuff->args[i] = g_s_stuff->args[i + 1];
		g_s_stuff->selected[i] = g_s_stuff->selected[i + 1];
		i++;
	}
	g_s_stuff->wc--;
	if (g_s_stuff->pos > 0)
		g_s_stuff->pos--;
	return (1);
}

int	get_enter(t_select *g_s_stuff)
{
	int	i;

	i = 0;
	reset_term();
	while (g_s_stuff->args[i])
	{
		if (g_s_stuff->selected[i] == 1)
		{
			ft_printf("%s ", g_s_stuff->args[i]);
		}
		i++;
	}
	ft_printf("\n");
	exit(0);
}

int	get_space(t_select *g_s_stuff)
{
	if (g_s_stuff->selected[g_s_stuff->pos] == 0)
		g_s_stuff->selected[g_s_stuff->pos] = 1;
	else
		g_s_stuff->selected[g_s_stuff->pos] = 0;
	return (1);
}
