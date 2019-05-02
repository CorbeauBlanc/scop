/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:26:32 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/02 16:23:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

GLfloat	*vtab_to_ftab(t_vector *vect, size_t size)
{
	GLfloat	*ret;
	size_t i;

	if (!(ret = (GLfloat*)malloc(3 * size * sizeof(GLfloat))))
		exit_error(TITLE, "malloc");
	i = 0;
	while (i < size)
	{
		ret[3 * i] = vect[i].x;
		ret[3 * i + 1] = vect[i].y;
		ret[3 * i + 2] = vect[i].z;
		++i;
	}
	return (ret);
}
