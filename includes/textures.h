//
// Created by Nymphadora Shelly on 17/01/2020.
//

#ifndef UNTITLED2_TEXTURES_H
#define UNTITLED2_TEXTURES_H
# define H_FOV					(1.0 * 0.73f * WIN_H / WIN_W)
# define V_FOV					(1.0 * .2f)
# define CEIL   0
# define CEI2  6
# define FLOOR  1
# define WALL1   2
# define WALL2   3
# define GRAFFITI 5

#include "wolf3d.h"

typedef struct s_textures
{
    float hei;
    float mapx;
    float mapz;
    unsigned txtx1;
    unsigned txtz;
    int x;
    int y;
}               t_textures;

typedef struct			s_scaler
{
    int					result;
    int					bop;
    int					fd;
    int					ca;
    int					cache;
}						t_scaler;

void		draw_cur_pistol_sprite(t_weapons *wpn, int width, int height, int cur_sprite, SDL_Surface *surface);
void		load_weapons(t_weapons *wpn);
void		load_pistol(t_weapons *wpn);
int			load_pistol_sprite(t_weapons *wpn, int sprite_count);
SDL_Surface		*load_pistol_part(int sprite);
//void			draw_pistol(t_weapons *wpn, t_player * pl);

void vline_walls(int x, t_player *pl, t_scaler ty, int n);
t_scaler	scalar_create(int a, int b, int c, int d, int f);
int			scr_nxt(t_scaler *i);
int			color_transoform(int color, float percent);
int			ft_get_pixel(SDL_Surface *sur, int x, int y);
//void		draw_ceil_floor(t_draw_screen_calc *ds, t_player *p, t_tex_i tex_i, t_game *g);
void		pix1(t_textures *t, t_player *pl, int n);
void        load_imgs(SDL_Surface *img[10]);//load images
void vline_graffiti(int x, t_player *pl, t_scaler ty, int n);
#endif //UNTITLED2_TEXTURES_H
