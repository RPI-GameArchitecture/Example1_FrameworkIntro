/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "framework/ga_compiler_defines.h"
#include "framework/ga_input.h"
#include "framework/ga_sim.h"
#include "framework/ga_output.h"
#include "framework/ga_frame_params.h"
#include "gameobject/ga_gameobject.h"


int main(int argc, const char** argv)
{

	// Create objects for three phases of the frame: input, sim and output.
	ga_input* input = new ga_input();
	ga_sim* sim = new ga_sim();
	ga_output* output = new ga_output(input->get_window());

	// create test gameobjects

	ga_player *player = new ga_player("player");
	ga_enemy *enemy1 = new ga_enemy("enemy 1");

	//sim->add_gameobject(player);
	sim->add_gameobject(enemy1);
	// Main loop:
	while (true)
	{
		// We pass frame state through the 3 phases using a params object.
		ga_frame_params params;
		
		params._gameobjects = sim->_gameobjects;

		// Gather user input and current time.
		if (!input->update(&params))
		{
			break;
		}
		
		// Run gameplay.
		sim->update(&params);

		// Draw to screen.
		output->update(&params);
	}

	delete output;
	delete sim;
	delete input;


	return 0;
}
