#include "bullet.h"
#include "Globals.h"
#include "Game.h"
// all typed by me, but was helped in Retention by Peter

Bullet::Bullet()
{
	loadBullet();
}

sf::Sprite Bullet::getBulletBody()
{
	return m_fireballSprite;
}

void Bullet::setPositionBullet(sf::Vector2f playerPosition)
{
	m_fireballSprite.setPosition(playerPosition);
}

void Bullet::loadBullet()
{
	if (!m_fireballDownTexture.loadFromFile("ASSETS\\SPRITES\\fireball_down.png"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}

	if (!m_fireballUpTexture.loadFromFile("ASSETS\\SPRITES\\fireball_up.png"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}

	if (!m_fireballRightTexture.loadFromFile("ASSETS\\SPRITES\\fireball_right.png"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}

	if (!m_fireballLeftTexture.loadFromFile("ASSETS\\SPRITES\\fireball_left.png"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}
}

void Bullet::shootBulletLeft()
{
	bulletDirection = EAST;
	m_fireballSprite.setTexture(m_fireballLeftTexture);
}

void Bullet::shootBulletUp()
{
	bulletDirection = NORTH;
	m_fireballSprite.setTexture(m_fireballUpTexture);
}

void Bullet::shootBulletdown()
{
	bulletDirection = SOUTH;
	m_fireballSprite.setTexture(m_fireballDownTexture);
}

void Bullet::shootBulletRight()
{
	bulletDirection = WEST;
	m_fireballSprite.setTexture(m_fireballRightTexture);
}

sf::FloatRect Bullet::boundingBox()
{
	return m_fireballSprite.getGlobalBounds();
}

bool Bullet::bulletMove()
{
	if (bulletDirection == NORTH)
	{
		m_fireballSprite.move(0, -10);
		return true;
	}

	if (bulletDirection == SOUTH)
	{
		m_fireballSprite.move(0, 10);
		return true;
	}
	if (bulletDirection == WEST)
	{
		m_fireballSprite.move(6, 0);
		return true;
	}
	if (bulletDirection == EAST)
	{
		m_fireballSprite.move(0, 6);
		return true;
	}

	if (m_fireballSprite.getPosition().y < 0.0f);
	{
		return false;
	}

	if (m_fireballSprite.getPosition().x < 0.0f);
	{
		return false;
	}

	return true;
}

void Bullet::speedBulletUp()
{
}
