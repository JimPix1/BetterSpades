/*
	Copyright (c) 2017-2020 ByteBit

	This file is part of BetterSpades.

	BetterSpades is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	BetterSpades is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with BetterSpades.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SOUND_H
#define SOUND_H

#ifdef USE_SOUND
#if __APPLE__
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif
#endif

#include "player.h"

#define SOUND_SCALE 0.6F

enum sound_space {
	SOUND_WORLD,
	SOUND_LOCAL,
};

extern int sound_enabled;

struct Sound_wav {
	int openal_buffer;
	float min, max;
};

extern struct Sound_wav sound_footstep1;
extern struct Sound_wav sound_footstep2;
extern struct Sound_wav sound_footstep3;
extern struct Sound_wav sound_footstep4;

extern struct Sound_wav sound_wade1;
extern struct Sound_wav sound_wade2;
extern struct Sound_wav sound_wade3;
extern struct Sound_wav sound_wade4;

extern struct Sound_wav sound_jump;
extern struct Sound_wav sound_jump_water;

extern struct Sound_wav sound_land;
extern struct Sound_wav sound_land_water;

extern struct Sound_wav sound_hurt_fall;

extern struct Sound_wav sound_explode;
extern struct Sound_wav sound_explode_water;
extern struct Sound_wav sound_grenade_bounce;
extern struct Sound_wav sound_grenade_pin;

extern struct Sound_wav sound_pickup;
extern struct Sound_wav sound_horn;

extern struct Sound_wav sound_rifle_shoot;
extern struct Sound_wav sound_rifle_reload;
extern struct Sound_wav sound_smg_shoot;
extern struct Sound_wav sound_smg_reload;
extern struct Sound_wav sound_shotgun_shoot;
extern struct Sound_wav sound_shotgun_reload;
extern struct Sound_wav sound_shotgun_cock;

extern struct Sound_wav sound_hitground;
extern struct Sound_wav sound_hitplayer;
extern struct Sound_wav sound_build;

extern struct Sound_wav sound_spade_woosh;
extern struct Sound_wav sound_spade_whack;

extern struct Sound_wav sound_death;
extern struct Sound_wav sound_beep1;
extern struct Sound_wav sound_beep2;
extern struct Sound_wav sound_switch;
extern struct Sound_wav sound_empty;
extern struct Sound_wav sound_intro;

extern struct Sound_wav sound_debris;
extern struct Sound_wav sound_bounce;
extern struct Sound_wav sound_impact;
extern struct Sound_wav sound_macros;
extern struct Sound_wav sound_chat;

void sound_volume(float vol);
void sound_create_sticky(struct Sound_wav* w, struct Player* player, int player_id);
void sound_create(enum sound_space option, struct Sound_wav* w, float x, float y, float z);
void sound_update(void);
void sound_load(struct Sound_wav* wav, char* name, float min, float max);
void sound_init(void);

#endif
