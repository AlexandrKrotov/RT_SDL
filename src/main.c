#include <rt.h>

void	ft_change_scene(t_m *m, char *scene)
{
	if (!strcmp(scene, "sphere"))
		ft_scene_init_sphere(m);
	else if (!strcmp(scene, "plane"))
		ft_scene_init_plane(m);
	else if (!strcmp(scene, "cone"))
		ft_scene_init_cone(m);
	else if (!strcmp(scene, "cylinder"))
		ft_scene_init_cylinder(m);
	else if (!strcmp(scene, "scene1"))
		ft_init_scene_1(m);
	else if (!strcmp(scene, "random"))
		ft_init_scene_2(m);
	else if (!strcmp(scene, "multilight"))
		ft_init_multilight(m);
	else
		ft_error(1);
}

void ft_init(t_m *m)
{
    m->lprm = fsdl_lprm_create();
    m->lprm->wnd = fsdl_window_create_stuct(D_WIDTH, D_HEIGHT, D_NAME);
    fsdl_window_and_renderer_create(m->lprm->wnd);
    m->loop = true;
}

void ft_loop(t_m *m)
{
    while (m->loop == true)
    {
		ft_render(&m);
        fsdl_loop_regular_operations(m->lprm);
    }
}

void	lets_start(char *scene)
{
	t_m	m;

	ft_init(&m);
	init_m(&m);
	ft_change_scene(&m, scene);
	ft_loop(&m);
}

int main(int ac, char **av) {
	int		stime;
	long	ltime;

	ltime = time(NULL);
	stime = (unsigned int)ltime / 2;
	srand((UC)stime);
	if (ac != 2)
		ft_error(1);
	else
		  fsdl_project_exec(lets_start, av[1]);
    return 0;
}