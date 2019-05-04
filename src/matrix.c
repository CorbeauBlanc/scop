/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:14:48 by edescoin          #+#    #+#             */
/*   Updated: 2019/05/02 19:18:15 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		clear_matrix(t_matrix *mat)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mat->r)
	{
		j = -1;
		while (++j < mat->c)
			mat->mat[i][j] = 0;
	}
}

t_matrix	*new_matrix(GLfloat **mat, int r, int c)
{
	t_matrix	*matrix;
	int			i;

	if (!(matrix = malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->r = r;
	matrix->c = c;
	if (!mat)
	{
		if (!(matrix->mat = (GLfloat**)malloc(r * sizeof(GLfloat*))))
			exit_error("rt", "malloc");
		i = -1;
		while (++i < r)
			if (!(matrix->mat[i] = (GLfloat*)malloc(c * sizeof(GLfloat))))
				exit_error("rt", "malloc");
		clear_matrix(matrix);
	}
	else
		matrix->mat = mat;
	return (matrix);
}

t_matrix	*create_identity(int i)
{
	t_matrix	*mtx;

	mtx = new_matrix(NULL, i, i);
	i = -1;
	while (++i < mtx->c)
		mtx->mat[i][i] = 1;
	return (mtx);
}

t_matrix	*copy_matrix(t_matrix *dst, t_matrix *src)
{
	int	i;
	int	j;

	if (dst->r != src->r || dst->c != src->c)
		return (NULL);
	i = -1;
	while (++i < dst->r)
	{
		j = -1;
		while (++j < dst->c)
			dst->mat[i][j] = src->mat[i][j];
	}
	return (dst);
}

void		delete_matrix(t_matrix *matrix)
{
	int	r;

	if (matrix)
	{
		r = -1;
		while (++r < matrix->r)
			free(matrix->mat[r]);
		free(matrix->mat);
		free(matrix);
	}
}
