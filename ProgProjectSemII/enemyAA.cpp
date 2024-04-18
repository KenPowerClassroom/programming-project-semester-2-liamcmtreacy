#include "enemyAA.h"
#include "Globals.h"
#include "Game.h"


enemyAA::enemyAA()
{
	// basic info
	loadEnemy();

	setPositionAA();
	strength = 2;
	speed = 5;
	enemyAlive = true;
	direction = (rand()% 4) + 1;
}

void enemyAA::loadEnemy()
{
	if (!m_AAEnemyTexture.loadFromFile("ASSETS\\SPRITES\\enemy1_down.png"))
	{
		std::cout << "error loading your first enemy " << std::endl;
	}

	if (!m_AAEnemyUp.loadFromFile("ASSETS\\SPRITES\\enemy1_up.png"))
	{
		std::cout << "error loading your first enemy " << std::endl;
	}

	if (!m_AAEnemyRight.loadFromFile("ASSETS\\SPRITES\\enemy1_right.png"))
	{
		std::cout << "error loading your first enemy " << std::endl;
	}

	if (!m_AAEnemyLeft.loadFromFile("ASSETS\\SPRITES\\enemy1_left.png"))
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

sf::FloatRect enemyAA::boundBox()
{
	return m_AAEnemySprite.getGlobalBounds();
}

void enemyAA::moveAA()
{
		sf::Vector2f pos(m_AAEnemySprite.getPosition());

		if (direction == EAST) 
		{
			pos.x = pos.x + speed;
			m_AAEnemySprite.setTexture(m_AAEnemyLeft);
		}
		if (direction == WEST)
		{
			pos.x = pos.x - speed;
			m_AAEnemySprite.setTexture(m_AAEnemyRight);
		}
		if (direction == NORTH)
		{
			pos.y = pos.y + speed;
			m_AAEnemySprite.setTexture(m_AAEnemyUp);
		}
		if (direction == SOUTH)
		{
			pos.y = pos.y - speed;
			m_AAEnemySprite.setTexture(m_AAEnemyTexture);
		}

		m_AAEnemySprite.setPosition(pos);
}

void enemyAA::checkBoundry(sf::Vector2f t_pos)
{
	sf::Vector2f pos(m_AAEnemySprite.getPosition());
		if (t_pos.x < 0.0f)
		{
			direction++;
		}
		if (t_pos.x > SCREEN_WIDTH - ENEMY_WIDTH)
		{
			direction--;
		}
		if (t_pos.y < 0.0f)
		{
			direction--;
		}
		if (t_pos.y > SCREEN_HEIGHT - ENEMY_WIDTH)
		{
			direction++;
		}

}

void enemyAA::setDirectionAA()
{
	direction = (rand() % 4) + 1;
}

void enemyAA::speedUp()
{
}

sf::FloatRect enemyAA::AAboundingBox()
{
	return m_AAEnemySprite.getGlobalBounds();
}



