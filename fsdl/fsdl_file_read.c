#include "fsdl.h"

//TODO Norm it
char *fsdl_file_read(const char *fn)
{
	SDL_RWops	*rw;
	Sint64		r_size;
	Sint64		nb_read_total;
	Sint64		nb_read;
	char		*res;
	char		*buf;

	if ((rw = SDL_RWFromFile(fn, "rb")) == NULL)
		fsdl_errors_log(ERR_FILE_OPEN);
	r_size = SDL_RWsize(rw);
	if ((res = malloc(sizeof(char) * ((size_t)r_size + 1))) == NULL)
		ft_errors_general(ERR_MALLOC);
	nb_read_total = 0;
	nb_read = 1;
	buf = res;
	while (nb_read_total < r_size && nb_read != 0)
	{
		nb_read = SDL_RWread(rw, buf, 1, (r_size - nb_read_total));
		nb_read_total += nb_read;
		buf += nb_read;
	}
	SDL_RWclose(rw);
	if (nb_read_total != r_size)
	{
		free(res);
		fsdl_errors_log(ERR_FILE_READ);
	}
	res[nb_read_total] = '\0';
	return (res);
}