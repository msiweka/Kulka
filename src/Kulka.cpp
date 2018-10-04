#include "Kulka.h"


Kulka::Kulka(sf::RenderWindow * mainWindow) :
	_parentWindow(mainWindow)
{
	sf::Color mask(249, 17, 255);

	sf::Image kulkaTexture;
	kulkaTexture.loadFromFile("..\\sprites\\kulka.png");

	kulkaTexture.createMaskFromColor(mask);
	texture.loadFromImage(kulkaTexture);

	width = kulkaTexture.getSize().x;
	height = kulkaTexture.getSize().y;

	kulka.setTexture(texture);
}

Kulka::~Kulka()
{
}

void Kulka::draw()
{
	_parentWindow->draw(kulka);
}

void Kulka::moveUp(float speed)
{
	sf::Vector2f position = kulka.getPosition();
	if (position.y - speed > 0)
		kulka.move(0, -speed);

	else
		kulka.setPosition(position.x, 0);
}

void Kulka::moveDown(float speed)
{
	sf::Vector2f position = kulka.getPosition();
	if (position.y + speed < _parentWindow->getSize().y - height)
		kulka.move(0, speed);

	else
		kulka.setPosition(position.x, _parentWindow->getSize().y - height);
}

void Kulka::moveLeft(float speed)
{
	sf::Vector2f position = kulka.getPosition();
	if (position.x - speed > 0)
		kulka.move(-speed, 0);

	else
		kulka.setPosition(0, position.y);
}

void Kulka::moveRight(float speed)
{
	sf::Vector2f position = kulka.getPosition();
	if (position.x + speed < _parentWindow->getSize().x - width)
		kulka.move(speed, 0);

	else
		kulka.setPosition(_parentWindow->getSize().x - width, position.y);
}
