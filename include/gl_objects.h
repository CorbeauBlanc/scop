#ifndef GL_OBJECT_H
# define GL_OBJECT_H
# include "structures.h"

t_vao	new_vao(t_vector *vectors, size_t nb_vectors,
				t_color *colors, size_t nb_colors);
void	delete_vao(t_vao *vao, t_bool to_free);
void	draw_vao(t_vao vao);

#endif
