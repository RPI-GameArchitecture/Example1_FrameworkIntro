#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

/*
** Old-fashioned inheritance-style GameObject
** Only for demonstration purposes
*/

#include <string>

class ga_gameobject
{
	public:
		ga_gameobject(std::string name);
		~ga_gameobject();

		virtual void update(class ga_frame_params *params);
		virtual void draw(class ga_frame_params *params);

	protected:
		std::string _name;
};

class ga_player : public ga_gameobject
{
	public:
		ga_player(std::string name);
		~ga_player();

		void update(class ga_frame_params *params);
		void draw(class ga_frame_params *params);
		double _x;
		double _y;
};

class ga_enemy : public ga_gameobject
{
public:
	ga_enemy(std::string name);
	~ga_enemy();

	void update(class ga_frame_params *params);
	void draw(class ga_frame_params *params);

	double _x;
	double _y;

	float _dx;
	float _dy;
};