#include "enemyAA.h"

enemyAA::enemyAA()
{
	loadEnemy();
	moveAA();

	setPositionAA();
	strength = 2;
	speed = 4;
	enemyAlive = true;
}

void enemyAA::loadEnemy()
{
	if (!m_AAEnemyTexture.loadFromFile("ASSETS\\SPRITES\\enemy1_down.png"))
	{
		std::cout << "error loading your first enemy " << std::endl;
	}
	m_AAEnemySprite.setTexture(m_AAEnemyTexture);
}

sf::Sprite enemyAA::getEnemyBody()
{
	return m_AAEnemySprite;
}

void enemyAA::setPositionAA()
{
	m_AAEnemySprite.setPosition(100, 550);
}

void enemyAA::moveAA()
{
	sf::Vector2f pos(m_AAEnemySprite.getPosition());

	if (direction == EAST)
	{
		pos.x = pos.x + speed;
	}
	if (direction == WEST)
	{
		pos.x = pos.x - speed;
	}
	if (direction == NORTH)
	{
		pos.y = pos.y - speed;
	}
	if (direction == SOUTH)
	{
		pos.y = pos.y + speed;
	}
}
