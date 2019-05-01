/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:22:08 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/01 17:55:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

GLuint	new_vector_vbo(t_vector *vectors, unsigned long nb_vectors)
{
	GLuint				vbo;
	GLfloat				**data;
	unsigned long		i;

	if (!(data = (GLfloat**)malloc(nb_vectors * sizeof(GLfloat*))))
		exit_error(TITLE, "malloc");
	i = -1;
	while (++i < nb_vectors)
		data[i] = vect_to_tab(vectors[i]);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, nb_vectors * 3 * sizeof(GLfloat), data,
				GL_STATIC_DRAW);
	i = -1;
	while (++i < nb_vectors)
		free(data[i]);
	free (data);
	return (vbo);
}

static void	add_vect_vbo(GLuint vbo)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(VECT_VBO_INDEX, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(VECT_VBO_INDEX);
}

t_vao		new_vao(t_vector *vectors, unsigned long nb_vectors)
{
	GLuint	vao;
	const GLuint	vect_vbo = new_vector_vbo(vectors, nb_vectors);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	add_vect_vbo(vect_vbo);
	return ((t_vao){vao, vect_vbo});
}

void		delete_vao(t_vao *vao, t_bool to_free)
{
	glDisableVertexAttribArray(VECT_VBO_INDEX);
	glDeleteBuffers(1, &vao->vect_vbo_id);
	glDeleteVertexArrays(1, &vao->id);
	if (to_free)
		free(vao);
}
