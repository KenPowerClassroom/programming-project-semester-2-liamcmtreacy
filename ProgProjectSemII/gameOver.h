#pragma once

#include "Globals.h"
#include "SFML/Graphics.hpp" 

class GameOver
{
	sf::Sprite gameOverSprite; // the game over sprite
	sf::Texture gameOverTexture; // game over texture

public:
	GameOver(); // class
	void loadGOBackground(); // load BG
	void draw(sf::RenderWindow& t_window); // draw the background
};