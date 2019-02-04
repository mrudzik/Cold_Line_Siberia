/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:23:42 by mrudzik           #+#    #+#             */
/*   Updated: 2019/02/01 19:23:44 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
#define ENEMY_CLASS_HPP

#include "Game.class.hpp"
#include "Game_Entity.hpp"
#include "Player.class.hpp"
#include "Bullet.class.hpp"

#define		ENEMY_NOT_SPAWNED	0
#define 	ENEMY_ALIVE 		1
#define		ENEMY_ATTACK		5
#define 	ENEMY_DEAD 			-1

class Enemy : public Game_Entity
{
private:

	int 		_attack_stage;
	float 		_dist_to_player;

public:
	int			is_active;

	bool 		is_hit(Bullet &bullet, Graph_Window &sdl_window);
	void 		attack(Player &player, Graph_Window &sdl_window);
	void 		calc_angle(Player &player);
	void 		calc_next_move(Player &player);
	void 		move(Player &player);
	void 		spawn_from_nowhere(Player &player);

	void 		set_new_pic(Graph_Window &sdl_window, std::string path);
	Enemy(Graph_Window &sdl_window);
	~Enemy();
	
};

#endif
