/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:07:31 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/02 17:29:38 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	check_shader_error(GLuint shader)
{
	int		success;
	char	error_log[512];

	bzero(error_log, 512);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, error_log);
		exit_custom_error(TITLE, "load_shader", error_log);
	}
}

GLuint		load_shader(t_string file, GLenum type)
{
	t_string	source;
	GLuint		shader;

	shader = glCreateShader(type);
	if (get_file_to_string(open(file, O_RDONLY), &source) < 0)
		exit_error(TITLE, "read shader source");
	glShaderSource(shader, 1, (const GLchar**)&source, NULL);
	glCompileShader(shader);
	check_shader_error(shader);
	free(source);
	return (shader);
}

t_programm	new_programm()
{
	const GLuint prog = glCreateProgram();
	const GLuint vertex_shader = load_shader("shaders/vertex_shader.vert",
											GL_VERTEX_SHADER);
	const GLuint fragment_shader = load_shader("shaders/fragment_shader.frag",
											GL_FRAGMENT_SHADER);

	glAttachShader(prog, vertex_shader);
	glAttachShader(prog, fragment_shader);
	glLinkProgram(prog);
	glUseProgram(prog);
	return ((t_programm){prog, vertex_shader, fragment_shader, -1, -1, -1, -1});
}
