/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_project.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:27:34 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/21 21:27:35 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSDL_H
# define FSDL_H

# if __APPLE__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_surface.h>
#  include <SDL2_ttf/SDL_ttf.h>
#  include <SDL2_image/SDL_image.h>

#  define SDL_REND SDL_RENDERER_ACCELERATED
# else
#  include <SDL.h>
#  include <SDL_surface.h>
#  include <SDL_ttf.h>
#  include <SDL_image.h>

#  define SDL_REND SDL_RENDERER_ACCELERATED
# endif

# include "ft_errors.h"
# include <stdio.h>
# include <errno.h>

#  define SDL_GLTXT SDL_GLContext

/*
** Custom SDL error defines
*/
# define ERR_TEX_QUERY 99
# define ERR_TEX_CREATE 100
# define ERR_WND_REND_CRE 101
# define ERR_WND_CRE 102
# define ERR_GL_CONTEXT 103
# define ERR_FILE_OPEN 104
# define ERR_FILE_READ 105

/*
** Sprite show mode defines
*/
# define SPR_NORMAL 0
# define SPR_SPR_TO_DEST 1
# define SPR_SPR_TO_SCR 2
# define SPR_WND_REL 3
# define SPR_CALC_WND_REL 4

/*
** Button flags defines
*/
enum	e_btn
{
	NO_FLAG = 0,
	IS_ABLE = 1,
	IS_VISIBLE = 2,
	IS_AV = 3
};

# define NA_VIEW 0
# define ABLE_VIEW 1

# define RSET fsdl_rect_set
# define DRSET fsdl_rect_double
# define R_TOD fsdl_rect_int_to_d
# define D_TOR fsdl_rect_dbl_to_int

# if SDL_BYTEORDER == SDL_BIGENDIAN
#  define RM 0xff000000
#  define GM 0x00ff0000
#  define BM 0x0000ff00
#  define AM 0x000000ff
# else
#  define RM 0x000000ff
#  define GM 0x0000ff00
#  define BM 0x00ff0000
#  define AM 0xff000000
# endif

typedef enum e_bool		t_bool;
typedef struct s_v2d	t_v2d;
typedef struct s_p		t_p;
typedef struct s_drect	t_drect;
typedef struct s_wnd	t_wnd;
typedef struct s_font	t_font;
typedef struct s_text	t_text;
typedef struct s_tex	t_tex;
typedef struct s_spri	t_spri;
typedef struct s_sprd	t_sprd;
typedef struct s_spribf	t_spribf;
typedef struct s_sprdbf	t_sprdbf;
typedef struct s_btn	t_btn;
typedef struct s_panel	t_panel;
typedef struct s_timer	t_timer;
typedef struct s_lprm	t_lprm;
typedef void			*(*t_fptr)(void);
typedef void			(*t_fvoid)();

enum		e_bool
{
	false,
	true
};

struct		s_v2d
{
	double	x;
	double	y;
};

struct		s_p
{
	int x;
	int y;
};

struct		s_drect
{
	double	x;
	double	y;
	double	w;
	double	h;
};

struct		s_wnd
{
	SDL_Window		*p;
	SDL_Renderer	*r;
	const char		*name;
	int				wid;
	int				hei;
};

struct		s_font
{
	const char	*fname;
	int			size;
	SDL_Color	fcol;
	SDL_Color	bcol;
};

struct		s_text
{
	t_font		f;
	TTF_Font	*font;
	SDL_Surface	*surf;
	SDL_Rect	loc;
};

struct		s_tex
{
	SDL_Renderer	*r;
	SDL_Texture		*t;
	int				w;
	int				h;
};

struct		s_spri
{
	t_tex		*tex;
	SDL_Rect	src;
	SDL_Rect	dest;
};

struct		s_sprd
{
	t_tex		*tex;
	SDL_Rect	src;
	t_v2d		dst;
	double		sx;
	double		sy;
};

struct		s_spribf
{
	t_tex	*tex;
	t_spri	**s_arr;
	int		sz;
};

struct		s_sprdbf
{
	t_tex	*tex;
	t_sprd	**s_arr;
	int		sz;
};

struct		s_btn
{
	SDL_Rect	dest;
	t_spri		*spr[2];
	void		*(*f_click)(void);
	enum e_btn	flags;
};

struct		s_panel
{
	SDL_Rect	pos;
	t_btn		**arr;
	int			px;
	int			py;
	int			dx;
	int			dy;
	int			sz;
};

struct		s_timer
{
	double	all_t;
	double	pau_t;
	double	cur_t;
	double	del_t;
	double	fra_t;
	int		frm;
};

struct		s_lprm
{
	t_wnd		*wnd;
	SDL_Event	e;
	t_bool		efl;
	const Uint8 *ks;
	t_p			ms_coord;
};

/*
** sdl_button.c
** sdl_button_array.c
*/
t_btn		*fsdl_btn_create(SDL_Rect *r, t_spri *s, t_spri *spr_alt, t_fptr f);
void		fsdl_btn_show(t_btn *b, SDL_Rect *dest);
int			fsdl_btn_mouse_over_check(int x, int y, t_btn *b);
void		fsdl_btn_state_set(t_btn *b, enum e_btn state);
t_btn		**fsdl_btn_create_2d_array(size_t row, size_t col);
/*
** fsdl_file_read.c
*/
char		*fsdl_file_read(const char *fn);
/*
** sdl_loop_prm.c
*/
t_lprm		*fsdl_lprm_create(void);
void		fsdl_loop_regular_operations(t_lprm *lprm);
/*
** sdl_panel.c
*/
t_panel		*fsdl_panel_create_empty(SDL_Rect pos, int wid, int hei);
t_btn		*fsdl_panel_mouse_check(t_panel *p, t_p pos);
void		fsdl_panel_show_all_btn(t_panel *p);
void		fsdl_panel_free_btn_free(t_panel *p, int btn_num);
/*
** sdl_project.c
*/
void		fsdl_project_exec(t_fvoid f, void *data);
void		fsdl_init(void);
SDL_GLTXT	fsdl_glcontext_create(t_wnd *wnd);
/*
** sdl_rect_set.c
** sdl_rect_convert.c
*/
SDL_Rect	fsdl_rect_set(int x, int y, int wid, int hei);
t_drect		fsdl_rect_double(double x, double y, double wid, double hei);
SDL_Rect	fsdl_rect_dbl_to_int(t_drect d);
t_drect		fsdl_rect_int_to_d(SDL_Rect r);
SDL_Rect	fsdl_rect_set_relative(SDL_Rect r, t_p pos, int wid, int hei);
t_drect		fsdl_rect_spr_dest_rel(t_spri *spr, t_drect sr);
SDL_Rect	fsdl_rect_wndrel(t_wnd *w, t_drect wr);
/*
** sdl_sprite_1_create.c
*/
t_spri		fsdl_sprite_int_create_stack(t_tex *tex, SDL_Rect spr);
t_spri		*fsdl_sprite_int_create_heap(t_tex *tex, SDL_Rect *src);
t_spri		*fsdl_sprite_int_create_from_file(SDL_Renderer *r, const char *fn);
void		fsdl_sprite_int_and_texture_free(t_spri *spr);
/*
** sdl_sprite_2_create.c
*/
t_sprd		*fsdl_sprite_dbl_create_heap(t_tex *tex, SDL_Rect *src);
t_sprd		*fsdl_sprite_dbl_create_from_file(SDL_Renderer *r, const char *fn);
void		fsdl_sprite_dbl_and_texture_free(t_sprd *spr);
void		fsdl_spr_dbl_to_point(t_wnd *w, t_sprd *spr, t_v2d pos, t_v2d sc);
/*
** sdl_sprite_buffer.c
*/
t_spribf	*fsdl_spr_buffer_create(t_tex *tex, SDL_Rect *rect_arr, int sz);
void		fsdl_spr_buffer_free(t_spribf *buf);
/*
** sdl_sprite_draw.c
*/
void		fsdl_sprite_wnd_box(t_wnd *w, t_spri *spr, t_drect *dst, int mode);
void		fsdl_sprite_show(t_spri *spr, SDL_Rect *dest, int mode);

/*
** sdl_surface.c
*/
SDL_Surface	*fsdl_create_surface(int w, int h);
void		fsdl_surface_fill(SDL_Surface *s, SDL_Color c);
void		fsdl_surface_px_alp(SDL_Surface *img, SDL_Color c, int x, int y);
void		fsdl_surface_px(SDL_Surface *img, SDL_Color c, int x, int y);
/*
** sdl_text_output.c
*/
t_text		fsdl_text_solid(t_font f, int x, int y);
void		fsdl_free_text(t_text *t);
t_font		fsdl_font_prm(const char *fn, int sz, SDL_Color fc, SDL_Color bc);
void		fsdl_put_text(t_text *t, const char *msg, SDL_Surface *img);
/*
** sdl_texture.c
*/
t_tex		*fsdl_texture_from_image_heap(SDL_Renderer *r, const char *fn);
t_tex		*fsdl_texture_free_heap(t_tex *tex);
/*
** sdl_timer.c
*/
t_timer		fsdl_timer_create(void);
void		fsdl_timer_calc_delta_and_frame(t_timer *t);
double		fsdl_timer_get_delta(t_timer *t);
/*
** sdl_window_create.c
** sdl_window_manage_prm.c
*/
t_wnd		*fsdl_window_create_stuct(int wid, int hei, const char *name);
void		fsdl_window_set_prm(t_wnd *wnd, int wid, int hei, const char *nm);
void		fsdl_window_create(t_wnd *wnd);
void		fsdl_window_and_renderer_create(t_wnd *wnd);
void		fsdl_window_get_dim(t_wnd *w);
void		fsdl_window_set_title(t_wnd *wnd);
void		fsdl_window_set_minimum_size(t_wnd *w, int min_w, int min_h);
/*
** sdl_error_management.c
*/
void		fsdl_errors_log(int err);

#endif
