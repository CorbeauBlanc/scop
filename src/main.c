/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:53:37 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/04 21:10:14 by edescoin         ###   ########.fr       */
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
	init_list_evts(&events);
/* 	if (!(scn = parsing(ac, av)))
		ft_putendl("usage : ./rt file.xml"); */

	t_programm p = new_programm();
	(void)p;

	t_vector vectors[3] =
	{
		{-1, -1, 0, 1},
		{1, -1, 0, 1},
		{0, 1, 0, 1}
	};

	t_color colors[3] =
	{
		{1, 0, 0, 1},
		{0, 1, 0, 1},
		{0, 0, 1, 1},
	};

	t_matrix *mat_model = create_identity(4);
	t_matrix *mat_cam = create_identity(4);

	t_vector cam_pos = vec3(0, 2, -3);
	t_vector cam_target = vec3(0, 0, 0);
	t_vector cam_dir = vec3(cam_pos.x - cam_target.x,
						cam_pos.y - cam_target.y,
						cam_pos.z - cam_target.z);

	t_vector wld_up = vec3(0, 1, 0);
	t_vector cam_right = vect_cross_product(wld_up, cam_dir);
	vect_normalize(&cam_right);
	t_vector cam_up = vect_cross_product(cam_dir, cam_right);

	mat_cam->mat[0][0] = cam_right.x;
	mat_cam->mat[0][1] = cam_right.y;
	mat_cam->mat[0][2] = cam_right.z;
	mat_cam->mat[1][0] = cam_up.x;
	mat_cam->mat[1][1] = cam_up.y;
	mat_cam->mat[1][2] = cam_up.z;
	mat_cam->mat[2][0] = cam_dir.x;
	mat_cam->mat[2][1] = cam_dir.y;
	mat_cam->mat[2][2] = cam_dir.z;
	mat_cam->mat[0][3] = -cam_pos.x;
	mat_cam->mat[1][3] = -cam_pos.y;
	mat_cam->mat[2][3] = -cam_pos.z;


	t_matrix *proj_mat = create_identity(4);
	proj_mat->mat[3][2] = 1;
	proj_mat->mat[3][3] = 0;

	scale(&mat_model, 1, 1, 1);
	x_rotation(&mat_model, 0);
	y_rotation(&mat_model, 0);
	z_rotation(&mat_model, 0);
	translation(&mat_model, 0, 0, 0);

	t_matrix *res = NULL;
	mult_matrix(&res, proj_mat, mat_cam);

	t_matrix *res2 = NULL;
	mult_matrix(&res2, mat_model, res);

	mult_vect(&vectors[0], res2, &vectors[0]);
	mult_vect(&vectors[1], res2, &vectors[1]);
	mult_vect(&vectors[2], res2, &vectors[2]);

	vect_normalize(&vectors[0]);
	vect_normalize(&vectors[1]);
	vect_normalize(&vectors[2]);

	t_vao vao = new_vao(vectors, 3, colors, 3);

	draw_vao(vao);
	refresh_window();

	wait_events(events);
	clear_events(&events);

	delete_vao(&vao, false);

	delete_sdl_core();

	exit(0);
}
