#ifndef PLAYER_H
#define PLAYER_H
# include "wolf3d.h"

typedef struct	s_player
{
	SDL_Surface	*srf;
	SDL_Surface *img[10];
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
	int			neib;
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
	int         u0;// "
	int         u1;// "
	float       org1x;
	float       org1y;
	float       org2x;
	float       org2y;
	float       light;
	int       y1;
	int       y2;

}				t_player;

#endif
