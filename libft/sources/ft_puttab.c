/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcecilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:30:17 by fcecilie          #+#    #+#             */
/*   Updated: 2017/01/09 18:25:46 by fcecilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	int n;

	n = 0;
	while (tab[n])
	{
		ft_putstr(tab[n]);
		ft_putchar('\n');
		n++;
	}
}
