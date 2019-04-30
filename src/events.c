/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:21:27 by edescoin          #+#    #+#             */
/*   Updated: 2019/04/30 23:05:10 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		new_event(t_event **head, SDL_EventType type, void *data,
					int (*fct)())
{
	t_event	*event;

	if (!(event = malloc(sizeof(t_event))))
		exit_error(TITLE, "malloc");
	*event = (t_event){type, data, fct, *head};
	*head = event;
}

void		clear_events(t_event **head)
{
	t_event	*tmp;

	while (*head)
	{
		tmp = *head;
		free(tmp->data);
		*head = (*head)->next;
		free(tmp);
	}
}

t_evt_data	*new_evt_data(SDL_Keycode keycode, int (*second_callback)())
{
	t_evt_data	*data;

	if (!(data = malloc(sizeof(t_evt_data))))
		exit_error(TITLE, "malloc");
	data->keycode = keycode;
	data->second_callback = second_callback;
	return (data);
}

void		wait_events(t_event *list_evts)
{
	SDL_Event	evt;
	t_event		*tmp;
	int			flag;

	flag = 1;
	while (flag)
	{
		tmp = list_evts;
		SDL_WaitEvent(&evt);
		flag = -1;
		while (tmp && flag == -1)
		{
			if (tmp->type == evt.type)
				flag = tmp->callback(&evt, tmp);
			if (flag == -1)
				tmp = tmp->next;
		}
	}
}
