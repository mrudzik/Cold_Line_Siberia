/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:53:31 by mrudzik           #+#    #+#             */
/*   Updated: 2019/02/01 14:53:38 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

void 	Bullet::set_new_pic(Graph_Window &sdl_window, std::string path)
{
	_picture.loadFromFile(path.c_str(), sdl_window);
}

void	Bullet::shoot(Player &player)
{

	this->_degree = player.getDegree();
	this->is_active = 1;
	this->_cur_frames = 0;
	_map_pos_x = player.getMapPos_x() + 40;
	_map_pos_y = player.getMapPos_y();

	_screenPos_x = player.getScreenPos_x() + 40;
	_screenPos_y = player.getScreenPos_y();

	int 	mouse_screenPos_x;
	int 	mouse_screenPos_y;
	SDL_GetMouseState(&mouse_screenPos_x, &mouse_screenPos_y);
	
	float x_vec;
	float y_vec;
	float full_len;
	int len;
	
	x_vec = fabs(_screenPos_x - mouse_screenPos_x);
	y_vec = fabs(_screenPos_y - mouse_screenPos_y);
	full_len = sqrt((x_vec * x_vec) + (y_vec * y_vec));

	
	len = _speed;
	_move_vec_x = -1 * (_screenPos_x - (_screenPos_x + (mouse_screenPos_x - _screenPos_x) * (len / full_len)));
	_move_vec_y = _screenPos_y - (_screenPos_y + (mouse_screenPos_y - _screenPos_y) * (len / full_len));
	
	// DRM.vx_start + (DRM.vx_end - DRM.vx_start)
	// * (DRM.len / DRM.full_len)
	// _move_vec_x = 15;
	// _move_vec_y = 0;
	// std::cout << "_degree " << _degree << std::endl;
}

void 	Bullet::move(Player &player)
{
	if (_cur_frames > _max_frames)
	{
		//Reseting vectors
		is_active = 0;
		_move_vec_x = 0;
		_move_vec_y = 0;
		
		return;
	}
	_cur_frames++;
	_map_pos_x += _move_vec_x;
	_map_pos_y += _move_vec_y;

	_screenPos_x = static_cast<int>( player.getScreenPos_x() + (_map_pos_x - player.getMapPos_x()) );
	_screenPos_y = static_cast<int>( player.getScreenPos_y() - (_map_pos_y - player.getMapPos_y()) );
}

Bullet::Bullet (Graph_Window &sdl_window) : Game_Entity()
{
	_picture.loadFromFile("pictures/Bullet.png", sdl_window);
	_screenPos_x = ((sdl_window.getWidth() - _picture.getWidth()) / 2);
	_screenPos_y = ((sdl_window.getHeight() - _picture.getHeight()) / 2);

	_speed = 20;
	_max_frames = 100;
	_cur_frames = 100;
	is_active = 0;
	return;
}


Bullet::~Bullet(void)
{
	return;
}