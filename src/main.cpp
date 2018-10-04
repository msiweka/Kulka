#include <SFML/Graphics.hpp>
#include <cmath>

#include "Kulka.h"

int main()
{
	const int speed = 15;
	sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "Kulka");
	Kulka kulka(&mainWindow);

	while (mainWindow.isOpen()) // Main loop
	{
		mainWindow.clear(sf::Color::Black);
		sf::Event event;

		while (mainWindow.pollEvent(event)) // Event loop
		{
			switch (event.type) // Event handling
			{
				case sf::Event::Closed: // close window [X]
				{
					mainWindow.close();
					break;
				}

				case sf::Event::KeyPressed: // Key handling
				{
					switch (event.key.code)
					{
						case sf::Keyboard::Right: // RIGHT KEY
						{
							kulka.moveRight(speed);
							break;
						}

						case sf::Keyboard::Left: // LEFT KEY
						{
							kulka.moveLeft(speed);
							break;
						}

						case sf::Keyboard::Up: // UP KEY
						{
							kulka.moveUp(speed);
							break;
						}

						case sf::Keyboard::Down: // DOWN KEY
						{
							kulka.moveDown(speed);
							break;
						}
					}
					break;
				} // Key handling end
			} // Event handling end
		} // Event loop end
		
		kulka.draw();
		mainWindow.display();
	} // Main loop end
	return 0;
}