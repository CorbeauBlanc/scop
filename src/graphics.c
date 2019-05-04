/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/04 17:46:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			set_gl_attributes()
{
	return (SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
								SDL_GL_CONTEXT_PROFILE_CORE) ||
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4) ||
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5) ||
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1));
}

void		init_glew()
{
	if (LINUX)
	{
		glewExperimental = GL_TRUE;
		glewInit();
	}
}

t_sdl_core	*get_sdl_core(void)
{
	static t_sdl_core	*core = NULL;

	if (core)
		return (core);
	if (!(core = malloc(sizeof(t_sdl_core))))
		exit_error(TITLE, "malloc");
	*core = (t_sdl_core){NULL, NULL, (t_color){0, 0, 0, 1}, WIN_WIDTH,
						WIN_HEIGHT, 0, 0};
	if (SDL_Init(SDL_VIDEO) || set_gl_attributes() ||
		!(core->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										WIN_WIDTH, WIN_HEIGHT,
										SDL_WINDOW_OPENGL)) ||
		!(core->context = SDL_GL_CreateContext(core->window)))
		exit_custom_error("SDL2: ", "get_sdl_core", (char*)SDL_GetError());
	init_glew();
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
	return (core);
}

void		delete_sdl_core(void)
{
	SDL_GL_DeleteContext(get_sdl_core()->context);
	SDL_DestroyWindow(get_sdl_core()->window);
	SDL_Quit();
	free(get_sdl_core());
}

GLfloat	*ctab_to_ftab(t_color *cols, size_t size)
{
	GLfloat	*ret;
	size_t	i;

	if (!(ret = (GLfloat*)malloc(4 * size * sizeof(GLfloat))))
		exit_error(TITLE, "malloc");
	i = 0;
	while (i < size)
	{
		ret[4 * i] = cols[i].r;
		ret[4 * i + 1] = cols[i].g;
		ret[4 * i + 2] = cols[i].b;
		ret[4 * i + 3] = cols[i].a;
		++i;
	}
	return (ret);
}
