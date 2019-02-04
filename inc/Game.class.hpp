/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:11:25 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/28 17:11:26 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP

#include "Graph_Window.hpp"
#include "Pic_Texture.class.hpp"
#include <vector>
#include <algorithm>
// #include "Player.class.hpp"

class 	Game
{

public:

	int 	bullet_count;
	int 	enemy_count;
	


void 	game_loop(void);


Game()
{
	bullet_count = 200;
	enemy_count = 50;
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	srand(time(NULL));
	return ;
}

~Game()
{
	return;
}
	
};


#endif
