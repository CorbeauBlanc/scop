/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:33 by edescoin          #+#    #+#             */
/*   Updated: 2019/04/30 22:17:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "structures.h"
# include "key_functions.h"
# ifndef __APPLE__
#  include <SDL2/SDL.h>
# else
#  include <SDL2/SDL.h>
# endif

/*
** events.c
*/
void		clear_events(t_event **head);
void		delete_event(t_event **head);
void		new_event(t_event **head, SDL_EventType type, void *data,
					int (*callback)());
t_evt_data	*new_evt_data(SDL_Keycode keycode, int (*second_callback)());
void		wait_events(t_event *list_evts);

#endif
