#ifndef GL_OBJECT_H
# define GL_OBJECT_H
# include "structures.h"

GLuint	new_vector_vbo(t_vector *vectors, unsigned long nb_vectors);
t_vao	new_vao(t_vector *vectors, unsigned long nb_vectors);
void	delete_vao(t_vao *vao, t_bool to_free);

#endif
