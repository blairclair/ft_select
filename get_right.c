/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:16:54 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/16 08:11:53 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	get_right(t_select *g_s_stuff)
{
	if (g_s_stuff->pos >= g_s_stuff->wc - 1 || g_s_stuff->pos < 0)
		g_s_stuff->pos = 0;
	else
		g_s_stuff->pos++;
	return (1);
}
