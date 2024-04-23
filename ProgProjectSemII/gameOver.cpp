#include "gameOver.h"
#include <iostream>

GameOver::GameOver()
{
	loadGOBackground();
}

void GameOver::loadGOBackground()
{
	if (!gameOverTexture.loadFromFile("ASSETS\\SPRITES\\endScreen1.png"))
	{
		std::cout << "error loading the background image" << std::endl; // error message if background fails
	}
	gameOverSprite.setTexture(gameOverTexture);
	gameOverTexture.setRepeated(true);
	gameOverSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void GameOver::draw(sf::RenderWindow& t_window)
{
	t_window.draw(gameOverSprite);
}
