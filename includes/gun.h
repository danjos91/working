//
// Created by Nymphadora Shelly on 13/01/2020.
//

#ifndef UNTITLED2_GUN_H
#define UNTITLED2_GUN_H

#include "wolf3d.h"

typedef	struct			s_weapons
{
    int					pistol_sprite[6][128][128];
    int					***lighter_sprite;
    int					type;
    double				sprite_counter;
}						t_weapons;


void		draw_cur_pistol_sprite(t_weapons *wpn, int width, int height, int cur_sprite, SDL_Surface *surface);
void		load_weapons(t_weapons *wpn);
void		load_pistol(t_weapons *wpn);
int			load_pistol_sprite(t_weapons *wpn, int sprite_count);
SDL_Surface		*load_pistol_part(int sprite);
void			draw_pistol(t_weapons *wpn, SDL_Surface *surface);

#endif //UNTITLED2_GUN_H
