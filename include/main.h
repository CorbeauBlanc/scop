/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 10:49:54 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/02 18:18:08 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# ifndef __APPLE__
#  include <SDL2/SDL.h>
#  include <GL/glew.h>
#  define SDL_VIDEO		SDL_INIT_VIDEO
#  define LINUX			1
# else
#  include "SDL2/SDL.h"
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_COCOA
#  define LINUX			0
# endif

# define TITLE			"scop"
# define POW			10000000000
# define LIMIT			100
# define WIN_WIDTH		1280
# define WIN_HEIGHT		700
# define DEBUG			1
# define LB				10000
# define VECT_VBO_INDEX 0
# define COL_VBO_INDEX 1

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <sys/timeb.h>

# include "camera.h"
# include "events.h"
# include "graphics.h"
# include "gl_objects.h"
# include "libft.h"
# include "matrix.h"
# include "rendering.h"
# include "shader.h"
# include "structures.h"
# include "vectors.h"

/*
**	utils.c
*/
int	eq(double nb1, double nb2);
int	ge(double nb1, double nb2);
int	gt(double nb1, double nb2);
int	le(double nb1, double nb2);
int	lt(double nb1, double nb2);

#endif
