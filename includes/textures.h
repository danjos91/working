//
// Created by Nymphadora Shelly on 17/01/2020.
//

#ifndef UNTITLED2_TEXTURES_H
#define UNTITLED2_TEXTURES_H

#include "wolf3d.h"

# define H_FOV					(1.0 * 0.73f * WIN_H / WIN_W)
# define V_FOV					(1.0 * .2f)
# define FLOOR  1
# define WALL_FULL 2
# define WALL_TOP  0
# define WALL_BOTT 1


typedef	struct			s_gun
{
	int					pistol_sprite[6][128][128];
	int					type;
	double				sprite_counter;
	int                 w;
	int                 h;
}						t_gun;



typedef struct			s_scaler
{
    int					result;
    int					bop;
    int					fd;
    int					ca;
    int					cache;
}						t_scaler;

void		draw_cur_pistol_sprite(t_gun *wpn, int width, int height, int cur_sprite, SDL_Surface *surface);
void		load_pistol(t_gun *wpn);
int			load_pistol_sprite(t_gun *wpn, int sprite_count);
SDL_Surface		*load_pistol_part(int sprite);
void			draw_pistol(t_gun *wpn, t_player *pl);

void draw_walls(int x, t_player *pl, int wall, int n);
t_scaler	scalar_create(int a, int b, int c, int d, int f);
int			scr_nxt(t_scaler *i);
int			color_transoform(int color, float percent);
int			ft_get_pixel(SDL_Surface *sur, int x, int y);
void		pix1(t_textures *t, t_player *pl, int n);
void        load_imgs(SDL_Surface *img[10]);//load images
void vline_graffiti(int x, t_player *pl, t_scaler ty, int n);
void    draw_ceil_floor(int x, t_player *pl);

#endif //UNTITLED2_TEXTURES_H
