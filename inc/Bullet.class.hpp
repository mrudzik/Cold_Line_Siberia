/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:51:53 by mrudzik           #+#    #+#             */
/*   Updated: 2019/02/01 14:51:54 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_HPP
#define BULLET_CLASS_HPP

#include "Game.class.hpp"
#include "Game_Entity.hpp"
#include "Player.class.hpp"

class Bullet : public Game_Entity
{

private:
	int 	_max_frames;
	int 	_cur_frames;

public:
	
	bool 	is_active;

	void 		set_new_pic(Graph_Window &sdl_window, std::string path);
	void 		shoot(Player &player);
	void 		move(Player &player);


	Bullet(Graph_Window &sdl_window);
	~Bullet();
	
};


#endif
