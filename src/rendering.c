/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:59:52 by shiro             #+#    #+#             */
/*   Updated: 2019/04/30 22:24:02 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	refresh_window()
{
	glClearColor(get_sdl_core()->clearColor.r, get_sdl_core()->clearColor.g,
				get_sdl_core()->clearColor.b, get_sdl_core()->clearColor.a);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(get_sdl_core()->window);
}
