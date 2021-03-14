/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:36:44 by lignigno          #+#    #+#             */
/*   Updated: 2021/03/13 13:48:21 by lignigno         ###   ########.fr       */
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
** <<<<<<<<[KEYS]>>>>>>>>
*/

# define ESC 53
# define UP 126
# define DW 125
# define RG 124
# define LF 123
# define SPACE 49

/*
** <<<<<<<<[PARAMS]>>>>>>>>
*/

# define YES 1
# define NO 0
# define BUFFER_SIZE 1024
# define SPEED 40
# define DEPTH 6
//canvas |--> screen_saver
# define BCKG_CANVAS 0x1c1d21
# define BCKG_SCENE 0x181a21

/*
** attenuation
*/

# define A 0.00003
# define B 0.0
# define C 1


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
# define NMA_SAVE "failed to allocate memory under save image\n\n"
# define NMA_INVERT "failed to allocate memory under invert image\n\n"
# define R_WAS_SET "resolution has been set\n\n"
# define A_WAS_SET "ambient has been set\n\n"
# define INCORRECT_RESOLUTION "the resolution in the .rt file incorrect\n\n"
# define INCORRECT_AMBIENT "the ambient in the .rt file incorrect\n\n"
# define INCORRECT_CAMERA "the camera in the .rt file incorrect\n\n"
# define INCORRECT_LIGHT "the light in the .rt file incorrect\n\n"
# define INCORRECT_PLANE "the plane in the .rt file incorrect\n\n"
# define INCORRECT_SPHERE "the sphere in the .rt file incorrect\n\n"
# define INCORRECT_SQUARE "the square in the .rt file incorrect\n\n"
# define INCORRECT_CYLINDER "the cylinder in the .rt file incorrect\n\n"
# define INCORRECT_TRIANGLE "the triangle in the .rt file incorrect\n\n"
# define NOT_EMPTY_NOT_NEW_LINE "the line is not empty and this no element\n\n"
# define CANT_OPEN "can\'t open .rt file\n\n"
# define READ_DIED "read_died\n\n"
# define DUMMY_ERROR "it\'s just a dummy_error, nothing important, pass on\n\n"

/*
** <<<<<<<<[MY_PLUHI]>>>>>>>>
*/

# define IN_A_HUMAN_WAY 1
# define ADJUSTMENTS 0
# define PERCENT 1
# define FOV_MAX 3600

// int		gg_flag = 0;

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
	CAM_IMG,
	LIGHT,
	PLANE,
	SPHERE,
	SQUARE,
	CYLINDER,
	TRIANGLE,
	MLX,
};

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
** <<<<<<<<[VECTOR]>>>>>>>>
*/

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

/*
** <<<<<<<<[OBJECTS]>>>>>>>>
*/

typedef struct	s_cam
{
	int					fov;
	t_vector			coordinates;
	t_vector			orientation;
	t_vector			normal_vector;
	t_img_data			view;
	struct s_cam		*next;
}				t_cam;

typedef struct	s_light
{
	t_vector			coordinates;
	int					color;
	struct s_light		*next;
}				t_light;

typedef struct	s_plane
{
	t_vector			coordinates;
	t_vector			normal_vector;
	int					color;
	struct s_plane		*next;
}				t_plane;

typedef struct	s_sphere
{
	t_vector			coordinates;
	int					color;
	double				diameter;
	struct s_sphere		*next;
}				t_sphere;

typedef struct	s_square
{
	t_vector			coordinates;
	t_vector			normal_vector;
	int					color;
	double				side_size;
	struct s_square		*next;
}				t_square;

typedef struct	s_cylinder
{
	t_vector			coordinates;
	t_vector			orientation;
	int					color;
	double				diameter;
	double				height;
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct	s_triangle
{
	t_vector			a;
	t_vector			b;
	t_vector			c;
	t_vector			normal_vector;
	int					color;
	struct s_triangle	*next;
}				t_triangle;

typedef struct	s_objs
{
	t_cam				*cam;
	t_light				*light;
	t_plane				*plane;
	t_sphere			*sphere;
	t_square			*square;
	t_cylinder			*cylinder;
	t_triangle			*triangle;
}				t_objs;

/*
** <<<<<<<<[INTERSECTION]>>>>>>>>
*/

typedef struct	s_inter
{
	t_vector	point;
	int			color;
	t_objs		obj;
}				t_inter;

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
	int			screen_saver;
	int			need_cleared[21];
	void		(*cleared_func[21])(struct s_vars *);
	t_img		imgs;
	t_objs		objects;
	t_cam		*current_cam;
}				t_vars;

/*
** ___________________________________________________________________PROTOTYPES
*/

/*
**  ___________________________________________________________________________
** | FUNCTIONS PROTOTYPE FROM A FOLDER                                     ./  |
** |___________________________________________________________________________|
*/

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                      CREATE_BMP_IMG.C]>>>>>>>>
*/

void			create_bmp_img(t_vars *vars);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                             UTILS_1.C]>>>>>>>>
*/

int				rgba(int r, int g, int b, int a);
void			put_pixel(t_img_data data, int x, int y, int color);
void			fill_img(t_img_data dat, int color);
int				closer(t_vector p_1, t_vector p_2, t_vector p_start);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                             ERRORKA.C]>>>>>>>>
*/

void			errorka(t_vars *vars, char *error);

/*
**  ___________________________________________________________________________
** | FUNCTIONS PROTOTYPE FROM A FOLDER                             RENDERING/  |
** |___________________________________________________________________________|
*/

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                         MAIN_RENDER.C]>>>>>>>>
*/

void			main_render(t_vars *vars, int full_render);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                RENDER_CAMERAS_VIEWS.C]>>>>>>>>
*/

void			render_cameras_views(t_vars *vars);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                          SHADOW_RAY.C]>>>>>>>>
*/

int				shadow_ray(t_vars *vars, t_inter intersection, t_vector start);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                           RAY_TRACE.C]>>>>>>>>
*/

int				ray_trace(t_vars *vars, t_vector p_1, t_vector p_2, int depth);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                   INTERS_WITH_PLANE.C]>>>>>>>>
*/

t_inter			inters_with_plane(t_vars *vars, t_vector p_1, t_vector p_2);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                  INTERS_WITH_SPHERE.C]>>>>>>>>
*/

t_inter			inters_with_sphere(t_vars *vars, t_vector p_1, t_vector p_2);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                  INTERS_WITH_SQUARE.C]>>>>>>>>
*/

t_inter			inters_with_square(t_vars *vars, t_vector p_1, t_vector p_2);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                INTERS_WITH_CYLINDER.C]>>>>>>>>
*/

t_inter			inters_with_cylinder(t_vars *vars, t_vector p_1, t_vector p_2);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                INTERS_WITH_TRIANGLE.C]>>>>>>>>
*/

t_inter			inters_with_triangle(t_vars *vars, t_vector p_1, t_vector p_2);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE                   NORMAL_FOR_OBJECT.C]>>>>>>>>
*/

t_vector		normal_for_plane(t_plane plane, t_vector start);
t_vector		normal_for_sphere(t_inter intersection, t_vector start);
t_vector		normal_for_square(t_square square, t_vector start);
t_vector		normal_for_cylinder(t_inter cylinder, t_vector start);
t_vector		normal_for_triangle(t_triangle triangle, t_vector start);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE              FUNCTIONS_FOR_VECTOR_1.C]>>>>>>>>
*/

double			len_vector(t_vector vector);
t_vector		multiplying_vector(t_vector vector, double num);
t_vector		calculating_normal_vector(t_vector orientation);
t_vector		vector_rotate(t_vector vector, t_vector axis, double angle);
t_vector		sum_vector(t_vector vector_1, double sign, t_vector vector_2);

/*
** <<<<<<<<[PROTOTYPE FROM A FILE              FUNCTIONS_FOR_VECTOR_2.C]>>>>>>>>
*/

double			cos_vectors(t_vector v1, t_vector v2);
double			scalar(t_vector a, t_vector b);

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

int				get_coordinates(char **str, t_vector *coordinates);
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

void			initial_setup(t_vars *vars, char **value);

/*
** <<<<<<<<[PROTOTYPE FROM A OTHER SUB SETUP FILES]>>>>>>>>
*/

void			setup_canvas(t_vars *vars);
void			setup_top_p(t_vars *vars);
void			setup_crt_p(t_vars *vars);
void			setup_adj_p(t_vars *vars);
void			setup_objects(t_vars *vars);
void			setup_cams_views(t_vars *vars);

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
