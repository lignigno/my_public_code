#include "../project_header.h"

void	free_canvas(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.canvas.img);
}

void	free_top_p(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.top_p.img);
}

void	free_crt_p(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.crt_p.img);
}

void	free_adj_p(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->imgs.adj_p.img);
}
