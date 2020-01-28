//
// Created by danny on 26.01.2020.
//
#include "wolf3d.h"

int			load_sky(t_player * pl)
{
    SDL_Surface *sky;
    unsigned int *pixels;
    int x;
    int y;

    sky = pl->img[3];
    pl->sky_pix = (int **)malloc(sizeof(int *) * sky->h);
    y = 0;
    while (y < sky->h)
    {
        pl->sky_pix[y] = (int *)malloc(sizeof(int) * sky->w);
        y++;
    }
    y = -1;
    pixels = (unsigned int *) sky->pixels;
    while (++y < sky->h) {
        x = -1;
        while (++x < sky->h)
            pl->sky_pix[y][x] = pixels[(y * sky->w) + x];
    }
    SDL_FreeSurface(sky);
    return (1);
}

void		draw_sky(t_player *pl)
{

    int		x_img;
    int     *pix;
    t_xy_int    pos;
    t_xy    num;
    t_xy_int   start;
    start.y = 0;
    start.x = 0;

    pix = (int*)pl->srf->pixels;
    num.y = 0;
    pos.y = 0;
    (void)((pos.y *= 0 | (int)(num.y *= 0)));
    while (pos.y < pl->img[3]->h && start.y < WIN_H)
    {
        pos.x = 0;
        num.x = 0;
        x_img = start.x ;
        while (pos.x < pl->img[3]->w - 1 && x_img < WIN_W)
        {
            num.x += 1.0f;//width of the gun and hand
            pos.x = (int)num.x;
            if (pl->sky_pix[(pos.y)][pos.x] != 0x000000)
                pix[start.y* WIN_W + x_img] =
                        color_transoform(pl->sky_pix[pos.y][pos.x], 1);
            x_img++;
        }
        num.y += 1.0f;
        pos.y = (int)num.y;
        start.y++;
    }
}

void		pix_sky(t_textures *t, t_player *pl)//guarda la textura gun
{
    int *pix;

    pix = (int *)pl->srf->pixels;
    pix[t->y * WIN_W + t->x] = pl->sky_pix[t->y][t->x];
}