/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:53:37 by edescoin          #+#    #+#             */
/*   Updated: 2019/04/30 22:38:52 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <time.h>

int		force_exit(void)
{
	exit(1);
	return (0);
}

void	init_list_evts(t_event **head)
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

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_event		*events;
	//t_scene		*scn;

	events = NULL;
/* 	if (!(scn = parsing(ac, av)))
		ft_putendl("usage : ./rt file.xml"); */

	get_sdl_core();
	init_list_evts(&events);
	refresh_window();
	wait_events(events);
	clear_events(&events);
	delete_sdl_core();

	exit(0);
}
