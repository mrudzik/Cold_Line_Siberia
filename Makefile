# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrudzik <mrudzik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 14:03:42 by mrudzik           #+#    #+#              #
#    Updated: 2019/01/09 20:55:18 by mrudzik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cold_line

SRCS 	:=	main.cpp				\
			Graph_Window.cpp 		\
			Game.class.cpp			\
			Pic_Texture.class.cpp 	\
			Game_Entity.cpp 		\
			Player.class.cpp 		Bullet.class.cpp		Enemy.class.cpp		\
			BackGround.class.cpp
#15_rotation_and_flipping.cpp
		

OBJS    :=	$(SRCS:.cpp=.o)

INCLUDES	=	-I ./inc\
				-I ./frameworks/SDL2.framework/Versions/A/Headers \
				-I ./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I ./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I ./frameworks/SDL2_mixer.framework/Headers \
				-I ./frameworks/SDL2_net.framework/Headers \
				-F ./frameworks 
				
FRAMEWORKS	=	-F ./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer -framework SDL2_net

CXX      := clang++
CXXFLAGS := -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@ $(INCLUDES) $(FRAMEWORKS) -g -fsanitize=address

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re:     fclean all

.PHONY: all clean fclean format re