#ifndef RC_TILEMAP_H_INCLUDED
#define RC_TILEMAP_H_INCLUDED

#include <irrlicht.h>
#include <vector>

struct rc_tile_obj
{
	int id;

	double fps;
	int num_frames;
	int current_frame;
	std::vector<int> frames;

	Uint32 frame_start_time;
	Uint32 frame_swap_time;
};

struct rc_tileset_obj
{
	bool active;

	int img_id;

	int tile_width;
	int tile_height;

	std::vector<rc_tile_obj> tiles;
};

struct rc_tilemap_row_obj
{
	std::vector<int> tile;
};

struct rc_tilemap_obj
{
	bool active;

	int tileset;
	irr::video::ITexture* texture;

	int num_tiles_across;
	int num_tiles_down;

	std::vector<rc_tilemap_row_obj> rows;
};

std::vector<rc_tileset_obj> rc_tileset;
std::vector<rc_tilemap_obj> rc_tilemap;

std::vector<int> rc_deleted_tileset;
std::vector<int> rc_deleted_tilemap;


#endif // RC_TILEMAP_H_INCLUDED
