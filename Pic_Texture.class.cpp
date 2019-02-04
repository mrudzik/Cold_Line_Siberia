/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pic_Texture.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:49:20 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/29 16:49:21 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pic_Texture.class.hpp"



SDL_Texture* 	Pic_Texture::getTexture(void)
{
	return (this->mTexture);
}

int 	Pic_Texture::getWidth(void)
{
	return (this->mWidth);
}

int 	Pic_Texture::getHeight(void)
{
	return (this->mHeight);
}



void 	Pic_Texture::free_texture(void)
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

bool 	Pic_Texture::loadFromFile(std::string path, Graph_Window &wind)
{
	free_texture();
	//Final Texture

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image " << path.c_str() << std::endl;
		std::cout << "SDL Error " << SDL_GetError() << std::endl;
	}
	else
	{
		//Color key image
		//SDL_MapRGB -> sets transparent pixel with something
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		//Create Texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(wind.get_render(), loadedSurface);
		if ( newTexture == NULL)
		{
			std::cout << "Unable to create texture from " << path.c_str() << std::endl;
			std::cout << "SDL Error " << SDL_GetError() << std::endl;
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		// Get rid of temp surface
		SDL_FreeSurface (loadedSurface);
	}
	this->mTexture = newTexture;
	return (this->mTexture != NULL);
}




void 	Pic_Texture::render_pic( Graph_Window &wind, int x, int y, SDL_Rect *clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
		//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen
	SDL_RenderCopyEx( wind.get_render(), mTexture, clip, &renderQuad, angle, center, flip );
}



Pic_Texture::Pic_Texture()
{
//Initialization
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Pic_Texture::~Pic_Texture()
{
	free_texture();
}









