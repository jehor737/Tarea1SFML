/*Jesús Horacio Rojas Cortés A01020026*/
#include "Box.h"
#include "LinkedList.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define SIZE_TEXT 20
void makeList(LinkedList<Box>* box_LinkedList);
int main()
{
	srand(time(NULL));
	LinkedList<Box> box_LinkedList;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Boxes");
	window.setActive(false);
	sf::Thread thread(&makeList, &box_LinkedList);
	thread.launch();
	sf::Font font;
	font.loadFromFile("arial.ttf");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				thread.terminate();
				window.close();
			}
		}
			window.clear();

			for(int i = 0; box_LinkedList.size() > i ; i++)
			{
				sf::Text text(std::to_string(i + 1), font, SIZE_TEXT);
				text.setColor(sf::Color::Green);
				sf::RectangleShape boxes(sf::Vector2f(box_LinkedList.getDataAtPosition(i).getWidth(), box_LinkedList.getDataAtPosition(i).getHeight()));
				boxes.setPosition(box_LinkedList.getDataAtPosition(i).getX(), box_LinkedList.getDataAtPosition(i).getY());
				boxes.setFillColor(sf::Color(box_LinkedList.getDataAtPosition(i).getRed(), box_LinkedList.getDataAtPosition(i).getGreen(), box_LinkedList.getDataAtPosition(i).getBlue()));
				text.setPosition( (box_LinkedList.getDataAtPosition(i).getX() + 0.5*box_LinkedList.getDataAtPosition(i).getWidth()) , (box_LinkedList.getDataAtPosition(i).getY() + 0.5*box_LinkedList.getDataAtPosition(i).getHeight()));
				window.draw(boxes);
				window.draw(text);
			}
			window.display();
	}
	return 0;
}

void makeList(LinkedList<Box>* box_LinkedList)
{

	char option = 'x';
		while (option != 'q')
		{
			std::cout << "\n== Box List Test Menu ==\n";
	    std::cout<<"a. New random box" <<std::endl;
	    std::cout<<"b. New custom box" <<std::endl;
			std::cout<<"c. Delete boxes" <<std::endl;
	    std::cout<<"q. Quit program" <<std::endl;
	    cin>>option;
	    switch (option) {
	      case 'a':
	      {
	        Box new_box;
	        std::cout<< new_box.getX()<<", "<<new_box.getY()<<std::endl;
	        box_LinkedList->insertTail(new_box);
	        break;
	      }

	      case 'b':
	      {
	        unsigned int x, y, width, height;
	        std::cout << "Set width" <<std::endl;
	        cin>>width;
	        std::cout << "Set height" <<std::endl;
	        cin>>height;
					std::cout << "Enter the distance from the top of the screen: " <<std::endl;
	        cin>>y;
	        std::cout << "Enter the distance from the left of the screen: " <<std::endl;
	        cin>>x;
					Box new_box(x, y, width, height);
	        std::cout<< new_box.getX()<<", "<<new_box.getY()<<std::endl;
	        box_LinkedList->insertTail(new_box);
	        break;
	      }

				case 'c':
					box_LinkedList->clear();
				break;

	      case 'q':
	        std::cout << "End of the program" <<std::endl;
	        break;
	    }
		}
		return;
}
