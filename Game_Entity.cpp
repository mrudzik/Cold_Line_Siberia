/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game_Entity.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:35:59 by mrudzik           #+#    #+#             */
/*   Updated: 2019/02/01 14:36:01 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game_Entity.hpp"



int 	Game_Entity::getScreenPos_y(void)
{
	return (_screenPos_y);
}

int 	Game_Entity::getScreenPos_x(void)
{
	return (_screenPos_x);
}

double 	Game_Entity::getDegree(void)
{
	return (_degree);
}

float 	Game_Entity::getSpeed(void)
{
	return (_speed);
}

void 	Game_Entity::set_next_move(float vec_x, float vec_y)
{
	_move_vec_x += vec_x;
	_move_vec_y += vec_y;
}



float 	Game_Entity::getMapPos_x(void)
{
	return (_map_pos_x);
}

float 	Game_Entity::getMapPos_y(void)
{
	return (_map_pos_y);
}


void	Game_Entity::draw_picture(Graph_Window &sdl_window)
{
	// std::cout << "_degree " << _degree << std::endl;
	_picture.render_pic(sdl_window, _screenPos_x, _screenPos_y , NULL, _degree, NULL, _flipType);
}




Game_Entity::Game_Entity()
{
	_flipType = SDL_FLIP_NONE;
	_degree = 0;
	_map_pos_x = 0;
	_map_pos_y = 0;
	_speed = 4;
}

Game_Entity::~Game_Entity()
{
	return;
}





