#ifndef PLAYER_H
#define PLAYER_H

# include "wolf3d.h"
#include "texture.h"


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

typedef struct	s_player
{
	SDL_Surface	*srf;
    SDL_Window	*win;
	SDL_Surface *img[10];
	char        *lvl;
	t_xy		t1;
	t_xy		t2;
	t_xy		scale_1;
	t_xy		scale_2;
    t_xyz		where;      // Current position
    t_xyz		velocity;   // Current motion vector
    float		angle;
    float		anglesin;
    float		anglecos;
    float		yaw;   // Looking towards (and sin() and cos() thereof)
    unsigned	sector;// Which sector the player is currently in
	int			sectors_nb;//Sectors number
    t_sector	*sectors;
	t_cycle		cycle;//one draw_screen cycle
	t_sector	*sect;//current sector
	int			door_all;//how much doors
	int			door_nb;//door near with player
	t_door      *doors;
	int         but_all;
	t_but       *buttons;
	t_ceil		ceil;
	t_floor		floor;
	float		nearz;
	float		farz;
	float		nearside;
	float		farside;
	float		x1;
	float		x2;
	int			y_top[WIN_W];
	int			y_bot[WIN_W];
	int			beginx;
	int			endx;
	int         count_sprite;//for start animation
    int         txtx;//need for walls
	float         u0;// "
	float         u1;
	t_xy 		org1;
	t_xy 		org2;
	float       light;
	int         y1;
	int         y2;
	int         s;
	int         n;
	int         f;
	int         **sky_pix;
	t_textures	t;
	t_texture   *tex;
	int			textures_nb;


}				t_player;

#endif
