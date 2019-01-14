#pragma once

/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_drawcall.h"
#include "gameobject/ga_gameobject.h"

#include <atomic>
#include <chrono>
#include <cstdint>
#include <vector>

/*
** Keyboard/controller buttons we track.
*/
enum ga_button_t
{
	k_button_left   = 1 << 0,
	k_button_right  = 1 << 1,
	k_button_up     = 1 << 2,
	k_button_down   = 1 << 3,
	k_button_space  = 1 << 4,
	k_button_a		= 1 << 5,
	k_button_b		= 1 << 6,
	k_button_c		= 1 << 7,
	k_button_d		= 1 << 8,
	k_button_e		= 1 << 9,
	k_button_f		= 1 << 10,
	k_button_g		= 1 << 11,
	k_button_h		= 1 << 12,
	k_button_i		= 1 << 13,
	k_button_j		= 1 << 14,
	k_button_k		= 1 << 15,
	k_button_l		= 1 << 16,
	k_button_m		= 1 << 17,
	k_button_n		= 1 << 18,
	k_button_o		= 1 << 19,
	k_button_p		= 1 << 20,
	k_button_q		= 1 << 21,
	k_button_r		= 1 << 22,
	k_button_s		= 1 << 23,
	k_button_t		= 1 << 24,
	k_button_u		= 1 << 25,
	k_button_v		= 1 << 26,
	k_button_w		= 1 << 27,
	k_button_x		= 1 << 28,
	k_button_y		= 1 << 29,
	k_button_z		= 1 << 30,
};

/*
** Working information for the frame.
** Each frame stage emits some data for consumption by later stages.
*/
struct ga_frame_params
{
	// Data emitted by input stage:
	std::chrono::high_resolution_clock::time_point _current_time;
	std::chrono::high_resolution_clock::duration _delta_time;

	uint64_t _button_mask;

	uint64_t _mouse_click_mask;
	uint64_t _mouse_press_mask;
	float _mouse_x;
	float _mouse_y;

	// Data emitted by sim stage:
	std::vector<ga_drawcall> _drawcalls;
	std::atomic_flag _drawcall_lock = ATOMIC_FLAG_INIT;

	std::vector<class ga_gameobject*> _gameobjects;
};
