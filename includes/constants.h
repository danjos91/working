#ifndef CONSTANTS_H
# define CONSTANTS_H
# define WIN_W 1400
# define WIN_H 800
#define EYE_H  6
#define CROUCH_H 2.5
#define HEAD_H  1
#define NOT_JUMP_H 2
#define hfov (0.73f*WIN_H)
#define vfov (.2f*WIN_H)
#define MAX_QUEUE 32
#define MAX_DOORS 100
#define MAX_BUT 100

#endif

/*
 * CROUCH_H 2.5---And when crouching
 * HEAD_H  1---How much room there is above camera before the head hits the ceiling
 * NOT_JUMP_H 2---How tall obstacles the player can simply walk over without jumping
 * hfov (0.73f*WIN_H)---Affects the horizontal field of vision
 * vfov (.2f*WIN_H)---Affects the vertical field of vision
 * MAX_QUEUE 32---maximum number of pending portal renders (engine)
 * MAX_DOORS 100---maximum number of doors
 * MAX_BUT 100---maximum number of buttons
 */