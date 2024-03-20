#include "enemyAA.h"

enemyAA::enemyAA()
{
	loadEnemy();
	moveAA();

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

void enemyAA::moveAA()
{
}

void enemyAA::setPositionAA()
{
	setPositionAA();
}

void enemyAA::setPositionAA(int posX, int posY)
{
	setPositionAA(posX, posY);
}
