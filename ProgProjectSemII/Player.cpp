
#include "Player.h"   // include Player header file

// Player function definitions here

Player::Player()
{
	loadSprite();

	image_width = 124;

	int xPos = SCREEN_WIDTH / 2;
	int yPos = SCREEN_HEIGHT / 2;
	setPosition(xPos, yPos);

	speed = 5;
	livesCount = 3;
}

void Player::loadSprite()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\SPRITES\\character.png")) // error checking
	{
		std::cout << "error loading the player character" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture); // player sprite merging with texture
}

sf::Sprite Player::getBody()
{
	return m_playerSprite;
}

void Player::setPosition()
{
	m_playerSprite.setPosition(400.0f, 400.0f);
}

void Player::setPosition(int xPos, int yPos)
{
	m_playerSprite.setPosition(xPos, yPos);
}

