#include "enemyCC.h"

enemyCC::enemyCC()
{
	loadCCenemy();

	CCalive = true;
	CCspeed = 4;
	directionCC = SOUTH;
}

void enemyCC::loadCCenemy()
{
	if (!CCTexture.loadFromFile("ASSETS\\SPRITES\\redGhost.png"))
	{
		std::cout << "error loading the third enemy" << std::endl;
	}

	if (!CCTextureRight.loadFromFile("ASSETS\\SPRITES\\redGhostright.png"))
	{
		std::cout << "error loading the third enemy" << std::endl;
	}
	m_enemyCCsprite.setTexture(CCTexture);
}

sf::Sprite enemyCC::getCCBody()
{
	return m_enemyCCsprite;
}

void enemyCC::setPositionCC()
{
	m_enemyCCsprite.setPosition(650, 102);
}

void enemyCC::setPositionCC(int xPos, int yPos)
{
	m_enemyCCsprite.setPosition(xPos, yPos);
}

sf::FloatRect enemyCC::boundBoxCC()
{
	return m_enemyCCsprite.getGlobalBounds();
}

void enemyCC::moveCC()
{
	sf::Vector2f pos(m_enemyCCsprite.getPosition());

	if (directionCC == EAST)
	{
		pos.x = pos.x + CCspeed;
		m_enemyCCsprite.setTexture(CCTextureRight);
	}
	if (directionCC == WEST)
	{
		pos.x = pos.x - CCspeed;
		m_enemyCCsprite.setTexture(CCTexture);
	}
	if (directionCC == NORTH)
	{
		pos.y = pos.y + CCspeed;
	}
	if (directionCC == SOUTH)
	{
		pos.y = pos.y - CCspeed;
	}

	m_enemyCCsprite.setPosition(pos);
}

void enemyCC::checkBoundryCC(sf::Vector2f t_pos)
{
	sf::Vector2f CCpos(m_enemyCCsprite.getPosition());
	if (t_pos.x < 0.0f)
	{
		directionCC++;
	}
	if (t_pos.x > SCREEN_WIDTH - ENEMY_WIDTH)
	{
		directionCC--;
	}
	if (t_pos.y < 0.0f)
	{
		directionCC--;
	}
	if (t_pos.y > SCREEN_HEIGHT - ENEMY_WIDTH)
	{
		directionCC++;
	}
}

void enemyCC::speedUpCC()
{
	CCspeed = 8;
}

void enemyCC::maxSpeedCC()
{
	CCspeed = 13;
}

void enemyCC::changeDirection()
{
	directionCC = (rand() % 4) + 1;
}
