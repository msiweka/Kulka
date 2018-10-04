#pragma once

#include <SFML/Graphics.hpp>

class Kulka
{
public:
	Kulka(sf::RenderWindow *parentWindow);
	~Kulka();

	void draw();

	void moveUp(float speed);
	void moveDown(float speed);
	void moveLeft(float speed);
	void moveRight(float speed);
private:
	sf::RenderWindow *_parentWindow;

	sf::Texture texture;
	sf::Sprite kulka;

	int width;
	int height;
};

