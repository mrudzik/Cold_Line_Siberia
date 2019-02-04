/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:32:27 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/29 17:32:28 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "Game.class.hpp"
#include "Game_Entity.hpp"

class  	Player : public Game_Entity
{

private:

	int 	_bord_start_x;
	int 	_bord_end_x;
	int 	_bord_start_y;
	int 	_bord_end_y;

public:

void 		movement(Graph_Window &sdl_window);
void 		move(void);
void		calc_degree(void);


	Player(Graph_Window &sdl_window);
	~Player();
	
};


#endif
