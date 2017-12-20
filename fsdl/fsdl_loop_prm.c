#include "fsdl.h"

t_lprm	*fsdl_lprm_create(void)
{
	t_lprm	*lprm;

	if ((lprm = malloc(sizeof(t_lprm))) == NULL)
		ft_errors_general(ERR_MALLOC);
	return (lprm);
}

void	fsdl_loop_regular_operations(t_lprm *lprm)
{
	if (SDL_PollEvent(&lprm->e))
		lprm->efl = true;
	else
		lprm->efl = false;
	lprm->ks = SDL_GetKeyboardState(NULL);
	fsdl_window_get_dim(lprm->wnd);
	SDL_GetMouseState(&lprm->ms_coord.x, &lprm->ms_coord.y);
}
