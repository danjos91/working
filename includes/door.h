#ifndef DOOR_H
# define DOOR_H

# include "wolf3d.h"

typedef struct	s_door
{
    int		s_nb;//door sector nb
    float	spd;//speed of lift door up or down
    int		max_d;//lift up while max_d
    int		min_d;//lift down while min_d
    int		state;//0-close 1-open
    int		key;//key id
}				t_door;

typedef struct	s_but
{
    int		s_nb;//button sector nb
    //float	spd;//speed of lift door up or down
    //int		max_d;//lift up while max_d
    //int		min_d;//lift down while min_d
    //state == 0 - do nothing, 1 - open door in that sector, 2-end level
    int		state;
    //int		key;//key id
}				t_but;

#endif
