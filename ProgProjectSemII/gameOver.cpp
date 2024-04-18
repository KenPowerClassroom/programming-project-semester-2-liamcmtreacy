#include "gameOver.h"

GameOver::GameOver()
{
	loadGOBackground();
}

void GameOver::loadGOBackground()
{
	if (!gameOverTexture.loadFromFile("ASSETS\\SPRITES\\gameOver.png"))
	{
		std::cout << "error loading the background image" << std::endl; // error message if background fails
	}
	gameOverSprite.setTexture(gameOverTexture);
	gameOverTexture.setRepeated(true);
	gameOverSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}
