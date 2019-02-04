/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph_Window.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:54:21 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/28 14:54:22 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRAPH_WINDOW_CLASS_HPP
#define GRAPH_WINDOW_CLASS_HPP

#include <iostream>

# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "SDL_net.h"

#define 	W 	1200
#define 	H 	1200

class Graph_Window
{

private:

	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*texture;
	TTF_Font			*font_ttf;
	
	int 				_wind_W;
	int 				_wind_H;
	int 				_img_buff[H][W];


	Graph_Window(void){
		return;
	}

public:
	const Uint8			*key_state;
	
	int 			getWidth(void);
	int 			getHeight(void);

	void 			draw_text(const char* text, int x, int y);
	void 	 		draw_window(void);

	SDL_Renderer*	get_render(void);

	
	

	Graph_Window(std::string str, int win_pos_x, int win_pos_y);

	~Graph_Window();

};

#endif

