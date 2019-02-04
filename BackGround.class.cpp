/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackGround.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:51:20 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/30 15:51:21 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BackGround.class.hpp"



void 	BackGround_Texture::render_backgr(Graph_Window &sdl_window, Player &player)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad_onscreen = { 0, 0, W, H };
	SDL_Rect renderQuad_ofpicture = { 0, 0, W, H };
	int temp;


	renderQuad_ofpicture.x += static_cast<int>(player.getMapPos_x());
	// If Reached Left Border of image
	if (player.getMapPos_x() < 0)
	{
		renderQuad_ofpicture.x = 0;
		renderQuad_ofpicture.w += static_cast<int>(player.getMapPos_x());
		renderQuad_onscreen.x -= static_cast<int>(player.getMapPos_x());
		renderQuad_onscreen.w = renderQuad_ofpicture.w;
	}
	// If Reached Right Border of image
	if (player.getMapPos_x() > this->getWidth() - W)
	{
		temp = (this->getWidth() - W) - player.getMapPos_x();
		// std::cout << "Temp " << temp << std::endl;
		renderQuad_ofpicture.w += temp;
		renderQuad_onscreen.w = renderQuad_ofpicture.w;
	}

	renderQuad_ofpicture.y -= static_cast<int>(player.getMapPos_y());
	// If Reached Upped Border of image
	if (player.getMapPos_y() > 0)
	{
		renderQuad_ofpicture.y = 0;
		renderQuad_ofpicture.h -= static_cast<int>(player.getMapPos_y());
		renderQuad_onscreen.y += static_cast<int>(player.getMapPos_y());
		renderQuad_onscreen.h = renderQuad_ofpicture.h;
	}
	// If Reached Lower Border of image
	if (player.getMapPos_y() < -1 * (this->getHeight() - H))
	{
		temp = (this->getHeight() - H) + player.getMapPos_y();
		// std::cout << "Temp 2 " << temp << std::endl;
		renderQuad_ofpicture.h += temp;
		renderQuad_onscreen.h = renderQuad_ofpicture.h;
	}
	
	// std::cout << "of picture x - " << renderQuad_ofpicture.x << " y - " << renderQuad_ofpicture.y << " w - " << renderQuad_ofpicture.w << " h - " << renderQuad_ofpicture.h << std::endl;
	// std::cout << "on screen  x - " << renderQuad_onscreen.x << " y - " << renderQuad_onscreen.y << " w - " << renderQuad_onscreen.w << " h - " << renderQuad_onscreen.h << std::endl;
	//Render to screen
	SDL_RenderCopy( sdl_window.get_render(), this->getTexture(), &renderQuad_ofpicture, &renderQuad_onscreen);
}



// int 	BackGround_Texture::getBordStrX(void)
// {
// 	return (this->_bord_start_x);
// }

// int 	BackGround_Texture::getBordStrY(void)
// {
// 	return (this->_bord_start_y);
// }

// int 	BackGround_Texture::getBordEndX(void)
// {
// 	return (this->_bord_end_x);
// }

// int 	BackGround_Texture::getBordEndY(void)
// {
// 	return (this->_bord_end_y);
// }


BackGround_Texture::BackGround_Texture(void): Pic_Texture()
{
	return;
}

BackGround_Texture::~BackGround_Texture(void)
{
	return;
}
