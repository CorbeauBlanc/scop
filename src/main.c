/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:53:37 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/01 19:04:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <time.h>

int			force_exit(void)
{
	exit(1);
	return (0);
}

static void	init_list_evts(t_event **head)
{
	new_event(head, SDL_KEYUP, new_evt_data(SDLK_ESCAPE, &exit_loop),
			&key_management);
	new_event(head, SDL_KEYUP, new_evt_data(SDLK_r, &set_color),
			&key_management);
	new_event(head, SDL_KEYUP, new_evt_data(SDLK_g, &set_color),
			&key_management);
	new_event(head, SDL_KEYUP, new_evt_data(SDLK_b, &set_color),
			&key_management);
	new_event(head, SDL_QUIT, NULL, &force_exit);
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_event		*events;
	//t_scene		*scn;

	get_sdl_core();
	events = NULL;
/* 	if (!(scn = parsing(ac, av)))
		ft_putendl("usage : ./rt file.xml"); */

	t_vector square[4] =
	{
		{-0.5, 0.5, 0.5 },
		{ 0.5, 0.5, 0.5 },
		{ 0.5,-0.5, 0.5 },
		{-0.5,-0.5, 0.5 },
	};

	t_vao vao = new_vao(square, 4);

	t_programm prog = new_programm();
	(void)prog;

	init_list_evts(&events);
	refresh_window();
	wait_events(events);
	clear_events(&events);

	delete_vao(&vao, false);

	delete_sdl_core();

	exit(0);
}
