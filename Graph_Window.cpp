/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph_Window.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:05:57 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/28 15:05:58 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Graph_Window.hpp"


int 			Graph_Window::getHeight(void)
{
	return (this->_wind_H);
}

int 			Graph_Window::getWidth(void)
{
	return (this->_wind_W);
}

SDL_Renderer*	Graph_Window::get_render(void)
{
	return (this->renderer);
}


void 			Graph_Window::draw_text(const char* text, int x, int y)
{
	SDL_Surface			*font_surf;
	SDL_Texture			*font_textr;
	SDL_Rect			font_rect;
	SDL_Color 			color;
	
	int	tw;
	int	th;

	color.r = 255;
	color.g = 255;
	color.b = 255;

	font_surf = TTF_RenderText_Solid(font_ttf, text, color);
	font_textr = SDL_CreateTextureFromSurface(renderer, font_surf);
	SDL_QueryTexture(font_textr, NULL, NULL, &tw, &th);
	font_rect.x = x;
	font_rect.y = y;
	font_rect.w = tw;
	font_rect.h = th;
	SDL_RenderCopy(renderer, font_textr, NULL, &font_rect);
	SDL_DestroyTexture(font_textr);
	SDL_FreeSurface(font_surf);
}

void 	 		Graph_Window::draw_window(void)
{
	SDL_RenderClear(renderer);
	SDL_UpdateTexture(texture, NULL, _img_buff, _wind_W << 2);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	
	int x;
	int y;

	y = 0;
	while (y < _wind_H)
	{
		x = 0;
		while (x < _wind_W)
		{
			_img_buff[y][x] = 0x333333;
			x++;
		}
		y++;
	}
}

Graph_Window::Graph_Window(std::string str, int win_pos_x, int win_pos_y):
	_wind_W(W), _wind_H(H)
{
	std::cout << "Window Start" << std::endl;
	if ((window = SDL_CreateWindow(str.c_str(),
win_pos_x, win_pos_y, _wind_W, _wind_H, SDL_WINDOW_FOREIGN)))
	{
		std::cout << "Window Created" << std::endl;
		if ((renderer = SDL_CreateRenderer(window, -1,
SDL_RENDERER_PRESENTVSYNC)))
		{
			std::cout << "Renderer Created" << std::endl;
			if ((texture = SDL_CreateTexture(renderer,
SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, _wind_W, _wind_H)))
			{
				std::cout << "Texture Created" << std::endl;
				font_ttf = TTF_OpenFont("ARIAL.TTF", 15);
				key_state = SDL_GetKeyboardState(NULL);
			}
		}
	}
	std::cout << "Window Initialized" << std::endl;
	return;
}


Graph_Window::~Graph_Window()
{
		if (texture != NULL)
			SDL_DestroyTexture(texture);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}