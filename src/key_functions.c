/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 22:12:52 by edescoin          #+#    #+#             */
/*   Updated: 2019/04/30 22:56:30 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	exit_loop()
{
	return (0);
}

int	set_color(t_evt_data *data)
{
	switch (data->keycode)
	{
		case SDLK_r:
			get_sdl_core()->clearColor = (t_color){1, 0, 0, 1};
		break;
		case SDLK_g:
			get_sdl_core()->clearColor = (t_color){0, 1, 0, 1};
		break;
		case SDLK_b:
			get_sdl_core()->clearColor = (t_color){0, 0, 1, 1};
		break;
	}
	refresh_window();
	return (1);
}

int	key_management(SDL_Event *current, t_event *evt)
{
	t_evt_data	*data;

	data = evt->data;
	if (current->key.keysym.sym == data->keycode)
		return (data->second_callback(data));
	return (-1);
}
