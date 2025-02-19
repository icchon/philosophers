/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisobe <kaisobe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:30:26 by kaisobe           #+#    #+#             */
/*   Updated: 2025/02/19 16:31:42 by kaisobe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "utils.h"
# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_info
{
	int						n_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						n_must_eat;
	int						must_eat_flg;
	pthread_mutex_t			print_mutex;
}							t_info;

typedef struct s_fork
{
	int						id;
	pthread_mutex_t			mutex;
}							t_fork;

typedef struct timeval		t_timeval;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
}							t_philo_status;

typedef struct s_philosopher
{
	int						id;
	t_philo_status			status;
	int						exit_flg;
	pthread_mutex_t			exit_flg_mutex;
	t_timeval				last_meal_time;
	struct s_philosopher	*left_person;
	struct s_philosopher	*right_person;
	t_fork					*left_fork;
	t_fork					*right_fork;
	pthread_t				pthread;
	t_timeval				start_time;
	pthread_mutex_t			last_meal_time_mutex;
	pthread_mutex_t			n_meals_mutex;
	t_info					*info;
	int						n_meals;
}							t_philosopher;

int							is_full_stomach(t_philosopher *philosopher);
int							is_all_full_stomach(t_philosopher *philosophers);
int							is_dead(t_philosopher *philosopher);
double						get_passed_time(t_timeval start);
t_philosopher				*new_philosophers(t_info *info);
t_philosopher				*get_philosopher(t_philosopher *philosophers,
								int id);
t_philosopher				*new_philosopher(int id, t_info *info);
void						print_philosophers(t_philosopher *philosophers);
void						print_philosopher(t_philosopher *philosopher);
void						print_log(t_philosopher *philosopher, char *msg);
void						print_info(t_info *info);
int							simulate(t_philosopher *philosophers);
void						monitor(t_philosopher *philosophers);
t_info						*new_info(int argc, char *argv[]);
void						set_info(t_info *info, int argc, char *argv[]);
t_fork						*new_fork(int id);
int							do_sleep(t_philosopher *philosopher);
int							do_eat(t_philosopher *philosopher);
int							release_forks(t_philosopher *philosopher);
int							take_forks(t_philosopher *philosopher);
void						free_info(t_info *info);
void						free_philosophers(t_philosopher *philosophers);
void						free_fork(t_fork *fork);
int							is_valid_arg(int argc, char *argv[]);
void						*monitor_thread(void *arg);
int							is_exit_flg(t_philosopher *philosopher);
int							is_any_dead(t_philosopher *philosophers);

#endif
