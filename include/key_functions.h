/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:50:38 by edescoin          #+#    #+#             */
/*   Updated: 2019/04/30 22:09:07 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_FUNCTIONS_H
# define KEY_FUNCTIONS_H
# include "structures.h"

int	exit_loop();
int	key_management(SDL_Event *current, t_event *evt);

int	set_color(t_evt_data *data);

#endif
