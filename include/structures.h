/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/01 19:01:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# ifndef __APPLE__
#  include <SDL2/SDL.h>
#  include <GL/glew.h>
# else
#  include "SDL2/SDL.h"
# endif
# include <time.h>
# include <sys/timeb.h>

# include "libft.h"

typedef struct				s_color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
}							t_color;

typedef struct				s_sdl_core
{
	SDL_Window				*window;
	SDL_GLContext			*context;
	t_color					clearColor;
	int						width;
	int						height;
	int						nb_threads;
	int						fullscreen;
}							t_sdl_core;

typedef struct				s_event
{
	SDL_EventType			type;
	void					*data;
	int						(*callback)();
	struct s_event			*next;
}							t_event;

typedef struct				s_evt_data
{
	SDL_Keycode				keycode;
	int						(*second_callback)();
}							t_evt_data;

typedef struct				s_matrix
{
	double					**mat;
	int						r;
	int						c;
}							t_matrix;

typedef struct				s_la_norme_ce_putain_de_cancer
{
	t_matrix				*abcd[4];
	t_matrix				*r_abcd[4];
	t_matrix				*inv_a;
	t_matrix				*inv_d;
	t_matrix				*comp1;
	t_matrix				*comp2;
}							t_la_norme_ce_putain_de_cancer;

typedef struct				s_vector
{
	double					x;
	double					y;
	double					z;
}							t_vector;

typedef struct				s_vector t_dot;

typedef struct				s_trans_data
{
	t_dot					trans;
	t_dot					rot;
	t_dot					scale;
}							t_trans_data;

typedef struct				s_obj_material
{
	SDL_Color				color;
	SDL_Color				transparent_color;
	SDL_Surface				*texture;
	SDL_Surface				*normal_map;
	int						transparency;
	int						txt_repeat;
	int						map_repeat;
	double					txt_streching;
	double					map_streching;
	void					(*texture_mapping)(t_dot i, t_dot *textel,
												double streching,
												SDL_Surface *texture);
	void					(*map_mapping)(t_dot i, t_dot *textel,
											double streching,
											SDL_Surface *texture);
}							t_obj_material;

typedef struct				s_vector_vbo
{
	GLuint					buffer;
	int						nb_vectors;
}							t_vector_vbo;

typedef struct				s_vao
{
	GLuint					id;
	GLuint					vect_vbo_id;
}							t_vao;

typedef struct				s_programm
{
	GLuint					id;
	long					vertex_shader_id;
	long					tesselation1_shader_id;
	long					tesselation2_shader_id;
	long					geometry_shader_id;
	long					fragment_shader_id;
	long					compute_shader_id;
}							t_programm;

typedef struct				s_object
{
	t_dot					origin;
	t_matrix				*trans_const;
	t_matrix				*trans_iconst;
	t_matrix				*trans_idir;
	t_matrix				*trans_norm;
	t_obj_material			material;
}							t_object;

typedef struct				s_objs_comp
{
	t_dot					orig;
	t_obj_material			material;
	double					reflection_amount;
	double					refraction_amount;
	double					refractive_index;
	double					shininess;
}							t_objs_comp;

typedef enum				e_light_type
{
	OBJECT,
	ORB,
	PARALLEL,
	SPOT
}							t_light_type;

typedef struct				s_light_crd
{
	t_dot					orig;
	t_vector				direction;
}							t_light_crd;

typedef struct				s_light
{
	const t_light_type		type;
	SDL_Color				color;
	t_vector				direction;
	double					power;
}							t_light;

/*
** parallel_light hérite de light
*/
typedef struct				s_parallel_light
{
	const t_light_type		type;
	SDL_Color				color;
	t_vector				direction;
	double					power;
}							t_parallel_light;

/*
** spotlight hérite de light
*/
typedef struct				s_spotlight
{
	const t_light_type		type;
	SDL_Color				color;
	t_vector				direction;
	double					power;

	t_dot					orig;
	double					aperture;
}							t_spotlight;

/*
** orb_light hérite de spotlight
*/
typedef struct				s_orb_light
{
	const t_light_type		type;
	SDL_Color				color;
	t_vector				direction;
	double					power;

	t_dot					orig;
	double					aperture;
}							t_orb_light;

typedef struct				s_camera
{
	t_dot					origin;
	t_dot					angle;
	double					depth;
	double					focal;
	double					fov;
}							t_camera;

typedef struct				s_list_objs
{
	t_object				*obj;
	struct s_list_objs		*next;
}							t_list_objs;

typedef struct				s_list_lights
{
	t_light					*light;
	struct s_list_lights	*next;
}							t_list_lights;

typedef struct				s_scene
{
	double					brightness;
	t_camera				cam;
	t_list_lights			*lights;
	t_list_objs				*objects;
	SDL_Texture				*background;
}							t_scene;

#endif
