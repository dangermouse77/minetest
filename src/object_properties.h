/*
Minetest
Copyright (C) 2013 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once

#include <string>
#include "irrlichttypes_bloated.h"
#include <iostream>
#include <map>
#include <vector>

struct ObjectProperties
{
	// Values are BS=1
	s16 hp_max = 1;
	bool physical = false;
	bool collideWithObjects = true;
	float weight = 5.0f;
	aabb3f collisionbox = aabb3f(-0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f);
	std::string visual = "sprite";
	std::string mesh = "";
	v2f visual_size = v2f(1, 1);
	std::vector<std::string> textures;
	std::vector<video::SColor> colors;
	v2s16 spritediv = v2s16(1, 1);
	v2s16 initial_sprite_basepos;
	bool is_visible = true;
	bool makes_footstep_sound = false;
	float automatic_rotate = 0.0f;
	f32 stepheight = 0.0f;
	bool automatic_face_movement_dir = false;
	f32 automatic_face_movement_dir_offset = 0.0f;
	bool backface_culling = true;
	std::string nametag = "";
	video::SColor nametag_color = video::SColor(255, 255, 255, 255);
	f32 automatic_face_movement_max_rotation_per_sec = -1.0f;
	std::string infotext;
	//! For dropped items, this contains item information.
	std::string wield_item;

	ObjectProperties();
	std::string dump();
	void serialize(std::ostream &os) const;
	void deSerialize(std::istream &is);
};
