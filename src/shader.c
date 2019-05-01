/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:07:31 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/01 19:10:09 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

GLuint		load_shader(t_string file, GLenum type)
{
	t_string	source;
	GLuint		shader;

	shader = glCreateShader(type);
	if (get_file_to_string(open(file, O_RDONLY), &source) < 0)
		exit_error(TITLE, "read shader source");
	glShaderSource(shader, 1, (const GLchar**)&source,
				(int[1]){ft_strlen(source)});
	glCompileShader(shader);
	free(source);
	return (shader);
}

t_programm	new_programm()
{
	const GLuint prog = glCreateProgram();
	const GLuint vertex_shader = load_shader("shaders/main.frag",
											GL_VERTEX_SHADER);

	glAttachShader(prog, vertex_shader);
	glLinkProgram(prog);
	glUseProgram(prog);
	return ((t_programm){prog, vertex_shader, -1, -1, -1, -1, -1});
}
