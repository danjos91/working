//
// Created by danny on 26.01.2020.
//

#ifndef DOOM42_SKY_H
#define DOOM42_SKY_H

#include "wolf3d.h"
#include "textures.h"

typedef struct	s_xy_int
{
    int	x;
    int	y;
}				t_xy_int;

int			load_sky(t_player * pl);
void		pix_sky(t_textures *t, t_player *pl);

#endif
