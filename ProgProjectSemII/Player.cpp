
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
	if (!m_playerTexture.loadFromFile("ASSETS\\SPRITES\\player_left.png")) // error checking and also loading the left sprite
	{
		std::cout << "error loading the player character" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);

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

	if (!m_playerTexture.loadFromFile("ASSETS\\SPRITES\\player_right.png")) // error checking and also loading the right sprite
	{
		std::cout << "error loading the player character" << std::endl;
	}

	m_playerSprite.setTexture(m_playerTexture);
	sf::Vector2f pos(m_playerSprite.getPosition());
		if (pos.x <= SCREEN_WIDTH - PLAYER_WIDTH)
		{
			pos.x = pos.x + speed;
		}
		m_playerSprite.setPosition(pos.x, pos.y);
}

void Player::moveUp()
{
	if (!m_playerTexture.loadFromFile("ASSETS\\SPRITES\\player_up.png")) // error checking plus loading up sprite
	{
		std::cout << "error loading the player character" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);

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
		direction++;
	}
	if (t_pos.x > SCREEN_WIDTH - image_width)
	{
		direction--;
	}
	if (t_pos.y <= 0.0f)
	{
		direction++;
	}
	if (t_pos.y > SCREEN_HEIGHT - image_width)
	{
		direction--;
	}
}

