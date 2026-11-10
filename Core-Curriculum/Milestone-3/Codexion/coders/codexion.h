/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:23:09 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/28 17:20:00 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <sys/time.h>
# include <stddef.h>

typedef struct s_simulation	t_simulation;
typedef struct s_coder		t_coder;

typedef struct s_request
{
	t_coder			*coder;
	long long		deadline;
	unsigned long	sequence;
}	t_request;

typedef struct s_heap
{
	t_request	**items;
	int			size;
	int			capacity;
}	t_heap;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	t_heap			queue;
	long long		available_at;
	unsigned long	sequence;
	int				held;
}	t_dongle;

typedef struct s_config
{
	int			coders_count;
	long long	burnout_ms;
	long long	compile_ms;
	long long	debug_ms;
	long long	refactor_ms;
	int			required_compiles;
	long long	cooldown_ms;
	int			edf;
}	t_config;

struct s_coder
{
	int				id;
	t_simulation	*simulation;
	t_dongle		*left;
	t_dongle		*right;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	long long		last_compile_start;
	int				compile_count;
};

struct s_simulation
{
	t_config		config;
	t_coder			*coders;
	t_dongle		*dongles;
	pthread_t		monitor;
	pthread_mutex_t	state_mutex;
	pthread_cond_t	state_cond;
	pthread_mutex_t	log_mutex;
	long long		start_ms;
	int				stopped;
	int				initialized_coders;
	int				initialized_dongles;
	int				initialized_state;
	unsigned long	request_sequence;
};

int			parse_arguments(int argc, char **argv, t_config *config);
void		copy_config(t_config *destination, const t_config *source);
long long	current_time_ms(void);
void		wait_ms(long long duration);
void		log_state(t_simulation *simulation, int id, const char *message);
void		log_burnout(t_simulation *simulation, int id);

int			init_simulation(t_simulation *simulation, t_config *config);
void		destroy_simulation(t_simulation *simulation);

void		sift_up(t_heap *heap, int index);
void		sift_down(t_heap *heap, int index);
int			heap_push(t_heap *heap, t_request *request);
t_request	*heap_peek(t_heap *heap);
void		heap_pop(t_heap *heap);
void		heap_remove(t_heap *heap, t_request *request);
void		free_heap(t_heap *heap);

void		make_timeout(struct timespec *timeout, long long time_ms);
int			simulation_stopped(t_simulation *simulation);
int			acquire_dongle(t_coder *coder, t_dongle *dongle);
void		release_dongle(t_coder *coder, t_dongle *dongle);
int			hold_single_dongle(t_coder *coder, t_dongle *dongle);
int			acquire_pair(t_coder *coder, t_dongle *first, t_dongle *second);
void		wake_dongles(t_simulation *simulation);

void		stop_simulation(t_simulation *simulation);
void		*coder_routine(void *argument);
void		*monitor_routine(void *argument);

#endif
