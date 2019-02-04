/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackGround.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudzik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:32:19 by mrudzik           #+#    #+#             */
/*   Updated: 2019/01/30 15:32:20 by mrudzik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_CLASS_HPP
#define BACKGROUND_CLASS_HPP

#include "Game.class.hpp"
#include "Player.class.hpp"

class BackGround_Texture : public Pic_Texture
{
private:


public:

	
	void 	render_backgr(Graph_Window &sdl_window, Player &plyr);
	
	BackGround_Texture();
	~BackGround_Texture();
	
};


#endif
