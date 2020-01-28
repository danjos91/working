#ifndef WOLF3D_H
# define WOLF3D_H

# include "SDL2/SDL.h"
# include "SDL2/SDL_thread.h"
# include "SDL2/SDL_ttf.h"
# include "SDL2/SDL_image.h"
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <libft.h>
# include <sys/stat.h>
# include "constants.h"
# include "door.h"
# include "engine.h"
# include "events.h"
# include "help.h"
# include "player.h"
# include "sky.h"
# include "texture.h"
# include "textures.h"

/*			but_detect.c			*/
int			but_detect(t_player *pl);//return sec_nb of button

/*			but.c			*/
void		but_total(t_player *pl);//create buttons array
int			but_script(t_player *pl, int but_nb, t_sub_ev *se);//choose but task

/*			door_detect.c			*/
int			door_detect(t_player *pl);//return sec_nb of door

/*			door.c			*/
void		door_but_сlick(t_player *pl, t_sub_ev *se);//when you press E key or button
void		door(t_player *pl, t_sub_ev *se);//cycle for open door


/*			math_functions.c			*/
float		min(float a, float b);
float		max(float a, float b);
float		clamp(float a, float mi, float ma);
float		vxs(float x0, float y0, float x1, float y1);
int			Overlap(float a0, float a1, float b0, float b1);
int			IntersectBox(float x0, float y0, float x1, float y1,float x2, float y2, float x3, float y3);
float		PointSide(float px, float py, float x0, float y0,float x1, float y1);
t_xy		Intersect(float x1, float y1, float x2, float y2,float x3, float y3, float x4, float y4);
void		UnloadData();
void		MovePlayer(float dx, float dy, t_player *player);
float		Yaw(float y, float z, t_player *player);
double		to_deg(double radians);

/*			main.c			*/
int			main(int ac, char **ag);
void		player_init(t_player *pl, t_xy *v, float *angle, int *n);
void		vline(int x, int y1,int y2, int top,int middle,int bottom, SDL_Surface* surface);
/*			engine.c			*/
void		engine_begin(t_player *pl);
int			engine_scale(t_player *pl, int sx1, int sx2);

/*			engine_exp.c			*/
int			engine_cross(t_player *pl);
void		engine_put_lines(t_player *pl, int neib);

/*			events_1.c			*/
int			events(t_sub_ev *se, t_player *player);

/*			events_2.c			*/
void		events_mouse_move(t_mouse *ms, t_player *pl);
void		events_vel(t_player *pl, t_sub_ev *se, t_others *ot);
void		events_jumps(t_sub_ev *se, t_player *pl, t_sect_ops *op, t_others *ot);

/*			load_file.c			*/
t_player	*load_next(t_player *pl);
void		load_file(char *ag, t_player *pl);

/*			motion.c			*/
void		motion_chk(t_sect_ops *op, t_player *player, t_others *ot, t_sub_ev *se);
void		motion_move_pl(float dx, float dy, t_player *pl);


/*			texture_parser.c			*/
t_texture	texture_parse(const char *fp, unsigned edit);

/*			door.c			*/
void		door_button(t_player *pl, t_sub_ev *se);
void		door(t_player *pl, t_sub_ev *se);

/*			vector_1.c			*/
t_vector3	ft_vec3_create(t_vector3 *orig, t_vector3 *dest);
double		ft_vec3_magnitude(t_vector3 this);

/*			vector_2.c			*/
double		ft_vec3_dot_product(t_vector3 this, t_vector3 rhs);
t_vector3	ft_vec3_normalize(t_vector3 vtc);

/*          vectors_2.c*/
float	vec2_cos(t_vector3 vec1, t_vector3 vec2);

t_texture			*load_textures(t_player *pl);

#endif
