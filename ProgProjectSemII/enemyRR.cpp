#include"enemyRR.h"
#include"Game.h"
#include"Globals.h"

enemyRR::enemyRR()
{
	loadEnemy();
	setPositionRR();

	RRstrength = 4;
	RRspeed = 4;
	RRalive = true;
	RRdirection = EAST;
}

void enemyRR::loadEnemy()
{
	if (!RRTexture.loadFromFile("ASSETS\\SPRITES\\enemy2_down.png"))
	{
		std::cout << "error loading the second enemy" << std::endl;
	}

	RRSprite.setTexture(RRTexture);
}

sf::Sprite enemyRR::getRRbody()
{
	return RRSprite;
}

void enemyRR::setPositionRR()
{
	RRSprite.setPosition(800, 780);
}

void enemyRR::setPositionRR(int xPos, int yPos)
{
	RRSprite.setPosition(xPos, yPos);
}

void enemyRR::moveRR()
{
	sf::Vector2f position(RRSprite.getPosition());
}

void enemyRR::checkBoundry(sf::Vector2f t_pos)
{
}

void enemyRR::setDirectionRR()
{
}


