/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pic_Texture.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:46:21 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/29 14:46:23 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIC_TEXTURE_CLASS_HPP
#define PIC_TEXTURE_CLASS_HPP

#include "Graph_Window.hpp"

class 	Pic_Texture
{
private:

	SDL_Texture* 	mTexture;

	int				mWidth;
	int 			mHeight;

public:

SDL_Texture* 	getTexture(void);
int 			getWidth(void);
int 			getHeight(void);

void	free_texture(void);
bool	loadFromFile(std::string path, Graph_Window &wind);
void	render_pic( Graph_Window &wind, int x, int y, SDL_Rect *clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

	Pic_Texture();
	~Pic_Texture();
};


#endif
