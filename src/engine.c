/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:46:09 by drafe             #+#    #+#             */
/*   Updated: 2020/01/18 16:27:48 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static int engine_pick_sec(t_player *pl)
**	Function to pick a sector & slice from the queue to draw
** **************************************************************************
*/

static int	engine_pick_sec(t_player *pl)
{
	//Pick a sector & slice from the queue to draw
	pl->cycle.current = pl->cycle.tail;//const struct item now = *cycle.tail;
	if(++pl->cycle.tail == pl->cycle.queue + MAX_QUEUE)
		pl->cycle.tail = pl->cycle.queue;
	if(pl->cycle.rend_sec[pl->cycle.current->sec_nb] & 0x21)
		return (-2); // Odd = still rendering, 0x20 = give up
	++pl->cycle.rend_sec[pl->cycle.current->sec_nb];
	pl->sect = &pl->sectors[pl->cycle.current->sec_nb];//SECT CREATED
	return (-1);
}

/*
** **************************************************************************
**	static void engine_preset(t_player *pl)
**	Function to set up some arrays and lists for engine
** **************************************************************************
*/

static void	engine_preset(t_player *pl)
{
	int	i;
	int	*rend_sec;

	if ((i = -1) && !(rend_sec = (int *)malloc(sizeof(int) * (pl->sectors_nb + 1))))
	{
		ft_putstr_fd("engine_preset - malloc error.\n", 2);
		exit (EXIT_FAILURE);
	}
	while(++i < pl->sectors_nb)
		rend_sec[i] = 0;
	pl->cycle.rend_sec = rend_sec;
	i = -1;
	while(++i < WIN_W)
		pl->y_top[i] = 0;
	i = -1;
	while(++i < WIN_W)
		pl->y_bot[i] = WIN_H - 1;
	pl->cycle.head = pl->cycle.queue;
	pl->cycle.tail = pl->cycle.queue;
	pl->cycle.head->sec_nb = (int)pl->sector;
	pl->cycle.head->sx1 = 0;
	pl->cycle.head->sx2 = WIN_W - 1;
	if(++pl->cycle.head == pl->cycle.queue + MAX_QUEUE)
		pl->cycle.head = pl->cycle.queue;
}

/*
** **************************************************************************
**	int engine_scale(t_player *pl, int sx1, int sx2)
**	Function to scale floor & ceil
** **************************************************************************
*/

int		engine_scale(t_player *pl, int sx1, int sx2)/*perspective*/
{
	pl->scale_1.x = hfov / pl->t1.y;
	pl->scale_1.y = vfov / pl->t1.y;
	pl->scale_2.x = hfov / pl->t2.y;
	pl->scale_2.y = vfov / pl->t2.y;
	//Do perspective transformation
	pl->x1 = WIN_W / 2 - (int)(pl->t1.x * pl->scale_1.x);
	pl->x2 = WIN_W / 2 - (int)(pl->t2.x * pl->scale_2.x);
	//Project our ceiling & floor heights into screen coordinates (Y coordinate)
	pl->ceil.y1a = WIN_H / 2 - (int)(Yaw(pl->ceil.yceil, pl->t1.y, pl) * pl->scale_1.y);
	pl->floor.y1b = WIN_H / 2 - (int)(Yaw(pl->floor.yfloor, pl->t1.y, pl) * pl->scale_1.y);
	pl->ceil.y2a = WIN_H / 2 - (int)(Yaw(pl->ceil.yceil, pl->t2.y, pl) * pl->scale_2.y);
	pl->floor.y2b = WIN_H / 2 - (int)(Yaw(pl->floor.yfloor, pl->t2.y, pl) * pl->scale_2.y);
	//The same for the neighboring sector
	pl->ceil.ny1a = WIN_H / 2 - (int)(Yaw(pl->ceil.nyceil, pl->t1.y, pl) * pl->scale_1.y);
	pl->floor.ny1b = WIN_H / 2 - (int)(Yaw(pl->floor.nyfloor, pl->t1.y, pl) * pl->scale_1.y);
	pl->ceil.ny2a = WIN_H / 2 - (int)(Yaw(pl->ceil.nyceil, pl->t2.y, pl) * pl->scale_2.y);
	pl->floor.ny2b = WIN_H / 2 - (int)(Yaw(pl->floor.nyfloor, pl->t2.y, pl) * pl->scale_2.y);
	if(pl->x1 >= pl->x2 || pl->x2 < sx1 || pl->x1 > sx2)
		return (0);
	return (1);
}

/*
** **************************************************************************
**	void engine_begin(t_player *pl)
**	Function to start engine calculations and draw all lines
** **************************************************************************
*/

void	engine_begin(t_player *pl)
{
	int			neib;
	int			s;

	engine_preset(pl);
    while(pl->cycle.head != pl->cycle.tail)
	{
		if ((s = engine_pick_sec(pl)) == -2)
			continue;
		while (++s < pl->sect->npoints)
		{
		    pl->s = s;
			if (engine_cross(pl) == 0)
				continue;

			//Acquire the floor and ceiling heights, relative to where the player's view is
			pl->ceil.yceil = pl->sect->ceil - pl->where.z;
			pl->floor.yfloor = pl->sect->floor - pl->where.z;
			//Check the edge type. neighbor=-1 means wall, other=boundary between two sectors.
			neib = pl->sect->neighbors[s];
			if(neib >= 0) // Is another sector showing through this portal? This permit us draw other sectors after the one where we are
			{
				pl->ceil.nyceil  = pl->sectors[neib].ceil  - pl->where.z;
				pl->floor.nyfloor = pl->sectors[neib].floor - pl->where.z;
			}

			if (engine_scale(pl, pl->cycle.current->sx1, pl->cycle.current->sx2) == 0)
				continue; // Only render if it's visible
            pl->f = 0;
            if ( s < 1 && pl->sect->floor == 0)
            {
                pl->n = 0;
            }
            else if (pl->sect->floor == 6 && pl->sect->ceil == 10)
                pl->n = 7;
			else if (s == 4 && pl->sect->floor == 0)// && pl->sect->floor == 0)
                pl->n = 10;
                else
                pl->n = 2;
            engine_put_lines(pl, neib);//Render all.
		}
        ++pl->cycle.rend_sec[pl->cycle.current->sec_nb];
    }
}
