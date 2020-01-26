//
// Created by Nymphadora Shelly on 04/12/2019.
//
#include "wolf3d.h"

void player_init(t_player *pl, t_xy *v, float *angle, int *n)//init data for LoadData function
{
    //player = (struct player) { {v->x, v->y, 0}, {0,0,0}, *angle,0,0,0, n };
    pl->where.x = v->x;
    pl->where.y = v->y;
    pl->where.z = 0;
    pl->velocity.x = 0;
    pl->velocity.y = 0;
    pl->velocity.z = 0;
    pl->angle = *angle;
    pl->anglesin = 0;
    pl->anglecos = 0;
    pl->yaw = 0;
    pl->sector = *n;
	pl->ceil.nyceil = 0;
	pl->floor.nyfloor = 0;
	//If it's partially behind the player, clip it against player's view frustrum
	pl->nearz = 1e-4f;
	pl->farz = 5;
	pl->nearside = 1e-5f;
	pl->farside = 20.f;
	//pl->door_all = -1;
    pl->light = 1;
}

void LoadData(char *ag, t_player *pl)//this function reads a new map format
{
    FILE* fp = fopen(ag, "rt");
    if(!fp) { perror(ag); exit(EXIT_FAILURE); }
    char Buf[256];
    char word[256];
    char *ptr;
    float angle;
    t_xy *vert = NULL;//, v;
    t_xy v;
    int n;
    int m;
    static int p;//the first time is 0. Is a rule for all statics variables
    int NumVertices = 0;
    while(fgets(Buf, sizeof Buf, fp))
        switch(sscanf(ptr = Buf, "%32s%n", word, &n) == 1 ? word[0] : '\0')
        {
            case 'v': // vertex
                for(sscanf(ptr += n, "%f%n", &v.y, &n); sscanf(ptr += n, "%f%n", &v.x, &n) == 1; )
                { vert = realloc(vert, ++NumVertices * sizeof(*vert)); vert[NumVertices-1] = v; }
                break;
            case 's': // sector
                if(p == 0)
                {
                    pl->sectors = malloc(pl->sectors_nb * sizeof(*pl->sectors));//allocate memory if first time
                    p++;
                }
                pl->sectors = realloc(pl->sectors, ++pl->sectors_nb * sizeof(*pl->sectors));//reallocate memory
                t_sector  *sect = &pl->sectors[pl->sectors_nb - 1];//SECT CREATED
                int* num = NULL;
                sscanf(ptr += n, "%f%f%n", &sect->floor,&sect->ceil, &n);
                for(m=0; sscanf(ptr += n, "%32s%n", word, &n) == 1 && word[0] != '#'; )
                { num = realloc(num, ++m * sizeof(*num)); num[m-1] = word[0]=='x' ? -1 : atoi(word); }
                sect->npoints   = m /= 2;
                sect->neighbors = malloc( (m  ) * sizeof(*sect->neighbors) );
                sect->vertex    = malloc( (m+1) * sizeof(*sect->vertex)    );
                for(n=0; n<m; ++n) sect->neighbors[n] = num[m + n];
                for(n=0; n<m; ++n) sect->vertex[n+1]  = vert[num[n]]; // TODO: Range checking
                sect->vertex[0] = sect->vertex[m]; // Ensure the vertexes form a loop
                free(num);
                break;
            case 'p':; // player

                sscanf(ptr += n, "%f %f %f %d", &v.x, &v.y, &angle,&n);
                player_init(pl, &v, &angle, &n); // TODO: Range checking
                pl->where.z = pl->sectors[pl->sector].floor + EyeHeight;
        }
    fclose(fp);
    free(vert);
}

void UnloadData(t_player *pl)
{
    for(int a=0; a < pl->sectors_nb; ++a) free(pl->sectors[a].vertex);
    for(int a=0; a < pl->sectors_nb; ++a) free(pl->sectors[a].neighbors);
    free(pl->sectors);
    pl->sectors = NULL;
    pl->sectors_nb = 0;
}

//vline: Draw a vertical line on screen, with a different color pixel in top & bottom
void vline(int x, int y1,int y2, int top,int middle,int bottom, SDL_Surface* surface)
{
    int	*pix;

	pix = (int*)surface->pixels;
    y1 = clamp(y1, 0, WIN_H - 1);
    y2 = clamp(y2, 0, WIN_H - 1);
    if(y2 == y1)
        pix[y1* WIN_W + x] = middle;
    else if(y2 > y1)
    {
        pix[y1 * WIN_W + x] = top;
        //for(int y= y1 + 1; y < y2; ++y)
          //  pix[y * WIN_W + x] = middle;
        pix[y2 * WIN_W + x] = bottom;
    }
}
//MovePlayer(dx,dy): Moves the player by (dx,dy) in the map, and
//also updates their anglesin/anglecos/sector properties properly.

void MovePlayer(float dx, float dy, t_player *pl)
{
    float px = pl->where.x;
    float py = pl->where.y;
    //Check if this movement crosses one of this sector's edges
    //that have a neighboring sector on the other side.
    //Because the edge vertices of each sector are defined in
    //clockwise order, PointSide will always return -1 for a point
    //that is outside the sector and 0 or 1 for a point that is inside.
    
    const t_sector * const sect = &pl->sectors[pl->sector];
    const t_xy* const vert = sect->vertex;
    for(int s = 0; s < sect->npoints; ++s)
        if(sect->neighbors[s] >= 0
           && IntersectBox(px,py, px+dx,py+dy, vert[s+0].x, vert[s+0].y, vert[s+1].x, vert[s+1].y)
           && PointSide(px+dx, py+dy, vert[s+0].x, vert[s+0].y, vert[s+1].x, vert[s+1].y) < 0)
        {
            pl->sector = sect->neighbors[s];
            break;
        }

    pl->where.x += dx;
    pl->where.y += dy;
    pl->anglesin = sinf(pl->angle);
    pl->anglecos = cosf(pl->angle);
}

int main(int ac, char **ag)
{
    t_subevents se;
    t_mouse ms;
    t_player pl;
    t_others ot;
    t_sector_ops op;
//	t_wolf3d w;
	t_weapons wpn;
///	SDL_Surface *scr_surf = NULL;

	pl.sectors_nb = 0;
  //  w.weapon_texture = SDL_LoadBMP("Textures/pistol.bmp");
    if (ac < 2 || ac > 2)
    {
        printf("map error");
        return (0);
    }
    se.quit = 0;
    LoadData(ag[1], &pl);//load map and init typedef t_player data
    //ft_init_anim(&w);//gun
    SDL_Window* window = NULL;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_W, WIN_H, SDL_WINDOW_SHOWN );
        SDL_SetWindowOpacity( window, 1.0f);

        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
            {
            pl.srf = SDL_GetWindowSurface(window);
			
            SDL_UpdateWindowSurface( window );
            SDL_ShowCursor(SDL_DISABLE);//NOT SHOW MOUSE CURSOR
            se.wsad[0] = 0;
            se.wsad[1] = 0;
            se.wsad[2] = 0;
            se.wsad[3] = 0;
            se.wsad[5] = 0;
            se.falling = 1;
            pl.count_sprite = 1;
            se.ground = 0;
            ot.moving = 0;
            se.ducking = 0;
            ms.yaw = 0;
            //load_weapons(&wpn);
            wpn.sprite_counter = 1;//if !1 is going to shoot
            load_pistol(&wpn);//load gun
            load_imgs(pl.img);
            load_sky(&pl);
            while (!se.quit)
            {
                pl.txtx = 0;

                //SDL_BlitSurface(pl.img[3], ft_create_rect(WIN_W, WIN_H, 0, 0), pl.srf, ft_create_rect(0, 0, 0, 0));
                //SDL_BlitSurface(w.weapon_texture, ft_create_rect(15, 15, 0, 0), pl.srf, ft_create_rect(WIN_W, WIN_H, WIN_W, WIN_H));
				//draw_sky(&pl);
                engine_begin(&pl);
				
//				scr_surf = SDL_GetWindowSurface(window);

				//SDL_BlitSurface(pl.img[4], ft_create_rect(15, 15, 0, 0), pl.srf, ft_create_rect(50, 50, WIN_H/2, WIN_W/2));
				if (pl.count_sprite == 10)// this for the event shoot
				{
                    wpn.sprite_counter = 2;
                    pl.count_sprite = 1;
				}
				draw_pistol(&wpn,&pl);//draw gun
                SDL_UpdateWindowSurface( window );

                //Vertical collision detection
                op.eyeheight = se.ducking ? DuckHeight : EyeHeight;
                se.ground = !se.falling;
                jumps(&se, &pl, &op, &ot);
                sectors_ops(&op, &pl, &ot, &se);
                if (!events(&se, &pl))
                    return(0);
                mouse_movement(&ms, &pl);//mouse aiming
                vectors_vel_dir(&pl, &se, &ot);
                MovePlayer(0, 0, &pl);//Refresh Vectors. start movement in 0//if this line is in vectors_vel_dir slomaet programmy whe is running, is needed here
            	//door(&pl, &se);
			}
			
            UnloadData(&pl);
            SDL_Quit();
        }
    }
    return 0;
}
