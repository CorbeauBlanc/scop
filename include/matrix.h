/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:42 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/02 19:18:34 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "structures.h"

/*
** matrix.c
*/
void		clear_matrix(t_matrix *mat);
t_matrix	*copy_matrix(t_matrix *dst, t_matrix *src);
t_matrix	*create_identity(int i);
t_matrix	*new_matrix(GLfloat **mat, int r, int c);
void		delete_matrix(t_matrix *matrix);
t_matrix	*mult_matrix(t_matrix **res, t_matrix *m1, t_matrix *m2);

/*
** matrix_ops.c
*/
t_matrix	*sub_matrix(t_matrix **res, t_matrix *m1, t_matrix *m2);
t_matrix	*add_matrix(t_matrix **res, t_matrix *m1, t_matrix *m2);
t_matrix	*neg_matrix(t_matrix **res, t_matrix *m);
GLfloat		get_det_3x3mat(t_matrix *m);
t_matrix	*get_inv_2x2mat(t_matrix **res, t_matrix *m);
t_matrix	*get_inv_3x3mat(t_matrix *res, t_matrix *m);
t_matrix	*get_inv_4x4mat(t_matrix *res, t_matrix *m);
void		mult_vect(t_vector *dest, const t_matrix *mtx,
					const t_vector *vect);

/*
** matrix_transformations.c
*/
void		translation(t_matrix **mtx, GLfloat x, GLfloat y, GLfloat z);
void		x_rotation(t_matrix **mtx, GLfloat theta);
void		y_rotation(t_matrix **mtx, GLfloat theta);
void		z_rotation(t_matrix **mtx, GLfloat theta);
void		scale(t_matrix **mtx, GLfloat x, GLfloat y, GLfloat z);

#endif
