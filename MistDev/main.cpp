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

	std::string str;
	sf::Text txt;
	txt.setPosition(sf::Vector2f(0, 100));
	txt.setColor(sf::Color::White);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Failed to load font" << std::endl;
	txt.setFont(font);
	txt.setCharacterSize(24); 


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::BackSpace)
					str = str.substr(0, (str.size()) - 1);
				if (event.key.code == sf::Keyboard::Return)
					str = "";
				txt.setString(str);
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					str += static_cast<char>(event.text.unicode);
					txt.setString(str);
				}

			}


		}

		window.clear();
		window.draw(shape);
		window.draw(txt);
		window.display();
	}

	return 0;
}
