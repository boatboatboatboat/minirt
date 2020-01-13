/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:26:56 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/11 01:19:47 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <vec3.h>
# include <libft.h>
# include <mat4.h>
# include <vector.h>

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

t_ray			ray_new(
		t_vec3 origin,
		t_vec3 direction);

typedef struct	s_color
{
	t_u8	b;
	t_u8	g;
	t_u8	r;
}				t_color;

t_color			color_add(
		t_color a,
		t_color b);
t_color			color_mul(
		t_color a,
		t_color b,
		t_f64 mult);
t_color			color_new(
		t_u8 r,
		t_u8 g,
		t_u8 b);

unsigned int	color_as_uint(t_color color);

typedef enum	e_render_tag
{
	Sphere,
	Plane,
	Triangle,
	Square,
	Cylinder
}				t_render_tag;

typedef struct	s_sphere
{
	t_vec3		center;
	t_f64		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_vec3		center;
	t_vec3		rotation;
}				t_plane;

typedef struct	s_square
{
	t_vec3		center;
	t_vec3		rotation;
	t_f64		size;
	t_size		other;
}				t_square;

typedef struct	s_triangle
{
	t_vec3		v0;
	t_vec3		v1;
	t_vec3		v2;
	t_size		other;
	t_bool		direction;
}				t_triangle;

typedef struct	s_cylinder
{
	t_vec3		center;
	t_vec3		rotation;
	t_f64		radius;
	t_f64		height;
	t_size		other;
	t_bool		direction;
}				t_cylinder;

typedef union	u_render_variant
{
	t_sphere	sphere;
	t_plane		plane;
	t_triangle	triangle;
	t_square	square;
	t_cylinder	cylinder;
}				t_render_variant;

typedef struct	s_renderable
{
	t_render_variant	var;
	t_render_tag		tag;
	t_color				color;
	t_bool				(*intersect)(
			struct s_renderable *, const t_ray *, t_f64 *out);
	t_vec3				(*normal)(struct s_renderable *, t_vec3 *);
}				t_renderable;

t_bool			sphere_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out);
t_vec3			sphere_normal(
		struct s_renderable *self,
		t_vec3 *hit);

t_bool			plane_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out);
t_vec3			plane_normal(
		struct s_renderable *self,
		t_vec3 *hit);

t_bool			cylinder_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out);
t_vec3			cylinder_normal(
		struct s_renderable *self,
		t_vec3 *hit);

t_bool			square_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out);
t_vec3			square_normal(
		struct s_renderable *self,
		t_vec3 *hit);

t_bool			triangle_intersect(
		struct s_renderable *self,
		const t_ray *ray,
		t_f64 *out);
t_bool			real_triangle_intersect(
		t_triangle *self,
		const t_ray *ray,
		t_f64 *out);
t_vec3			triangle_normal(
		struct s_renderable *self,
		t_vec3 *hit);

typedef struct	s_light
{
	t_color		color;
	t_vec3		position;
	t_f64		brightness;
}				t_light;

typedef struct	s_camera
{
	t_mat4		cframe;
	t_vec3		adjust;
	t_f64		fov;
}				t_camera;

typedef struct	s_scene
{
	unsigned char	set;
	t_size			resolution[2];
	t_color			ambient_color;
	t_f64			ambient_brightness;
	t_vector		objects;
	t_vector		lights;
	t_vector		cameras;
	t_size			current_camera;
	t_vector		buffer;
	t_size			scale;
}				t_scene;

void			scene_render(t_scene *self);
t_bool			scene_cast_ray(
		t_scene *self,
		const t_ray *ray,
		t_renderable **hit,
		t_f64 *distance);
t_ray			screen_ray(
		t_scene *scene,
		t_size x,
		t_size y);
void			render_pixel(
		t_scene *scene,
		t_size x,
		t_size y);
t_ray			screen_ray_res(
		t_scene *scene,
		const t_size resolution[2],
		t_size x,
		t_size y);

typedef struct	s_thread_msg
{
	t_scene		*scene;
	int			id;
}				t_thread_msg;

#endif
