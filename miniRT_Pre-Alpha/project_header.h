/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:36:44 by lignigno          #+#    #+#             */
/*   Updated: 2021/02/12 12:37:54 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_HEADER_H
# define PROJECT_HEADER_H

/*
** not foget :
**
** delete x and y for pers;
** -return FLAGS in every Makefile;
** delete this comment;
*/

/*
**  /--------------------------------------------------------------------------\
** |                                ._________.                                |
** |                                | CONTENT |                                |
** |                                '_________'                                |
** |                                                                           |
** | ____INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . .  57   |
** |                                                                           |
** | ____DEFINES :                                                             |
** |     -keys . . . . . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |     -params . . . . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |     -need_cleared . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |     -errors . . . . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |     -my_pluhi . . . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |                                                                           |
** | ____STRUCTS :                                                             |
** |     -images . . . . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |     -objects  . . . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |     -main_struct  . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |                                                                           |
** | ____PROTOTYPES :                                                          |
** |     -{ ./ } : . . . . . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |         -utils_1.c                                                        |
** |         -errorka.c                                                        |
** |     -{ parser_and_processing/ } : . . . . . . . . . . . . . . . . . xxx   |
** |     -{ initial_setup.c/ } : . . . . . . . . . . . . . . . . . . . . xxx   |
** |     -{ cleaner.c/ } : . . . . . . . . . . . . . . . . . . . . . . . xxx   |
** |                                                                           |
** |                                                                           |
**  \--------------------------------------------------------------------------/
*/

/*
** _____________________________________________________________________INCLUDES
*/

# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <sys/errno.h>

/*
** ______________________________________________________________________DEFINES
*/

/*
** 0xc8de21 font
** 0x1e1e1e backgound
*/

/*
** <<<<<<<<[KEYS]>>>>>>>>
*/

# define ESC 53
# define UP 126
# define DW 125
# define RG 124
# define LF 123

/*
** <<<<<<<<[PARAMS]>>>>>>>>
*/

# define BUFFER_SIZE 1024
# define SPEED 40

/*
** <<<<<<<<[NEED_CLEARED]>>>>>>>>
*/

/*
** to clear a specific element,
** you need to do as shown in the following example:
**
** {
**     t_vars  vars;
**
**     vars.need_cleared[CLEAR_ONLY] = CYLINDER;
**     cleaner(t_vars *vars);
** }
*/

enum			e_need_cleared
{
	CLEAR_ONLY,
	CANVAS,
	TOP_P,
	CRT_P,
	ADJ_P,
	CAM,
	LIGHT,
	PLANE,
	SPHERE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
	MLX,
};

/*
** <<<<<<<<[ERRORS]>>>>>>>>
*/

/*
**    NMA : NOT MEMORY ALLOCATED
*/

# define NO_ARG "no .rt file\n\n"
# define MANY_ARG "too many arguments\n\n"
# define BAD_FILE_NAME "not correct file name\n\n"
# define BAD_EXTENSION "the file has an invalid extension\n\n"
# define BAD_SECOND_ARG "not correct second argument\n\n"
# define NOT_CREATED_MLX "failed to create mlx\n\n"
# define NMA_CAMERA "failed to allocate memory under camera\n\n"
# define NMA_LIGHT "failed to allocate memory under light\n\n"
# define NMA_PLANE "failed to allocate memory under plane\n\n"
# define NMA_SPHERE "failed to allocate memory under sphere\n\n"
# define NMA_SQUARE "failed to allocate memory under square\n\n"
# define NMA_CYLINDER "failed to allocate memory under cylinder\n\n"
# define NMA_TRIANGLE "failed to allocate memory under triangle\n\n"
# define R_WAS_SET "resolution has been set\n\n"
# define A_WAS_SET "ambient has been set\n\n"
# define INCORRECT_RESOLUTION "the resolution in the .rt file \
is set incorrectly\n\n"
# define INCORRECT_AMBIENT "the ambient in the .rt file is set incorrectly\n\n"
# define INCORRECT_CAMERA "the camera in the .rt file is set incorrectly\n\n"
# define INCORRECT_LIGHT "the light in the .rt file is set incorrectly\n\n"
# define INCORRECT_PLANE "the plane in the .rt file is set incorrectly\n\n"
# define INCORRECT_SPHERE "the sphere in the .rt file is set incorrectly\n\n"
# define INCORRECT_SQUARE "the square in the .rt file is set incorrectly\n\n"
# define INCORRECT_CYLINDER "the cylinder in the .rt file \
is set incorrectly\n\n"
# define INCORRECT_TRIANGLE "the triangle in the .rt file \
is set incorrectly\n\n"
# define NOT_EMPTY_NOT_NEW_LINE "the line is not empty and there is no \\n\n\n"
# define CANT_OPEN "can\'t open .rt file\n\n"
# define READ_DIED "read_died\n\n"
# define DUMMY_ERROR "it\'s just a dummy_error, nothing important, pass on\n\
(or did I just forget to come up with this error)\n\n"

/*
** <<<<<<<<[MY_PLUHI]>>>>>>>>
*/

# define IN_A_HUMAN_WAY 1
# define ADJUSTMENTS 0
# define BCKG_CANVAS 0x1c1d21

/*
** ______________________________________________________________________STRUCTS
*/

/*
** transcript for image abbreviations
**
**    top_p : top_panel
**    crt_p : creation_panel
**    adj_p : adjustment_panel
*/

/*
** <<<<<<<<[IMAGES]>>>>>>>>
*/

typedef struct	s_img_data
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bit_per_pixel;
	int			endian;
}				t_img_data;

typedef struct	s_img
{
	t_img_data	canvas;
	t_img_data	top_p;
	t_img_data	crt_p;
	t_img_data	adj_p;
}				t_img;

/*
** <<<<<<<<[OBJECTS]>>>>>>>>
*/

typedef struct	s_cam
{
	double				coordinates[3];
	double				normal_vector[3];
	int					fov;
	t_img_data			view;
	struct s_cam		*next;
}				t_cam;

typedef struct	s_light
{
	double				coordinates[3];
	int					color;
	struct s_light		*next;
}				t_light;

typedef struct	s_plane
{
	double				coordinates[3];
	double				normal_vector[3];
	int					color;
	struct s_plane		*next;
}				t_plane;

typedef struct	s_sphere
{
	double				coordinates[3];
	int					color;
	double				diameter;
	struct s_sphere		*next;
}				t_sphere;

typedef struct	s_square
{
	double				coordinates[3];
	double				normal_vector[3];
	int					color;
	double				side_size;
	struct s_square		*next;
}				t_square;

typedef struct	s_cylinder
{
	double				coordinates[3];
	double				normal_vector[3];
	int					color;
	double				diameter;
	double				height;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct	s_triangle
{
	double				coordinates_a[3];
	double				coordinates_b[3];
	double				coordinates_c[3];
	int					color;
	struct s_triangle	*next;
}				t_triangle;

typedef struct	s_objs
{
	t_cam		*cam;
	t_light		*light;
	t_plane		*plane;
	t_sphere	*sphere;
	t_square	*square;
	t_cylinder	*cylinder;
	t_triangle	*triangle;
}				t_objs;

/*
** <<<<<<<<[MAIN_STRUCT]>>>>>>>>
*/

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	int			save;
	int			w_win;
	int			h_win;
	int			ambient;
	int			need_cleared[21];
	void		(*cleared_func[21])(struct s_vars *);
	void		*tmp;
	t_img		imgs;
	t_objs		objects;
	t_cam		*current_cam;



	int			x;		//pers
	int			y;		//pers
}				t_vars;

/*
** ___________________________________________________________________PROTOTYPES
*/

void			ts_pers(t_vars *vars);
void			initial_rendering(t_vars *vars);

/*
**  ___________________________________________________________________________
** | FUNCTIONS PROTOTYPE FROM A FOLDER                                     ./  |
** |___________________________________________________________________________|
*/

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                             UTILS_1.C]>>>>>>>>
*/

int				rgba(int r, int g, int b, int a);
void			put_pixel(t_img_data data, int x, int y, int color);
void			fill_img(t_img_data dat, int color);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                             ERRORKA.C]>>>>>>>>
*/

void			errorka(t_vars *vars, char *error);

/*
**  ___________________________________________________________________________
** | FUNCTIONS PROTOTYPE FROM A FOLDER                 PARSER_AND_PROCESSING/  |
** |___________________________________________________________________________|
*/

/*
** <<<<<<<<[PROTOTYPE FROM A FILE             PROCESSING_INPUT_VALUES.C]>>>>>>>>
*/

void			processing_input_values(t_vars *vars, int count, char **value);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                   PARSER_SCENE_FILE.C]>>>>>>>>
*/

void			parser_scene_file(t_vars *vars, char *file_name);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                  UTILS_FOR_PARSER_1.C]>>>>>>>>
*/

int				get_int_num_in_range(char **str, long *num, int from, int to);
int				get_dbl_num_in_range(char **str, double *num, int from, int to);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                  UTILS_FOR_PARSER_2.C]>>>>>>>>
*/

int				get_coordinates(char **str, double *coordinates);
int				add_rgb(char **str, int *color);

/*
** <<<<<<<<[PROTOTYPE FROM A OTHER SUB PARSER FILES]>>>>>>>>
*/

void			get_resolution(t_vars *vars, char *str);
void			get_ambient(t_vars *vars, char *str);
void			get_camera(t_vars *vars, char *str);
void			get_light(t_vars *vars, char *str);
void			get_plane(t_vars *vars, char *str);
void			get_sphere(t_vars *vars, char *str);
void			get_square(t_vars *vars, char *str);
void			get_cylinder(t_vars *vars, char *str);
void			get_triangle(t_vars *vars, char *str);

/*
**  ___________________________________________________________________________
** | FUNCTIONS PROTOTYPE FROM A FOLDER                       INITIAL_SETUP.C/  |
** |___________________________________________________________________________|
*/

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                       INITIAL_SETUP.C]>>>>>>>>
*/

void			initial_setup(t_vars *vars, int count, char **value);

/*
** <<<<<<<<[PROTOTYPE FROM A OTHER SUB SETUP FILES]>>>>>>>>
*/

void			setup_canvas(t_vars *vars);
void			setup_top_p(t_vars *vars);
void			setup_crt_p(t_vars *vars);
void			setup_adj_p(t_vars *vars);
void			setup_objects(t_vars *vars);

/*
**  ___________________________________________________________________________
** | FUNCTIONS PROTOTYPE FROM A FOLDER                             CLEANER.C/  |
** |___________________________________________________________________________|
*/

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                             CLEANER.C]>>>>>>>>
*/

void			cleaner(t_vars *vars);

/*
** <<<<<<<<[PROTOTYPE FROM A OTHER SUB CLEANUP FILES]>>>>>>>>
*/

void			free_mlx(t_vars *vars);
void			free_canvas(t_vars *vars);
void			free_top_p(t_vars *vars);
void			free_crt_p(t_vars *vars);
void			free_adj_p(t_vars *vars);
void			free_cam(t_vars *vars);
void			free_light(t_vars *vars);
void			free_plane(t_vars *vars);
void			free_sphere(t_vars *vars);
void			free_square(t_vars *vars);
void			free_cylinder(t_vars *vars);
void			free_triangle(t_vars *vars);

#endif
