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

}
