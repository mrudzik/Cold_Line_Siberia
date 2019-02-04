/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game_Entity.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:22:26 by mrudzik           #+#    #+#             */
/*   Updated: 2019/02/01 14:22:27 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include "Game.class.hpp"


class		Game_Entity
{

protected:

	Pic_Texture 		_picture;
	SDL_RendererFlip 	_flipType;


	double 				_degree;


	int 				_screenPos_x;
	int 				_screenPos_y;

	float 		_map_pos_x;
	float 		_map_pos_y;
	float 		_move_vec_x;
	float 		_move_vec_y;

	float 		_speed;


public:
	
void 		movement(Graph_Window &sdl_window);
void 		set_next_move(float vec_x, float vec_y);

float 		getSpeed(void);
float 		getMapPos_x(void);
float		getMapPos_y(void);
int 		getScreenPos_x(void);
int 		getScreenPos_y(void);

double 		getDegree(void);

void 		draw_picture(Graph_Window &sdl_window);


Game_Entity();
~Game_Entity();
	
};



#endif
