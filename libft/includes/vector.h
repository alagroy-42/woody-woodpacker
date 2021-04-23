/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:28:53 by alagroy-          #+#    #+#             */
/*   Updated: 2019/09/23 17:28:54 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "libft.h"

typedef int			(*t_func)(int c);

typedef struct		s_vector
{
	char	*value;
	size_t	len;
	size_t	size;
	int		scale;
}					t_vector;

int					vct_append(t_vector *vct, char c);
void				vct_apply(t_vector *vct, t_func f);
int					vct_cat(t_vector *vct, t_vector *cat);
ssize_t				vct_chr(t_vector *vct, char c);
t_vector			*vct_create(int len);
int					vct_delpart(t_vector *vct, unsigned int i,
					unsigned int len);
void				vct_destroy(t_vector **vct);
void				vct_dprint(t_vector *vct, int fd);
void				vct_dprintendl(t_vector *vct, int fd);
char				vct_gnc(t_vector *vct);
int					vct_gnl(int fd, t_vector **vct);
int					vct_insertstr(t_vector *vct, char *str, int index);
int					vct_nappend(t_vector *vct, char c, int n);
int					vct_ncmp(t_vector *vct, t_vector *cmp, unsigned int n);
int					vct_npush(t_vector *vct, char c, unsigned int n);
void				vct_print(t_vector *vct);
void				vct_printendl(t_vector *vct);
int					vct_push(t_vector *vct, char c);
ssize_t				vct_rchr(t_vector *vct, char c);
int					vct_read_file(int fd, t_vector *vct);
int					vct_realloc(t_vector *vct);
void				vct_replace(t_vector *vct, char c, char replace);
void				vct_rev(t_vector *vct);
t_vector			*vct_split(t_vector *vct, char c);
int					vct_strcat(t_vector *vct, char *str);
int					vct_strcpy(t_vector *vct, char *str);
t_vector			*vct_strdup(char *str);
int					vct_strncat(t_vector *vct, char *str, unsigned int len);
int					vct_strncpy(t_vector *vct, char *str, unsigned int len);
int					vct_strpush(t_vector *vct, char *str);
int					vct_strreplace(t_vector *vct, char *s, char *replace);
t_vector			*vct_strsplit(t_vector *vct, char *c);
ssize_t				vct_strstr(t_vector *vct, char *s);
t_vector			*vct_sub(t_vector *vct, int i, int len);
int					vct_vctcpy(t_vector *vct, t_vector *cpy);
t_vector			*vct_vctdup(t_vector *vct);
int					vct_vctncpy(t_vector *vct, t_vector *cpy, unsigned int n);

#endif
