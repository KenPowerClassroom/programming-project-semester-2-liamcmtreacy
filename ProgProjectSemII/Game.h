// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include "enemyAA.h"
#include "enemyRR.h"
#include "bullet.h"

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	Player myPlayer;
	enemyAA arrayAA[3]; // standard enemy, named AA
	enemyRR arrayRR[2]; // FOLLOWER ENEMY. NAMED RUSTY RAYMOND

	Bullet playerBullet;
	sf::RenderWindow window;

public:

	int directionFacing;

	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

	sf::Text m_score;
	sf::Text m_lives;
	sf::Text m_enemiesKilled;

	sf::Sprite BGSprite;
	sf::Texture BGTexture;
	sf::RectangleShape m_healthBar;

	int enemiesKilled = 0;
	int gameScore = 0;

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update(); // call everything in update
	void	draw();
	void loadBackground(); // loads background
	void setUpAA(); // set position of AA enemy
	void setUpRR(); // set position of RR enemy
	void collisionDetection(); 

	bool isBulletActive{ false };
};
