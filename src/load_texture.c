//
// Created by Nymphadora Shelly on 28/01/2020.
//

#include "wolf3d.h"

/*
** **************************************************************************
**	t_texture *load_all_textures(t_player *pl)
**	Function to load textures
** **************************************************************************
*/

t_texture			*load_textures(t_player *pl)
{
	t_texture	*t_arr;

	pl->textures_nb = 11;
	if (!(t_arr = (t_texture *)malloc(sizeof(t_texture) * pl->textures_nb)))
	{
		ft_putstr_fd("Can't allocate memory for textures array.\n", 2);
		exit(EXIT_FAILURE);
	}
	t_arr[0] = texture_parse("Img_tga/texture_leaf_burch.tga");
	t_arr[1] = texture_parse("Img_tga/ivy.tga");
	t_arr[2] = texture_parse("Img_tga/marble.tga");
	t_arr[3] = texture_parse("Img_tga/rock.tga");
	t_arr[4] = texture_parse("Img_tga/rock1.tga");
	t_arr[5] = texture_parse("Img_tga/cosmos.tga");
	t_arr[6] = texture_parse("Img_tga/grid_black.tga");
	t_arr[7] = texture_parse("Img_tga/fence.tga");
	t_arr[8] = texture_parse("Img_tga/revolver0.tga");
	t_arr[9] = texture_parse("Img_tga/revolver1.tga");
	t_arr[10] = texture_parse("Img_tga/revolver2.tga");


	return (t_arr);
}
