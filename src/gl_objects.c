/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:22:08 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/02 18:31:18 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static GLuint	new_generic_vbo(GLfloat *data, size_t nb_emts, t_bool free_data)
{
	GLuint	vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, nb_emts * sizeof(GLfloat), data,
				GL_STATIC_DRAW);
	if (free_data)
		free(data);
	return (vbo);
}

static void	add_generic_vbo(GLuint vbo, GLuint index, GLint size)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(index);
}

GLuint	new_vector_vbo(t_vector *vectors, size_t nb_vectors)
{
	return (new_generic_vbo(vtab_to_ftab(vectors, nb_vectors), nb_vectors * 3,
			true));
}

GLuint	new_color_vbo(t_color *cols, size_t nb_colors)
{
	return (new_generic_vbo(ctab_to_ftab(cols, nb_colors), nb_colors * 4,
			true));
}

void	add_vector_vbo(GLuint vbo)
{
	add_generic_vbo(vbo, VECT_VBO_INDEX, 3);
}

void	add_color_vbo(GLuint vbo)
{
	add_generic_vbo(vbo, COL_VBO_INDEX, 4);
}

t_vao		new_vao(t_vector *vectors, size_t nb_vectors,
					t_color *colors, size_t nb_colors)
{
	GLuint	vao;
	const GLuint	vect_vbo = new_vector_vbo(vectors, nb_vectors);
	const GLuint	col_vbo = new_color_vbo(colors, nb_colors);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	add_vector_vbo(vect_vbo);
	add_color_vbo(col_vbo);
	return ((t_vao){vao, vect_vbo, col_vbo, nb_vectors, nb_colors});
}

void		draw_vao(t_vao vao)
{
	glDrawArrays(GL_TRIANGLES, 0, vao.nb_vectors);
}

void		delete_vao(t_vao *vao, t_bool to_free)
{
	glDisableVertexAttribArray(VECT_VBO_INDEX);
	glDisableVertexAttribArray(COL_VBO_INDEX);
	glDeleteBuffers(1, &vao->vect_vbo_id);
	glDeleteBuffers(1, &vao->col_vbo_id);
	glDeleteVertexArrays(1, &vao->id);
	if (to_free)
		free(vao);
}
