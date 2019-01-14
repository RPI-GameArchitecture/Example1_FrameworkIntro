/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_sim.h"

#include "ga_compiler_defines.h"

#include "gameobject/ga_gameobject.h"

#if defined(GA_MINGW)
#include <malloc.h>
#endif

ga_sim::ga_sim()
{
}

ga_sim::~ga_sim()
{
}


void ga_sim::add_gameobject(ga_gameobject* go)
{
	_gameobjects.push_back(go);

}

void ga_sim::update(ga_frame_params* params)
{
	// simple game loop update 

	for (int i = 0; i < _gameobjects.size(); i++)
	{
		_gameobjects[i]->update(params);
	}

}


