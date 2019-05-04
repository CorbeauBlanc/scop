/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:45:00 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/04 20:42:45 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		vect_normalize(t_vector *v)
{
	GLfloat	len;

	len = get_vect_lenght(v);
	*v = (t_vector){v->x / len, v->y / len, v->z / len, v->w};
}

GLfloat		angle_between_vectors(t_vector a, t_vector b)
{
	GLfloat	angle;
	GLfloat	pdt_scalaire;
	GLfloat	dist_a;
	GLfloat	dist_b;

	dist_a = get_vect_lenght(&a);
	dist_b = get_vect_lenght(&b);
	if (!(dist_a && dist_b))
		return (0);
	pdt_scalaire = vect_dot_product(a, b);
	angle = acos(pdt_scalaire / (dist_a * dist_b)) * 180 / M_PI;
	return (angle);
}

t_vector	vec3(GLfloat x, GLfloat y, GLfloat z)
{
	return ((t_vector){x, y, z, 1});
}

t_dot		dot(GLfloat x, GLfloat y, GLfloat z)
{
	return ((t_dot){x, y, z});
}

t_vector	v_inv(t_vector v)
{
	return ((t_vector){-v.x, -v.y, -v.z, v.w});
}
