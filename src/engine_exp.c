//**************************************************************************
//                                                                          
//                                                       :::      ::::::::  
//  engine_exp.c                                       :+:      :+:    :+:  
//                                                   +:+ +:+         +:+    
//  By: drafe <drafe@student.42.fr>                +#+  +:+       +#+       
//                                               +#+#+#+#+#+   +#+          
//  Created: 2020/01/10 21:27:28 by drafe             #+#    #+#            
//  Updated: 2020/01/12 19:03:44 by drafe            ###   ########.fr      
//                                                                          
//**************************************************************************

#include "wolf3d.h"

/*
** **************************************************************************
**	int engine_cross(t_player *pl, int sec_n, unsigned s)
**	Function to find intersections and set t1 & t2
**	t1.y was tz1 before recontruction
** **************************************************************************
*/
void	xy_vertex_of_sectors(t_xy *v_start, t_xy *v_end, t_player *pl)
{
	v_start->x = pl->sectors[pl->cycle.current->sec_nb].vertex[pl->s + 0].x - pl->where.x;
	v_start->y = pl->sectors[pl->cycle.current->sec_nb].vertex[pl->s + 0].y - pl->where.y;
	v_end->x = pl->sectors[pl->cycle.current->sec_nb].vertex[pl->s + 1].x - pl->where.x;
	v_end->y = pl->sectors[pl->cycle.current->sec_nb].vertex[pl->s + 1].y - pl->where.y;

	pl->t1.x = v_start->x * pl->anglesin - v_start->y * pl->anglecos;
	pl->t1.y = v_start->x * pl->anglecos + v_start->y * pl->anglesin;
	pl->t2.x = v_end->x * pl->anglesin - v_end->y * pl->anglecos;
	pl->t2.y = v_end->x * pl->anglecos + v_end->y * pl->anglesin;
}
/*
 * Acquire the x,y coordinates of the two endpoints (vertices) of this edge of the sector
 * also rotate them around the player's view
 */

int			engine_cross(t_player *pl)
{
	t_xy	i1;
	t_xy	i2;
	t_xy	v_start;
	t_xy	v_end;

	xy_vertex_of_sectors(&v_start, &v_end, pl);
	//Is the wall at least partially in front of the player?
	if((pl->t1.y <= 0) && (pl->t2.y <= 0))
		return (0);//continue
	pl->u0 = 0;
	pl->u1 = 3000;//if the number is higher, the number or images in walls is going to be more
	//If it's partially behind the player, cut it against player's view
	if((pl->t1.y <= 0) || (pl->t2.y <= 0))
	{
		i1 = Intersect(pl->t1.x, pl->t1.y, pl->t2.x, pl->t2.y, -pl->nearside, pl->nearz, -pl->farside, pl->farz);
		i2 = Intersect(pl->t1.x, pl->t1.y, pl->t2.x, pl->t2.y, pl->nearside, pl->nearz, pl->farside, pl->farz);

		pl->org1.x = pl->t1.x;
		pl->org1.y = pl->t1.y;
		pl->org2.x = pl->t2.x;
		pl->org2.y = pl->t2.y;
		(pl->t1.y < pl->nearz && i1.y > 0) ? pl->t1 = i1 : pl->t1;
		(pl->t1.y < pl->nearz && i1.y < 0) ? pl->t1 = i2 : pl->t1;
		(pl->t2.y < pl->nearz && i1.y > 0) ? pl->t2 = i1 : pl->t2;
		(pl->t2.y < pl->nearz && i1.y < 0) ? pl->t2 = i2 : pl->t2;


        /*EXTRA CALCS FOR WALLS*/
        if (fabsf(pl->t2.x - pl->t1.x) > fabsf(pl->t2.y - pl->t1.y)) {
            pl->u0 =  ((pl->t1.x - pl->org1.x) * 3000 / (pl->org2.x - pl->org1.x));
            pl->u1 =  ((pl->t2.x - pl->org1.x) * 3000/ (pl->org2.x - pl->org1.x));
        } else {
            pl->u0 =  ((pl->t1.y - pl->org1.y) * 3000/
                        (pl->org2.y - pl->org1.y));
            pl->u1 =  ((pl->t2.y - pl->org1.y) * 3000/
                        (pl->org2.y - pl->org1.y));
            printf("w %d\n", pl->srf->w);
        }
	}
	return (1);
}

/*
** **************************************************************************
**	static void engine_ceil_floor(t_player *pl, int x, int *z, int neib)
**	Function to draw ceil and floor lines and lines betwen them
** **************************************************************************
*/

void engine_calcs(int x, t_player *pl, int operation)
{
	if (operation == 0)
	{
		pl->txtx = (int)((pl->u0 * ((pl->x2 - x) * pl->t2.y) + pl->u1 * ((x - pl->x1) * pl->t1.y)) / ((pl->x2 - x) * pl->t2.y + (x - pl->x1) * pl->t1.y));
		pl->floor.ya = (x - pl->x1) * (pl->ceil.y2a - pl->ceil.y1a) / (pl->x2 - pl->x1) + pl->ceil.y1a;
		pl->ceil.cya = clamp(pl->floor.ya, pl->y_top[x], pl->y_bot[x]);// top
		pl->floor.yb = (x - pl->x1) * (pl->floor.y2b - pl->floor.y1b) / (pl->x2 - pl->x1) + pl->floor.y1b;
		pl->ceil.cyb = clamp(pl->floor.yb, pl->y_top[x], pl->y_bot[x]);// bottom
	}
	if (operation == 1)
	{
		pl->t.hei = pl->t.y < pl->ceil.cya ? pl->ceil.yceil : pl->floor.yfloor;
		pl->t.mapz = pl->t.hei * WIN_H * V_FOV / ((WIN_H / 2 - (float)pl->t.y) - pl->yaw * WIN_H * V_FOV);
		pl->t.mapx = pl->t.mapz * (WIN_W/2 - (float)pl->t.x) / (WIN_W * (H_FOV));
		pl->t.txtx1 = (unsigned int)(((pl->t.mapz * pl->anglecos + pl->t.mapx * pl->anglesin) + pl->where.x) * 256);
		pl->t.txtz = (unsigned int)(((pl->t.mapz * pl->anglesin - pl->t.mapx * pl->anglecos) + pl->where.y) * 256);
	}
	if (operation == 2)
	{
		pl->floor.nya = (x - pl->x1) * (pl->ceil.ny2a - pl->ceil.ny1a) / (pl->x2 - pl->x1) + pl->ceil.ny1a;
		pl->ceil.cnya = clamp(pl->floor.nya, pl->y_top[x], pl->y_bot[x]);
		pl->floor.nyb = (x - pl->x1) * (pl->floor.ny2b - pl->floor.ny1b) / (pl->x2 - pl->x1) + pl->floor.ny1b;
		pl->ceil.cnyb = clamp(pl->floor.nyb, pl->y_top[x], pl->y_bot[x]);
		pl->y_top[x] = clamp(max(pl->ceil.cya, pl->ceil.cnya), pl->y_top[x], WIN_H-1);   // Shrink the remaining window below these ceilings
		pl->y_bot[x] = clamp(min(pl->ceil.cyb, pl->ceil.cnyb), 0, pl->y_bot[x]); // Shrink the remaining window above these floors
	}
}

void draw_ceil_floor(int x, t_player *pl)
{
	pl->t.y = pl->y_top[x];
	pl->t.x = x;
	while (++pl->t.y <= pl->y_bot[x])//HERE we draw ceil and floor
	{
		if (pl->t.y >= pl->ceil.cya && pl->t.y <= pl->ceil.cyb)
		{
			pl->t.y = pl->ceil.cyb;
			continue;
		}
		engine_calcs(x, pl, 1);
		if (pl->t.y < pl->ceil.cya && pl->sect->ceil != 20)//pl->s != 0)// && pl->s != 1)
			pix1(&pl->t, pl, pl->f);
		if (pl->t.y < pl->ceil.cya && pl->sect->ceil == 20)
			pix_sky(&pl->t, pl);
		if (pl->t.y >= pl->ceil.cya)// && pl->s != 0 && pl->s != 1)
			pix1(&pl->t, pl, FLOOR);
	}
}

static void	engine_ceil_floor(t_player *pl, int x, int neib)
{
	engine_calcs(x, pl, 0);
    draw_ceil_floor(x, pl);
	if(neib >= 0)
	{
		engine_calcs(x, pl, 2);
        draw_walls(x, pl, WALL_TOP, pl->n);
        draw_walls(x, pl, WALL_BOTT, pl->n);
    }
	else
        draw_walls(x, pl, WALL_FULL, pl->n);
}
/*
** **************************************************************************
**	void engine_ceil_floor(t_player *pl, int neib)
**	Function to draw all needed lines
** **************************************************************************
*/

void		engine_put_lines(t_player *pl, int neib)
{
	int			x;

	pl->beginx = (int)fmax((double)pl->x1, (double)pl->cycle.current->sx1);
	pl->endx = (int)fmin((double)pl->x2, (double)pl->cycle.current->sx2);
	x = pl->beginx;

	while (++x <= pl->endx)
		engine_ceil_floor(pl, x, neib);//ceil floor and some walls
	if(neib >= 0 && pl->endx >= pl->beginx && (pl->cycle.head + MAX_QUEUE + 1 - pl->cycle.tail) % MAX_QUEUE)
	{
		pl->cycle.head->sec_nb = neib;
		pl->cycle.head->sx1 = pl->beginx;
		pl->cycle.head->sx2 = pl->endx;
		if(++pl->cycle.head == pl->cycle.queue + MAX_QUEUE)
			pl->cycle.head = pl->cycle.queue;
	}
}
