#include "../project_header.h"

/*
** ________________________________________________________________MAIN FUNCTION
*/

static void risovat(t_vars *vars)
{
	#define PI 3.14159265
	double	angl;
	double	x = 0;
	double	y = 0;
	int		radius = 40;
	
	while (radius > 0)
	{
		angl = 0;
		while (angl < 360)
		{
			x = cos(angl * PI / 180) * radius;
			y = sin(angl * PI / 180) * radius;
			put_pixel(vars->imgs.top_p, 40 + x, 39 + 1 + y,
			(180 << 16) + 80 + (radius << 16) + radius);
			angl += 0.2;
		}
		radius--;
	}
}

void			setup_top_p(t_vars *vars)
{
	t_img_data	data;

	data = vars->imgs.top_p;
	data.img = mlx_new_image(vars->mlx, 80, 80);
	data.addr = mlx_get_data_addr(data.img,
								 &data.bit_per_pixel,
								 &data.width,
								 &data.endian);
	data.height = 80;
	fill_img(data, 0xff000000);
	vars->imgs.top_p = data;
	risovat(vars);
	vars->need_cleared[TOP_P] = 1;
	vars->cleared_func[TOP_P] = free_top_p;
}