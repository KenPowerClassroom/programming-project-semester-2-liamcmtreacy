#include"enemyRR.h"
#include"Game.h"
#include"Globals.h"

enemyRR::enemyRR()
{
	loadEnemy();
	setPositionRR();

	RRstrength = 4;
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

void enemyRR::moveRR(const sf::Vector2f& playerPosition)
{
	sf::Vector2f RRPos = RRSprite.getPosition();

	sf::Vector2f direction = playerPosition - RRPos;

	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	direction /= distance;

	float speedOfFollower = 2;
	RRSprite.move(direction * speedOfFollower);
	//typed myself, but helped by Shane Moran

}

void enemyRR::checkBoundry(sf::Vector2f t_pos)
{
}

void enemyRR::setDirectionRR()
{
}


