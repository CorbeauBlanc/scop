#ifndef SHADER_H
# define SHADER_H
# include "structures.h"

GLuint		load_shader(t_string file, GLenum type);
t_programm	new_programm();

#endif
