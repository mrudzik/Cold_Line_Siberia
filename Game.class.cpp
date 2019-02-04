/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:32:15 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/28 17:32:17 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"


#include "Player.class.hpp"
#include "BackGround.class.hpp"
#include "Bullet.class.hpp"
#include "Enemy.class.hpp"


void 		Game::game_loop(void)
{
	Graph_Window 	sdl_window("Cold Line", 600, 100);
	SDL_Event  		event;
	int 			cycle;
	int 			i;
	int 			en;

	BackGround_Texture 		back_gr;
	back_gr.loadFromFile("pictures/snow_background_2x.png", sdl_window);


	Player 			player(sdl_window);


	std::vector<Bullet> 	bullet(bullet_count, Bullet(sdl_window));
	i = 0;
	while (i < bullet_count)
	{
		bullet[i].set_new_pic(sdl_window, "pictures/Bullet.png");
		i++;
	}
	std::vector<Enemy> 	enemy(enemy_count, Enemy(sdl_window));
	i = 0;
	while (i < enemy_count)
	{
		enemy[i].set_new_pic(sdl_window, "pictures/Enemy_sprite.png");
		i++;
	}
	


	cycle = 1;
	while (cycle)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				std::cout << "closing cross" << std::endl;
				cycle = 0;
			}
			// Mouse events
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				i = 0;
				while (i < bullet_count)
				{
					if (bullet[i].is_active == 0)
					{
						bullet[i].shoot(player);
						break;
					}
					i++;
				}
			}
		}

		
		if ((rand() % 50) == 0)
		{
			i = 0;
			while (i < enemy_count)
			{
				if (enemy[i].is_active == 0)
				{
					enemy[i].spawn_from_nowhere(player);
					break;
				}
				i++;
			}
		}
		player.movement(sdl_window);

		SDL_RenderClear( sdl_window.get_render() );

	// 	BackGround stuff
		back_gr.render_backgr(sdl_window, player);

		


	// 	Enemy stuff
		i = 0;
		while (i < enemy_count)
		{
			if (enemy[i].is_active > 0)
			{
				enemy[i].calc_next_move(player);
				enemy[i].move(player);
				enemy[i].calc_angle(player);
				if (enemy[i].is_active == ENEMY_ATTACK)
					enemy[i].attack(player, sdl_window);
				enemy[i].draw_picture(sdl_window);
			}
			else if (enemy[i].is_active == ENEMY_DEAD)
			{
				enemy[i].move(player);
				enemy[i].draw_picture(sdl_window);
			}
			i++;
		}



// 	Bullet stuff
		i = 0;
		while (i < bullet_count)
		{
			if (bullet[i].is_active == 1)
			{
				bullet[i].move(player);
				bullet[i].draw_picture(sdl_window);
			// Hit enemy
				en = 0;
				while (en < enemy_count)
				{
					if (enemy[en].is_active > 0)
					{
						if (enemy[en].is_hit(bullet[i], sdl_window))
						{
							bullet[i].is_active = 0;
							break;
						}
					}
					en++;
				}
			}
			i++;
		}



	// 	Player stuff
		player.calc_degree();
		player.draw_picture(sdl_window);

		

		
		SDL_RenderPresent( sdl_window.get_render() );
	}
}
