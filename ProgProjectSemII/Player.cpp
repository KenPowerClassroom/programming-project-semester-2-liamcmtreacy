#include "Player.h"   // include Player header file

// Player function definitions here

Player::Player()
{
	loadSprite();

	image_width = 64;

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

	if (!m_playerLeftTexture.loadFromFile("ASSETS\\SPRITES\\player_left.png")) // error checking and also loading the left sprite
	{
		std::cout << "error loading the player character" << std::endl;
	}

	if (!m_playerRightTexture.loadFromFile("ASSETS\\SPRITES\\player_right.png")) // error checking and also loading the right sprite
	{
		std::cout << "error loading the player character" << std::endl;
	}

	if (!m_playerUpTexture.loadFromFile("ASSETS\\SPRITES\\player_up.png")) // error checking plus loading up sprite
	{
		std::cout << "error loading the player character" << std::endl;
	}
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
	m_playerSprite.setTexture(m_playerLeftTexture);
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
	m_playerSprite.setTexture(m_playerRightTexture);
	sf::Vector2f pos(m_playerSprite.getPosition());
		if (pos.x <= SCREEN_WIDTH - PLAYER_WIDTH)
		{
			pos.x = pos.x + speed;
		}
		m_playerSprite.setPosition(pos.x, pos.y);
}

void Player::moveUp()
{
	m_playerSprite.setTexture(m_playerUpTexture);
	sf::Vector2f pos(m_playerSprite.getPosition());
	if (pos.y >= 0)
	{
		pos.y = pos.y - speed;
	}
	m_playerSprite.setPosition(pos.x, pos.y);
}

void Player::moveDown()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\SPRITES\\player_down.png")) // error checking plus loading down sprite
	{
		std::cout << "error loading the player character" << std::endl;
	}

	m_playerSprite.setTexture(m_playerTexture);
	sf::Vector2f pos(m_playerSprite.getPosition());


	if (pos.y <= SCREEN_HEIGHT - image_width)
	{
		pos.y = pos.y + speed;
	}
	m_playerSprite.setPosition(pos.x, pos.y);
}


sf::Sprite Player::getBody() // get body
{
	return m_playerSprite; // return sprite body
}

void Player::boundry(sf::Vector2f t_pos)
{
	// boundry checking
	if (t_pos.x <= 0.0f)
	{
		PlayerDirection++;
	}
	if (t_pos.x > SCREEN_WIDTH - image_width)
	{
		PlayerDirection--;
	}
	if (t_pos.y <= 0.0f)
	{
		PlayerDirection++;
	}
	if (t_pos.y > SCREEN_HEIGHT - image_width)
	{
		PlayerDirection--;
	}
}

sf::FloatRect Player::playerBoundingBox()
{
	return m_playerSprite.getGlobalBounds();
}

bool Player::isPlayerAlive()
{
	return isPlayerLiving;
}

bool Player::playerdead()
{
	isPlayerLiving = false;
	return isPlayerLiving;
}

