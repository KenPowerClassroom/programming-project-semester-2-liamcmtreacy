// Name: Liam Treacy
// Login: started MARCH 20th 2024 9:08am
// Date: 20/03/24
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib")




#include "Game.h"   // include Game header file
#include "enemyAA.h" // enemyAA header
#include "RustyRaymond.h" //RR header


int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// Load the font file & setup the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file" << std::endl;
	}

	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

	m_score.setFont(m_font);  // set the font for the text
	m_score.setCharacterSize(24); // text size
	m_score.setFillColor(sf::Color::White); // color
	m_score.setPosition(10, 40);  // score total and its position on the screen

	m_lives.setFont(m_font);  // text font
	m_lives.setCharacterSize(24); //text size
	m_lives.setFillColor(sf::Color::White); // setting the color white for the text
	m_lives.setPosition(10, 70);  // position next to the score and message

	m_enemiesKilled.setFont(m_font);  // set the font for the text
	m_enemiesKilled.setCharacterSize(24); // set the text size
	m_enemiesKilled.setFillColor(sf::Color::White); // set the text colour
	m_enemiesKilled.setPosition(10, 100);  // its position on the screen

	setUpAA();
	loadBackground();
}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();
<<<<<<< HEAD
=======
			setUpAA(); // don't do setup inside game loop, this should be done BEFORE the game loop
			
>>>>>>> af7cf51ee158c7322edb9ced3293ed30aa8f01da
			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		myPlayer.moveLeft(); // calling move left function
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myPlayer.moveRight(); // calling moveRight function
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		myPlayer.moveUp(); // calling move up function
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		myPlayer.moveDown(); // calling move down function
	}
	// update any game variables here 
	AAenemy.moveAA();
	arrayAA[0].moveAA();
	arrayAA[1].moveAA();
	arrayAA[2].moveAA();
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	m_message.setString("Game Play");
	m_score.setString("Score: ");
	m_lives.setString("Lives: ");
	m_enemiesKilled.setString("Enemies Killed: ");
	window.draw(BGSprite); // draw the Sprite for background
	window.draw(m_score); // write score to the screen
	window.draw(m_lives);
	window.draw(m_enemiesKilled);
	window.draw(m_message);  // write message to the screen
	window.draw(myPlayer.getBody()); // draw the player character
<<<<<<< HEAD
	window.draw(AAenemy.getEnemyBody());
	for (int plus = 0; plus < MAXAA; plus++)
=======
	window.draw(RRenemy.getRRbody());

	window.draw(AAenemy.getEnemyBody());

	for (int index = 0; index < MAXAA; index++)
>>>>>>> af7cf51ee158c7322edb9ced3293ed30aa8f01da
	{
		window.draw(arrayAA[plus].getEnemyBody());
	}
	window.draw(RRenemy.getRRbody());
	window.display();
}

void Game::loadBackground()
{
	(!BGTexture.loadFromFile("ASSETS\\SPRITES\\floor.png"));
	{
		std::cout << "error loading the background image" << std::endl; // error message if background fails
	}
	BGTexture.setRepeated(true); // always showing
	BGSprite.setTexture(BGTexture); // setTexture and Sprite together
	BGSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
}

void Game::setUpAA() // set up positions
{
	for (int index = 0; index < MAXAA; index++)
	{
		arrayAA[0].setPositionAA(300, 300);
		arrayAA[1].setPositionAA(480, 100);
		arrayAA[2].setPositionAA(1400, 250);
	}
}

void Game::setUpRR()
{
	RRenemy.setPositionRR(550, 500);
}
