
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#define SAFE 1
#define UNSAFE 0
#define NUM_LANES 6
#define NUM_ENEMIES 4
#define GAME_HEIGHT 1000
#define GAME_WIDTH 800
#define CELL_HEIGHT 50
#define CELL_WIDTH 50

int main()
{
	sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "													J-Walker!!!");
	window.setVerticalSyncEnabled(true);
	sf::RectangleShape jwalker;

	jwalker.setSize(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT));
	jwalker.setFillColor(sf::Color::Yellow);
	jwalker.setPosition(sf::Vector2f(jwalker.getPosition().x, window.getSize().y - jwalker.getSize().y));
	sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window.getDefaultView().getSize());

	Enemy_Lane lane1(0, NUM_ENEMIES, true);
  Enemy_Lane lane2(50, NUM_ENEMIES,false);
  Enemy_Lane lane3(100, NUM_ENEMIES,true);
  Enemy_Lane lane4(150, NUM_ENEMIES, false);
  Enemy_Lane lane5(200, NUM_ENEMIES,true);
  Enemy_Lane lane6(250, NUM_ENEMIES,false);
	Enemy_Lane lane7(300, NUM_ENEMIES,true);
	Enemy_Lane lane8(350, NUM_ENEMIES,false);
	Enemy_Lane lane9(400, NUM_ENEMIES,true);
	Enemy_Lane lane10(450, NUM_ENEMIES,false);
	Enemy_Lane lane11(500, NUM_ENEMIES,true);
	Enemy_Lane lane12(550, NUM_ENEMIES,false);
	Enemy_Lane lane13(600, NUM_ENEMIES,true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
				if (event.type == sf::Event::Closed)
								window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
						jwalker.move(0, -5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
						jwalker.move(0, 5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
						jwalker.move(-5, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
						jwalker.move(5, 0);
		}
		// handle events
	/*	sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				//Move Left
				if (sf::Keyboard::Left == event.key.code)
				{
					jwalker.move(-50, 0);
				}
				//Move Right
				else if (sf::Keyboard::Right == event.key.code)
				{
					jwalker.move(50, 0);
				}
				//Move Up
				else if (sf::Keyboard::Up == event.key.code)
				{
					jwalker.move(0, -50);
				}
				//Move Down
				else if (sf::Keyboard::Down == event.key.code)
				{
					jwalker.move(0, 50);
				}
				//Escape using ESC key
				else if (sf::Keyboard::Escape == event.key.code)
				{
					window.close();
				}
				//Pause the screen
				else if (sf::Keyboard::Space == event.key.code)
				{

				}
			}*/
		}
//set walker bounds
		sf::Vector2f position = jwalker.getPosition();
		position.y = std::max(position.y, windowBounds.top);
		position.y = std::min(position.y, windowBounds.top + windowBounds.height - jwalker.getSize().y);
		position.x = std::max(position.x, windowBounds.left);
		position.x = std::min(position.x, windowBounds.left + windowBounds.width - jwalker.getSize().x);
		jwalker.setPosition(position);

//detect collisions

for(int i = 0; i<lane1.enemies.size();++i){
	if ((jwalker.getGlobalBounds().intersects(lane1.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane2.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane3.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane4.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane5.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane6.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane7.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane8.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane9.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane10.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane11.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane12.enemies[i].getGlobalBounds())) ||
			(jwalker.getGlobalBounds().intersects(lane13.enemies[i].getGlobalBounds()))){
		window.close();
		}
}
window.clear();

		// draw SFML content
lane1.refresh();
lane2.refresh();
lane3.refresh();
lane4.refresh();
lane5.refresh();
lane6.refresh();
		lane7.refresh();
		lane8.refresh();
		lane9.refresh();
		lane10.refresh();
		lane11.refresh();
		lane12.refresh();
		lane13.refresh();
		window.draw(jwalker);
		for(int i = 0; i<lane1.enemies.size();++i){
			window.draw(lane1.enemies[i]);
			window.draw(lane2.enemies[i]);
			window.draw(lane3.enemies[i]);
			window.draw(lane4.enemies[i]);
			window.draw(lane5.enemies[i]);
			window.draw(lane6.enemies[i]);
			window.draw(lane7.enemies[i]);
			window.draw(lane8.enemies[i]);
			window.draw(lane9.enemies[i]);
			window.draw(lane10.enemies[i]);
			window.draw(lane11.enemies[i]);
			window.draw(lane12.enemies[i]);
			window.draw(lane13.enemies[i]);
		}
		window.display();
	}

//	return EXIT_SUCCESS;
//}
