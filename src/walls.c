//
// Created by Nymphadora Shelly on 20/01/2020.
//

#include "wolf3d.h"

void load_imgs(SDL_Surface *img[10])
{
    img[0]= IMG_Load("Textures/wall1.png");
    img[0]= SDL_ConvertSurfaceFormat(img[0], SDL_PIXELFORMAT_RGB888, 0);
    img[1]= IMG_Load("Textures/wood.png");
    img[1]= SDL_ConvertSurfaceFormat(img[1], SDL_PIXELFORMAT_RGB888, 0);
    img[2]= IMG_Load("Textures/wall2.png");
    img[2]= SDL_ConvertSurfaceFormat(img[2], SDL_PIXELFORMAT_RGB888, 0);
    img[3]= IMG_Load("Textures/wood.png");
    img[4]= IMG_Load("Textures/wood.png");
    img[5]= IMG_Load("Textures/wood.png");
    img[6]= IMG_Load("Textures/wood.png");
    img[7]= IMG_Load("Textures/wood.png");
    img[8]= IMG_Load("Textures/wood.png");
    img[9]= IMG_Load("Textures/wood.png");
}

t_scaler	scalar_create(int a, int b, int c, int d, int f)
{
    t_scaler	s;

    s.result = d + (b - 1 - a) * (f - d) / (c - a);
    s.bop = ((f < d) ^ (c < a)) ? -1 : 1;
    s.fd = abs(f - d);
    s.ca = abs(c - a);
    s.cache = (int)((b - 1 - a) * abs(f - d)) % abs(c - a);
    return (s);
}

int			scr_nxt(t_scaler *i)
{
    i->cache += i->fd;
    while (i->cache >= i->ca)
    {
        i->result += i->bop;
        i->cache -= i->ca;
    }
    return (i->result);
}

void vline_walls(int x, t_player *pl, t_scaler ty, int n)
{
    unsigned	txty;
    int			y;
    int         *pix;

    y = pl->y1;
    pix = (int*)pl->srf->pixels;
    pl->y1 = clamp(pl->y1, 0, WIN_H-1);
    pl->y2 = clamp(pl->y2, 0, WIN_H-1);
    pix += pl->y1 * WIN_W + x;
    while (y <= pl->y2)
    {
        ++y;
        txty = scr_nxt(&ty);
        *pix = color_transoform( ft_get_pixel(
               pl->img[n],
               pl->txtx % pl->img[n]->w,
               txty % pl->img[n]->h), pl->light);
        pix += WIN_W ;
    }
}
