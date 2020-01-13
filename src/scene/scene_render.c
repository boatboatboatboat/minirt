/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:15:15 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/11 03:59:55 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <minirt.h>

#if IS_BONUS == 1
# include <pthread.h>
#endif

void		*worker(void *msg_arg)
{
	t_thread_msg	*message;
	t_size			x;
	t_size			y;

	message = msg_arg;
	x = 0;
	y = message->id;
	while (y < message->scene->resolution[1])
	{
		x = 0;
		while (x < message->scene->resolution[0])
		{
			render_pixel(message->scene, x, y);
			x += 1;
		}
		y += THREAD_COUNT;
	}
	return (NULL);
}

#if IS_BONUS == 1

void		scene_render(t_scene *scene)
{
	t_size			x;
	pthread_t		threads[THREAD_COUNT];
	t_thread_msg	messages[THREAD_COUNT];

	scene->buffer.size = scene->buffer.capacity;
	x = 0;
	while (x < THREAD_COUNT)
	{
		messages[x].scene = scene;
		messages[x].id = x;
		if (pthread_create(&threads[x], NULL, worker, &messages[x]) != 0)
		{
			worker(&messages[x]);
			messages[x].scene = NULL;
		}
		x += 1;
	}
	while (x > 0)
	{
		x -= 1;
		if (messages[x].scene != NULL)
			pthread_join(threads[x], NULL);
	}
}

#else

void		scene_render(t_scene *scene)
{
	t_thread_msg	message;

	scene->buffer.size = scene->buffer.capacity;
	message.scene = scene;
	message.id = 0;
	worker(&message);
}

#endif
