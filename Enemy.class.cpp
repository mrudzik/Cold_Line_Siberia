/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:23:51 by mrudzik           #+#    #+#             */
/*   Updated: 2019/02/01 19:23:52 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"


bool		Enemy::is_hit(Bullet &bullet, Graph_Window &sdl_window)
{
	float x_vec;
	float y_vec;
	
	x_vec = fabs((_screenPos_x + 30) - bullet.getScreenPos_x());
	y_vec = fabs((_screenPos_y - 25) - bullet.getScreenPos_y());
	if (sqrt((x_vec * x_vec) + (y_vec * y_vec)) < 40)
	{
		_picture.loadFromFile("pictures/Enemy_Dead.png", sdl_window);
		is_active = ENEMY_DEAD;
		return (1);
	}
	return (0);
}


void 		Enemy::attack(Player &player, Graph_Window &sdl_window)
{
	(void)player;
	if (_attack_stage == 0)
		_picture.loadFromFile("pictures/Enemy_attack_1.png", sdl_window);
	else if (_attack_stage == 10)
		_picture.loadFromFile("pictures/Enemy_attack_2.png", sdl_window);
	else if (_attack_stage == 15)
		_picture.loadFromFile("pictures/Enemy_attack_3.png", sdl_window);
	else if (_attack_stage == 20)
		_picture.loadFromFile("pictures/Enemy_attack_4.png", sdl_window);
	else if (_attack_stage == 25)
		_picture.loadFromFile("pictures/Enemy_attack_5.png", sdl_window);
	else if (_attack_stage == 30)
	{
		// Here must be player hit
		_picture.loadFromFile("pictures/Enemy_attack_6.png", sdl_window);
		// if (_dist_to_player <= 80)
	}
	else if (_attack_stage == 35)
	{
		// _attack_stage;
		is_active = ENEMY_ALIVE;
		_attack_stage = 0;
		_picture.loadFromFile("pictures/Enemy_sprite.png", sdl_window);
		return;
	}
	_attack_stage++;
	return;
}

void 		Enemy::calc_angle(Player &player)
{
	bool 	half_flag = false;
	if (player.getScreenPos_y() < _screenPos_y)
		half_flag = true;

	int 	vecx_A = _screenPos_x - player.getScreenPos_x()  + (_picture.getWidth() / 2);
	int 	vecy_A = _screenPos_y - player.getScreenPos_y();
	int 	vecx_B = 10;
	int 	vecy_B = 0;
	double 	angle_cos = (vecx_A * vecx_B + vecy_A * vecy_B) /
		(sqrt(vecx_A * vecx_A + vecy_A * vecy_A) * sqrt(vecx_B * vecx_B + vecy_B * vecy_B));

	_degree = 90.0 - acos(angle_cos) * (180.0 / M_PI);
	if (half_flag)
		_degree = 90.0 + (90.0 - _degree);
}

void 		Enemy::calc_next_move(Player &player)
{
	float x_vec;
	float y_vec;
	int len;
	
	x_vec = fabs(_screenPos_x - player.getScreenPos_x());
	y_vec = fabs(_screenPos_y - player.getScreenPos_y());
	_dist_to_player = sqrt((x_vec * x_vec) + (y_vec * y_vec));
	if (_dist_to_player > 70)
	{
		len = _speed;
		_move_vec_x = -1 * (_screenPos_x - (_screenPos_x + (player.getScreenPos_x() - _screenPos_x) * (len / _dist_to_player)));
		_move_vec_y = _screenPos_y - (_screenPos_y + (player.getScreenPos_y() - _screenPos_y) * (len / _dist_to_player));
	}
	else if (_attack_stage == 0)
	{
		is_active = ENEMY_ATTACK;

	}
}

void 		Enemy::move(Player &player)
{
	_map_pos_x += _move_vec_x;
	_map_pos_y += _move_vec_y;

	_screenPos_x = static_cast<int>( player.getScreenPos_x() + (_map_pos_x - player.getMapPos_x()) );
	_screenPos_y = static_cast<int>( player.getScreenPos_y() - (_map_pos_y - player.getMapPos_y()) );

	_move_vec_x = 0;
	_move_vec_y = 0;
}

void 		Enemy::spawn_from_nowhere(Player &player)
{
	int dir;
		dir = rand() % 4;
	
	is_active = 1;
	
	if (dir == 0)
	{
		_map_pos_x = player.getMapPos_x() + 800;
		_map_pos_y = player.getMapPos_y() - (rand() % 800);
	}
	else if (dir == 1)
	{
		_map_pos_x = player.getMapPos_x() - (rand() % 800);
		_map_pos_y = player.getMapPos_y() + 800;
	}
	else if (dir == 2)
	{
		_map_pos_x = player.getMapPos_x() - (rand() % 800);
		_map_pos_y = player.getMapPos_y() - 800;
	}
	else
	{
		_map_pos_x = player.getMapPos_x() - 800;
		_map_pos_y = player.getMapPos_y() - (rand() % 800);
	}
	std::cout << "Enemy spawned at x - " << _map_pos_x << " y - " << _map_pos_y << std::endl;
}

void 	Enemy::set_new_pic(Graph_Window &sdl_window, std::string path)
{
	_picture.loadFromFile(path.c_str(), sdl_window);
}

Enemy::Enemy (Graph_Window &sdl_window) : Game_Entity()
{
	_picture.loadFromFile("pictures/Enemy_sprite.png", sdl_window);
	_screenPos_x = ((sdl_window.getWidth() - _picture.getWidth()) / 2);
	_screenPos_y = ((sdl_window.getHeight() - _picture.getHeight()) / 2);

	_speed = 1;
	_attack_stage = 0;
	is_active = 0;
	return;
}

Enemy::~Enemy (void)
{
	return;
}
