#include "enemyAA.h"

enemyAA::enemyAA()
{
	// basic info
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
	m_AAEnemySprite.setTexture(m_AAEnemyTexture); // loading AA
}

sf::Sprite enemyAA::getEnemyBody()
{
	return m_AAEnemySprite; // returning the sprite
}

void enemyAA::setPositionAA()
{
	m_AAEnemySprite.setPosition(100, 550); // set position of AA
}

void enemyAA::setPositionAA(int xPos, int yPos)
{
	m_AAEnemySprite.setPosition(xPos, yPos);
}

void enemyAA::moveAA()
{
	sf::Vector2f pos(m_AAEnemySprite.getPosition());

	if (direction == EAST) // moving left
	{
		pos.x = pos.x + speed;
	}
	if (direction == WEST) // moving right
	{
		pos.x = pos.x - speed;
	} 
	// moving up
	if (direction == NORTH)
	{
		pos.y = pos.y - speed;
	}
	if (direction == SOUTH) // moving down
	{
		pos.y = pos.y + speed;
	}
}
