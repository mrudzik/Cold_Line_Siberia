/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:37:50 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/28 14:37:52 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Graph_Window.hpp"
#include "Game.class.hpp"



void 	all_stuff(void)
{
	Game 	this_game;

	this_game.game_loop();
}




int 	main (void)
{
	
	all_stuff();
	return (0);
}



