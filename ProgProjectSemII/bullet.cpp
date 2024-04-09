#include "bullet.h"
#include "Globals.h"
#include "Game.h"

Bullet::Bullet()
{
	loadBullet();
}

void Bullet::loadBullet()
{
	if (!m_fireballDownTexture.loadFromFile("ASSETS\\SPRITES\\fireball_down"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}

	if (!m_fireballUpTexture.loadFromFile("ASSETS\\SPRITES\\fireball_up"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}

	if (!m_fireballRightTexture.loadFromFile("ASSETS\\SPRITES\\fireball_right"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}

	if (!m_fireballLeftTexture.loadFromFile("ASSETS\\SPRITES\\fireball_left"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}
}

void Bullet::shootBulletLeft()
{
	didPlayerShoot = true;
	bulletDirection = EAST;
	m_fireballSprite.setTexture(m_fireballLeftTexture);
}

void Bullet::shootBulletUp()
{
	didPlayerShoot = true;
	bulletDirection = NORTH;
	m_fireballSprite.setTexture(m_fireballUpTexture);
}

void Bullet::shootBulletdown()
{
	didPlayerShoot = true;
	bulletDirection = SOUTH;
	m_fireballSprite.setTexture(m_fireballDownTexture);
}

void Bullet::shootBulletRight()
{
	didPlayerShoot = true;
	bulletDirection = WEST;
	m_fireballSprite.setTexture(m_fireballRightTexture);
}

void Bullet::setPositionBullet()
{
}

void Bullet::speedBulletUp()
{
}
