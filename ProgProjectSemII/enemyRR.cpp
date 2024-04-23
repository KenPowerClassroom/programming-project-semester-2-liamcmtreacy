#include"enemyRR.h"
#include"Game.h"
#include"Globals.h"

enemyRR::enemyRR()
{
	loadEnemy();
	setPositionRR();

	RRalive = true;
	RRdirection = EAST;
	RRspeedFollowing = 2.5;
}

void enemyRR::loadEnemy()
{
	if (!RRTexture.loadFromFile("ASSETS\\SPRITES\\enemy2_down.png"))
	{
		std::cout << "error loading the second enemy" << std::endl;
	}

	if (!RRTexture.loadFromFile("ASSETS\\SPRITES\\enemy2_up.png"))
	{
		std::cout << "error loading the second enemy" << std::endl;
	}

	if (!RRTexture.loadFromFile("ASSETS\\SPRITES\\enemy2_right.png"))
	{
		std::cout << "error loading the second enemy" << std::endl;
	}

	if (!RRTexture.loadFromFile("ASSETS\\SPRITES\\enemy2_left.png"))
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

	RRSprite.move(direction * RRspeedFollowing);
	//typed myself, but got some guidance and help by Shane Moran

}

void enemyRR::checkBoundryRR(sf::Vector2f t_pos)
{
	sf::Vector2f RRpos(RRSprite.getPosition());

	if (t_pos.x < 0.0f)
	{
		RRdirection++;
	}
	if (t_pos.x > SCREEN_WIDTH - ENEMY_WIDTH)
	{
		RRdirection--;
	}
	if (t_pos.y < 0.0f)
	{
		RRdirection--;
	}
	if (t_pos.y > SCREEN_HEIGHT - ENEMY_WIDTH)
	{
		RRdirection++;
	}
}

sf::FloatRect enemyRR::getBoundingBoxRR()
{
	return RRSprite.getGlobalBounds();
}

void enemyRR::RRspeedUp()
{
	RRspeedFollowing = 4.3;
}

void enemyRR::resetSpeed()
{
	RRspeedFollowing = 2.5;
}
