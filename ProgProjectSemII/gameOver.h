#pragma once


#include "Globals.h"
#include "SFML/Graphics.hpp" 

class GameOver
{
	sf::Sprite gameOverSprite;
	sf::Texture gameOverTexture;

public:
	GameOver();
	void loadGOBackground();
	void draw(sf::RenderWindow& t_window);
};