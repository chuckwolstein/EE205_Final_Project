#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#define SAFE 1
#define UNSAFE 0

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "J-Walker!!!");

	sf::RectangleShape jwalker;

	jwalker.setSize(sf::Vector2f(80, 80));
	jwalker.setPosition(sf::Vector2f(jwalker.getPosition().x, window.getSize().y - jwalker.getSize().y));


	sf::RectangleShape car;

	car.setSize(sf::Vector2f(120, 60));
	car.setFillColor(sf::Color::Red);
	car.setPosition(sf::Vector2f(car.getPosition().x, window.getSize().y / 2 - car.getSize().y));

	while (window.isOpen())
	{
		// handle events
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:

				if (sf::Keyboard::Key::Left == event.key.code)
				{
					jwalker.move(-80, 0);
				}
				else if (sf::Keyboard::Key::Right == event.key.code)
				{
					jwalker.move(80, 0);
				}
				else if (sf::Keyboard::Key::Up == event.key.code)
				{
					jwalker.move(0, -80);
				}
				else if (sf::Keyboard::Key::Down == event.key.code)
				{
					jwalker.move(0, 80);
				}
			}
		}

		// update
		car.move(0.2, 0);

		if (car.getPosition().x > window.getSize().x)
		{
			car.setPosition(sf::Vector2f(-car.getSize().x, window.getSize().y / 2 - car.getSize().y));
		}

		if (jwalker.getGlobalBounds().intersects(car.getGlobalBounds()))
		{
			window.close();
		}

		window.clear();

		// draw SFML content
		window.draw(jwalker);
		window.draw(car);

		window.display();
	}

	return EXIT_SUCCESS;
}
