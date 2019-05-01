/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:26:32 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/01 16:42:56 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

GLfloat	*vect_to_tab(t_vector vect)
{
	GLfloat	*ret;

	if (!(ret = (GLfloat*)malloc(3 * sizeof(GLfloat))))
		exit_error(TITLE, "malloc");
	ret[0] = vect.x;
	ret[1] = vect.y;
	ret[2] = vect.z;
	return (ret);
}
