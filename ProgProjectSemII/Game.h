// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <SFML/Audio.hpp>
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

	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

	sf::Text m_score;
	sf::Text m_lives;
	sf::Text m_enemiesKilled;
	sf::Text m_gameOver;
	sf::Text m_timer;

	sf::Sprite BGSprite;
	sf::Texture BGTexture;
	sf::RectangleShape m_healthBar;

	int enemiesKilled = 0;
	int gameScore = 0;
	int life = 5;
	float gameTimer = 0.0f;

public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent(); // loads game
	void	run(); // run game
	void	update(); // anything that can be changed is called here
	void	draw(); // draws everything
	void loadBackground(); // loads background
	void setUpAA(); // set position of AA enemy
	void setUpRR(); // set position of RR enemy
	void collisionDetection(); // too see if the player hit the enemies
	void setUpAudio();

	bool isPlayerAlive = true;
};
