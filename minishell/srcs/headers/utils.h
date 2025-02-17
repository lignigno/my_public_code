/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:56:22 by lignigno          #+#    #+#             */
/*   Updated: 2021/06/01 23:56:10 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "all_headers.h"

# define BUFFER_SIZE 1

char	*add_char(char *str, char ch, size_t index);
void	add_new_history(t_all_var *all, char *command_line);
void	add_process(t_all_var *all, t_command *command, int pid);
void	add_var(t_all_var *all, const char *variable, char *value);
void	add_with_sorting(t_all_var *all, char *str, t_env **list);
void	add_without_sorting(t_all_var *all, char *str, t_env **list);
int		change_existing_variable(t_all_var *all, t_env *env, t_env *list);
void	change_pwd(t_all_var *all);
void	change_oldpwd(t_all_var *all, char *tmp);
char	compare_char_with(const char *arr_type, char ch);
int		command_exists(t_all_var *all, char *command, char **full_name);
void	destroy_processes(int signal, int except);
void	free_pipes(int	**pipes);
void	free_processes(void);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(long long n);
int		ft_putchar(int ch);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_value(t_all_var *all, char *variable);
t_env	*get_variable(t_env *list, char *name_variable);
int		name_with_path(char *name);
t_env	*new_env(t_all_var *all, char *str);
int		not_valid_identifier(t_all_var *all, char *func, char *what, int *code);
int		o_my_wait(void);
size_t	skip_redirects(char *str, size_t i, int mark, int slash);
size_t	skip_spaces(char *str, size_t i);
int		valid_char(char ch, size_t i);

#endif