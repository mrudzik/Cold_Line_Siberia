/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:34:27 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/29 17:34:31 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

void 		Player::movement(Graph_Window &sdl_window)
{
	if (sdl_window.key_state[SDL_SCANCODE_UP]
	|| sdl_window.key_state[SDL_SCANCODE_W])
		this->set_next_move(0, this->getSpeed());
	
	if (sdl_window.key_state[SDL_SCANCODE_DOWN]
	|| sdl_window.key_state[SDL_SCANCODE_S])
		this->set_next_move(0, -1 * this->getSpeed());
		
	if (sdl_window.key_state[SDL_SCANCODE_RIGHT]
	|| sdl_window.key_state[SDL_SCANCODE_D])
		this->set_next_move(this->getSpeed(), 0);
		
	if (sdl_window.key_state[SDL_SCANCODE_LEFT]
	|| sdl_window.key_state[SDL_SCANCODE_A])
		this->set_next_move(-1 * this->getSpeed(), 0);
		
	this->move();
}

void 	Player::move(void)
{
	// std::cout << "Player pos 	x - " << this->getMapPos_x() << " y - " << this->getMapPos_y() << std::endl;
	_map_pos_x += _move_vec_x;
	_map_pos_y += _move_vec_y;

	//Checking background borders
	if (_bord_start_x > _map_pos_x)
		_map_pos_x = _bord_start_x;
	if (_bord_end_x < _map_pos_x)
		_map_pos_x = _bord_end_x;

	if (_bord_start_y < _map_pos_y)
		_map_pos_y = _bord_start_y;
	if (_bord_end_y > _map_pos_y)
		_map_pos_y = _bord_end_y;

	//Reseting vectors
	_move_vec_x = 0;
	_move_vec_y = 0;
}

void 	Player::calc_degree(void)
{
	// (void)sdl_window;

	int 	mouse_screenPos_x;
	int 	mouse_screenPos_y;

	SDL_GetMouseState(&mouse_screenPos_x, &mouse_screenPos_y);

	bool 	half_flag = false;
	if (mouse_screenPos_y < _screenPos_y)
		half_flag = true;

	int 	vecx_A = _screenPos_x - mouse_screenPos_x  + (_picture.getWidth() / 2);
	int 	vecy_A = _screenPos_y - mouse_screenPos_y;
	int 	vecx_B = 10;
	int 	vecy_B = 0;
	double 	angle_cos = (vecx_A * vecx_B + vecy_A * vecy_B) /
		(sqrt(vecx_A * vecx_A + vecy_A * vecy_A) * sqrt(vecx_B * vecx_B + vecy_B * vecy_B));

	_degree = 90.0 - acos(angle_cos) * (180.0 / M_PI);
	if (half_flag)
		_degree = 90.0 + (90.0 - _degree);
	return;
}


Player::Player(Graph_Window &sdl_window) : Game_Entity()
{
	_picture.loadFromFile("pictures/Player_Mouse_sprite_resized.png", sdl_window);
	_screenPos_x = ((sdl_window.getWidth() - _picture.getWidth()) / 2);
	_screenPos_y = ((sdl_window.getHeight() - _picture.getHeight()) / 2);


	_bord_start_x = -512;
		_bord_end_x = 3380;
	_bord_start_y = 512;
		_bord_end_y = -3380;

	return;
}

Player::~Player(void)
{
	return;
}
