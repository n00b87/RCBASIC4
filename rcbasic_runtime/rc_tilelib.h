#ifndef RC_TILELIB_H_INCLUDED
#define RC_TILELIB_H_INCLUDED

#ifdef RC_ANDROID
	#include "SDL.h"
#else
	#include <SDL2/SDL.h>
#endif // _IRR_ANDROID_PLATFORM_

#include "rc_tilemap.h"
#include "rc_gfx_core.h"


int rc_createTileSet(int img_id, int tile_w, int tile_h)
{
	if(img_id < 0 || img_id >= rc_image.size())
		return -1;

	if(!rc_image[img_id].image)
		return -1;

	rc_tileset_obj tset;

	tset.active = true;
	tset.img_id = img_id;

	tset.tile_width = tile_w;
	tset.tile_height = tile_h;

	int num_tiles = ((int)rc_image[img_id].image->getSize().Width / tile_w) * ((int)rc_image[img_id].image->getSize().Height / tile_h);
	tset.tiles.resize(num_tiles);

	for(int i = 0; i < tset.tiles.size(); i++)
	{
		tset.tiles[i].frames.push_back(i);
		tset.tiles[i].fps = 0;
		tset.tiles[i].frame_swap_time = 0;
		tset.tiles[i].frame_start_time = 0;
	}

	int tset_id = rc_tileset.size();

	if(rc_deleted_tileset.size() > 0)
	{
		tset_id = rc_deleted_tileset[0];
		rc_deleted_tileset.erase(rc_deleted_tileset.begin());
		rc_tileset[tset_id] = tset;
	}
	else
		rc_tileset.push_back(tset);

	return tset_id;
}

void rc_deleteTileSet(int tileset)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return;

	if(!rc_tileset[tileset].active)
		return;

	rc_tileset[tileset].tiles.clear();
	rc_tileset[tileset].img_id = -1;
	rc_tileset[tileset].active = false;

	rc_deleted_tileset.push_back(tileset);
}

void rc_setTileAnimationLength(int tileset, int base_tile, int num_frames)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return;

	if(!rc_tileset[tileset].active)
		return;

	if(base_tile < 0 || base_tile >= rc_tileset[tileset].tiles.size())
		return;

	rc_tileset[tileset].tiles[base_tile].frames.resize(num_frames);
	rc_tileset[tileset].tiles[base_tile].num_frames = num_frames;
}

int rc_getTileAnimationLength(int tileset, int base_tile)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return 0;

	if(!rc_tileset[tileset].active)
		return 0;

	if(base_tile < 0 || base_tile >= rc_tileset[tileset].tiles.size())
		return 0;

	return rc_tileset[tileset].tiles[base_tile].num_frames;
}

void rc_setTileAnimationFrame(int tileset, int base_tile, int anim_frame, int tile_frame)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return;

	if(!rc_tileset[tileset].active)
		return;

	if(base_tile < 0 || base_tile >= rc_tileset[tileset].tiles.size())
		return;

	rc_tileset[tileset].tiles[base_tile].frames[anim_frame] = tile_frame;
}

int rc_getTileAnimationFrame(int tileset, int base_tile, int anim_frame)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return -1;

	if(!rc_tileset[tileset].active)
		return -1;

	if(base_tile < 0 || base_tile >= rc_tileset[tileset].tiles.size())
		return -1;

	return rc_tileset[tileset].tiles[base_tile].frames[anim_frame];
}


void rc_setTileAnimationSpeed(int tileset, int base_tile, double speed)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return;

	if(!rc_tileset[tileset].active)
		return;

	if(base_tile < 0 || base_tile >= rc_tileset[tileset].tiles.size())
		return;

	rc_tileset[tileset].tiles[base_tile].fps = speed;
	rc_tileset[tileset].tiles[base_tile].frame_swap_time = 1000/speed;
}

double rc_getTileAnimationSpeed(int tileset, int base_tile)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return 0;

	if(!rc_tileset[tileset].active)
		return 0;

	if(base_tile < 0 || base_tile >= rc_tileset[tileset].tiles.size())
		return 0;

	return rc_tileset[tileset].tiles[base_tile].fps;
}


//--------------------------------------TILEMAP-----------------------------------------------
int rc_createTileMap(int tileset, int widthInTiles, int heightInTiles)
{
	if(tileset < 0 || tileset >= rc_tileset.size())
		return -1;

	if(!rc_tileset[tileset].active)
		return -1;

	rc_tilemap_obj tilemap;

	tilemap.active = true;
	tilemap.texture = NULL;
	tilemap.tileset = tileset;

	tilemap.num_tiles_across = widthInTiles;
	tilemap.num_tiles_down = heightInTiles;

	tilemap.rows.resize(heightInTiles);
	for(int i = 0; i < tilemap.rows.size(); i++)
	{
		tilemap.rows[i].tile.resize(widthInTiles);
	}

	int tm_id = rc_tilemap.size();

	if(rc_deleted_tilemap.size() > 0)
	{
		tm_id = rc_deleted_tilemap[0];
		rc_deleted_tilemap.erase(rc_deleted_tilemap.begin());
		rc_tilemap[tm_id] = tilemap;
	}
	else
		rc_tilemap.push_back(tilemap);

	return tm_id;
}

void rc_deleteTileMap(int tilemap)
{
	if(tilemap < 0 || tilemap >= rc_tilemap.size())
		return;

	if(!rc_tilemap[tilemap].active)
		return;

	rc_tilemap[tilemap].rows.clear();
	rc_tilemap[tilemap].num_tiles_across = 0;
	rc_tilemap[tilemap].num_tiles_down = 0;
	rc_tilemap[tilemap].texture = NULL;
	rc_tilemap[tilemap].tileset = -1;
	rc_tilemap[tilemap].active = false;

	rc_deleted_tilemap.push_back(tilemap);
}

void rc_setTileMapSize(int tilemap, int widthInTiles, int heightInTiles)
{
	if(tilemap < 0 || tilemap >= rc_tilemap.size())
		return;

	if(!rc_tilemap[tilemap].active)
		return;

	rc_tilemap[tilemap].num_tiles_across = widthInTiles;
	rc_tilemap[tilemap].num_tiles_down = heightInTiles;

	rc_tilemap[tilemap].rows.resize(heightInTiles);
	for(int i = 0; i < rc_tilemap[tilemap].rows.size(); i++)
	{
		rc_tilemap[tilemap].rows[i].tile.resize(widthInTiles);
	}
}

void rc_getTileMapSize(int tilemap, double* widthInTiles, double* heightInTiles)
{
	if(tilemap < 0 || tilemap >= rc_tilemap.size())
		return;

	if(!rc_tilemap[tilemap].active)
		return;

	*widthInTiles = rc_tilemap[tilemap].num_tiles_across;
	*heightInTiles = rc_tilemap[tilemap].num_tiles_down;
}

void rc_setTile(int tilemap, int tile, int x, int y)
{
	if(tilemap < 0 || tilemap >= rc_tilemap.size())
		return;

	if(!rc_tilemap[tilemap].active)
		return;

	int tileset = rc_tilemap[tilemap].tileset;

	//if tilemap exists, then its safe to assume tileset is in range since tilemap can't be created if its not
	if(!rc_tileset[tileset].active)
		return;

	int num_tset_tiles = rc_tileset[tileset].tiles.size();

	if(tile < 0 || tile >= num_tset_tiles)
		tile = -1;

	if( (x < 0 || x >= rc_tilemap[tilemap].num_tiles_across) || (y < 0 || y >= rc_tilemap[tilemap].num_tiles_down) )
		return;

	rc_tilemap[tilemap].rows[y].tile[x] = tile;
}

int rc_getTile(int tilemap, int x, int y)
{
	if(tilemap < 0 || tilemap >= rc_tilemap.size())
		return -1;

	if(!rc_tilemap[tilemap].active)
		return -1;

	if( (x < 0 || x >= rc_tilemap[tilemap].num_tiles_across) || (y < 0 || y >= rc_tilemap[tilemap].num_tiles_down) )
		return -1;

	return rc_tilemap[tilemap].rows[y].tile[x];
}

void rc_fillTile(int tilemap, int tile, int x, int y, int widthInTiles, int heightInTiles)
{
	if(tilemap < 0 || tilemap >= rc_tilemap.size())
		return;

	if(!rc_tilemap[tilemap].active)
		return;

	int tileset = rc_tilemap[tilemap].tileset;

	//if tilemap exists, then its safe to assume tileset is in range since tilemap can't be created if its not
	if(!rc_tileset[tileset].active)
		return;

	int num_tset_tiles = rc_tileset[tileset].tiles.size();

	if(tile < 0 || tile >= num_tset_tiles)
		tile = -1;

	if( (x < 0 || x >= rc_tilemap[tilemap].num_tiles_across) || (y < 0 || y >= rc_tilemap[tilemap].num_tiles_down) )
		return;

	if( ( (x+widthInTiles) < 0 || (x+widthInTiles) > rc_tilemap[tilemap].num_tiles_across) || ( (y+heightInTiles) < 0 || (y+heightInTiles) > rc_tilemap[tilemap].num_tiles_down) )
		return;

	for(int iy = 0; iy < heightInTiles; iy++)
		for(int ix = 0; ix < widthInTiles; ix++)
			rc_tilemap[tilemap].rows[y+iy].tile[x+ix] = tile;
}

void getTileInTileset(int tileset, int tile, int* x, int* y)
{
	int img_w = rc_image[ rc_tileset[tileset].img_id ].image->getSize().Width;
	int img_h = rc_image[ rc_tileset[tileset].img_id ].image->getSize().Height;
	int tile_w = rc_tileset[tileset].tile_width;
	int tile_h = rc_tileset[tileset].tile_height;
	int widthInTiles = img_w / tile_w;

	*x = (tile%widthInTiles) * tile_w;
	*y = (tile/widthInTiles) * tile_h;
}

int getNumTilesInTileset(int tileset)
{
	int img_w = rc_image[ rc_tileset[tileset].img_id ].image->getSize().Width;
	int img_h = rc_image[ rc_tileset[tileset].img_id ].image->getSize().Height;
	int tile_w = rc_tileset[tileset].tile_width;
	int tile_h = rc_tileset[tileset].tile_height;
	int widthInTiles = img_w / tile_w;
	int heightInTiles = img_h / tile_h;

	return (widthInTiles*heightInTiles);
}

void updateTileset(int tileset)
{
	Uint32 current_time_ms = SDL_GetTicks();
	for(int i = 0; i < rc_tileset[tileset].tiles.size(); i++)
	{
		if( (current_time_ms-rc_tileset[tileset].tiles[i].frame_start_time) >= rc_tileset[tileset].tiles[i].frame_swap_time )
		{
			rc_tileset[tileset].tiles[i].current_frame++;
			if(rc_tileset[tileset].tiles[i].current_frame >= rc_tileset[tileset].tiles[i].num_frames)
				rc_tileset[tileset].tiles[i].current_frame = 0;

			rc_tileset[tileset].tiles[i].frame_start_time = current_time_ms;
		}
	}
}

void rc_drawTileMap(int tilemap, int x, int y, int w, int h, int offset_x, int offset_y)
{
	if(tilemap < 0 || tilemap >= rc_tilemap.size())
		return;

	if(!rc_tilemap[tilemap].active)
		return;

	if(rc_active_canvas < 0 || rc_active_canvas >= rc_canvas.size())
		return;

	if(!rc_canvas[rc_active_canvas].type == RC_CANVAS_TYPE_2D)
		return;

	if(!rc_canvas[rc_active_canvas].texture)
		return;

	rc_tilemap[tilemap].texture = VideoDriver->addRenderTargetTexture(irr::core::dimension2d<u32>(w,h), "rt", ECF_A8R8G8B8);
	VideoDriver->setRenderTarget(rc_tilemap[tilemap].texture, true, true, irr::video::SColor(0,0,0,0));


	int tileset = rc_tilemap[tilemap].tileset;

	updateTileset(tileset);

	int vp_widthInTiles = w/rc_tileset[tileset].tile_width;
	int vp_heightInTiles = h/rc_tileset[tileset].tile_height;

	int tset_img_id = rc_tileset[tileset].img_id;
	int src_w = rc_tileset[tileset].tile_width;
	int src_h = rc_tileset[tileset].tile_height;

	int tile_offset_x = offset_x / src_w;
	int tile_offset_y = offset_y / src_h;

	int screen_offset_x = 0 - (offset_x % src_w);
	int screen_offset_y = 0 - (offset_y % src_h);

	int num_tiles_in_tset = getNumTilesInTileset(tileset);

	for(int iy = 0; iy < vp_heightInTiles+1; iy++)
	{
		for(int ix = 0; ix < vp_widthInTiles+1; ix++)
		{
			int current_frame = 0; //TODO: ADD TIMING
			int map_x = tile_offset_x + ix;
			int map_y = tile_offset_y + iy;

			if(map_x < 0 || map_x >= rc_tilemap[tilemap].num_tiles_across || map_y < 0 || map_y >= rc_tilemap[tilemap].num_tiles_down)
				continue;

			int tile = rc_tilemap[tilemap].rows[map_y].tile[map_x];

			if(tile < 0 || tile >= num_tiles_in_tset)
				continue;

			current_frame = rc_tileset[tileset].tiles[tile].current_frame;
			tile = rc_tileset[tileset].tiles[tile].frames[current_frame];

			if(tile < 0 || tile >= num_tiles_in_tset)
				continue;

			int src_x = 0;
			int src_y = 0;
			getTileInTileset(tileset, tile, &src_x, &src_y);
			irr::core::rect<irr::s32> sourceRect( irr::core::vector2d<irr::s32>(src_x, src_y), irr::core::dimension2d<irr::s32>(src_w, src_h));

			irr::video::SColor color(rc_image[tset_img_id].alpha,
									rc_image[tset_img_id].color_mod.getRed(),
									rc_image[tset_img_id].color_mod.getGreen(),
									rc_image[tset_img_id].color_mod.getBlue());

			int dst_x = screen_offset_x + (ix*src_w);
			int dst_y = screen_offset_y + (iy*src_h);
			irr::core::rect<irr::s32> dest( irr::core::vector2d<irr::s32>(dst_x, dst_y), irr::core::dimension2d<irr::s32>(src_w, src_h));


			VideoDriver->draw2DImage(rc_image[tset_img_id].image, dest, sourceRect, 0, 0, true);
		}
	}

	VideoDriver->setRenderTarget(rc_canvas[rc_active_canvas].texture, false, false);

	irr::core::rect<irr::s32> sourceRect( irr::core::vector2d<irr::s32>(0, 0), irr::core::dimension2d<irr::s32>(w, h));
	irr::core::rect<irr::s32> dest( irr::core::vector2d<irr::s32>(x, y), irr::core::dimension2d<irr::s32>(w, h));

	VideoDriver->draw2DImage(rc_tilemap[tilemap].texture, dest, sourceRect, 0, 0, false);
	VideoDriver->removeTexture(rc_tilemap[tilemap].texture);
	rc_tilemap[tilemap].texture = NULL;
	//draw2DImage(VideoDriver, rc_tilemap[tilemap].texture, src, pos,)
}


#endif // RC_TILELIB_H_INCLUDED
