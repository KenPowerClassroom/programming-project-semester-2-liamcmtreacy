
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
	if (!m_playerTexture.loadFromFile("ASSETS\\SPRITES\\player_down.png")) // error checking
	{
		std::cout << "error loading the player character" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture); // player sprite merging with texture
}

sf::Sprite Player::getBody() // get body
{
	return m_playerSprite;
}

void Player::setPosition() // having the set Position of the sprite
{
	m_playerSprite.setPosition(400.0f, 400.0f);
}

void Player::setPosition(int xPos, int yPos) // having the set Position of the sprite
{
	m_playerSprite.setPosition(xPos, yPos);
}

void Player::moveLeft()
{
	sf::Vector2f pos(m_playerSprite.getPosition());
	{
		if (pos.x >=0)
		{
			pos.x = pos.x - speed;
		}
	}
	m_playerSprite.setPosition(pos.x, pos.y);
}

void Player::moveRight()
{
	sf::Vector2f pos(m_playerSprite.getPosition());
	{
		if (pos.x <= SCREEN_WIDTH - 124)
		{
			pos.x = pos.x + speed;
		}
	}
	m_playerSprite.setPosition(pos.x, pos.y);
}

void Player::moveUp()
{
	sf::Vector2f pos(m_playerSprite.getPosition());
	if (pos.y >= 0)
	{
		pos.y = pos.y - speed;
	}
	m_playerSprite.setPosition(pos.x, pos.y);
}

void Player::moveDown()
{
	sf::Vector2f pos(m_playerSprite.getPosition());
	if (pos.y <= SCREEN_HEIGHT - 100)
	{
		pos.y = pos.y + speed;
	}
	m_playerSprite.setPosition(pos.x, pos.y);
}

