/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:05:52 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/02 17:22:40 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_error(char *prog, char *fct)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	perror(fct);
	exit(1);
}

void	exit_custom_error(char *prog, char *fct, char *err)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(fct, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(err, 2);
	write(2, "\n", 1);
	exit(1);
}
