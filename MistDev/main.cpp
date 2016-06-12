// main.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<iostream>
#include<SFML\Graphics.hpp>

int main()
{
	//I MADE A CHANGE :O IT RUNS :O
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::RectangleShape shape(sf::Vector2f(100,100));
	shape.setPosition(sf::Vector2f(50, 50));
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
