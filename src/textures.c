//
// Created by Nymphadora Shelly on 17/01/2020.
//

#include "wolf3d.h"

int			ft_get_pixel(SDL_Surface *sur, int x, int y)//no da el pixel que vamos a usar
{
    int		*pixel;

    pixel = sur->pixels + y * (sur->pitch ) + x * sur->format->BytesPerPixel;
    return (*pixel);
}

int			color_transoform(int color, float percent)
{
    int		rgb[4];

    rgb[0] = ((color >> 0) & 0xFF) * percent;
    rgb[1] = ((color >> 8) & 0xFF) * percent;
    rgb[2] = ((color >> 16) & 0xFF) * percent;
    rgb[3] = (color >> 24) & 0xFF *0;
    color = ( (rgb[3] << 24) | (rgb[2] << 16) | (rgb[1] << 8) | rgb[0] << 0);
    //printf("color %d\n", rgb[3]);
    return (color);
}


void		pix1(t_textures *t, t_player *pl, int n)//guarda la textura gun
{
    int *pix;

    pix = (int *)pl->srf->pixels;
        pix[t->y * WIN_W + t->x ] = color_transoform(ft_get_pixel(pl->img[n], t->txtx1 % pl->img[n]->w, t->txtz % pl->img[n]->h), pl->light);
}
