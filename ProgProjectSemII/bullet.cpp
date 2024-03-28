#include "bullet.h"

Bullet::Bullet()
{
	loadBullet();
}

void Bullet::loadBullet()
{
	if (!m_fireballTexture.loadFromFile("ASSETS\\SPRITES\\fireball_down"))
	{
		std::cout << "error loading the fireball sprites " << std::endl;
	}
	m_fireballSprite.setTexture(m_fireballTexture);
}

void Bullet::setPositionBullet()
{
}

void Bullet::speedBulletUp()
{
}
