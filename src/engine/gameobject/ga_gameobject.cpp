/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_gameobject.h"
#include "framework/ga_frame_params.h"
#include <iostream>
#include <math.h>
ga_gameobject::ga_gameobject(std::string name) : _name(name)
{
}

ga_gameobject::~ga_gameobject()
{
}

void ga_gameobject::update(ga_frame_params *params)
{
}

void ga_gameobject::draw(ga_frame_params *params)
{
}


ga_player::ga_player(std::string name) : ga_gameobject(name)
{
	_name = name;
	_x = 0;
	_y = 0;

}

ga_player::~ga_player()
{
}

void ga_player::update(ga_frame_params *params)
{
	if (params->_button_mask & k_button_right)
	{
		_x++;
	}
	if (params->_button_mask & k_button_left)
	{
		_x--;
	}
	if (params->_button_mask & k_button_up)
	{
		_y++;
	}
	if (params->_button_mask & k_button_down)
	{
		_y--;
	}

}

void ga_player::draw(ga_frame_params *params)
{
	std::cout << "Player Update:" << _name << " " << _x << " " << _y << "\n";
}

ga_enemy::ga_enemy(std::string name) : ga_gameobject(name)
{
	_name = name;
	_x = 0;
	_y = 0;
	_dx = 20;
	_dy = 10;
}

ga_enemy::~ga_enemy()
{
}

void ga_enemy::update(ga_frame_params *params)
{
	
	// convert dt from chrono::duration to seconds 

	double dt = (double)params->_delta_time.count() * pow(10, -8);
	std::cout << dt << std::endl;

	_x += _dx * dt;
	_y += _dy * dt;

	if (_x > 1280 || _x < 0)
	{
		_dx = -_dx;
	}
	if (_y > 720 || _y < 0)
	{
		_dy = -_dy;
	}

}

void ga_enemy::draw(ga_frame_params *params)
{
	std::cout << "Enemy Update:" << _name << " " << _x << " " << _y << "\n";

}
