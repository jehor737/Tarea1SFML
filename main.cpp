/*Jesús Horacio Rojas Cortés A01020026*/
#include "Box.h"
#include "LinkedList.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
void makeList(sf::RenderWindow* window);
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Boxes");
	sf::Thread thread(&makeList, &window);
	thread.launch();
	while (window.isOpen())
	{
		//thread.launch();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
		  //thread.launch();
			if (event.type == sf::Event::Closed)
			{
				thread.terminate();
				window.close();
			}
			window.clear();
			window.display();
		}
	}
	return 0;
}

void makeList(sf::RenderWindow* window)
{
	LinkedList<Box> linkedList;
	char option = 'a';
	while(window->isOpen())
	{
		//window->clear();
		//window->display();

		while (option != 'q')
		{
	    cout<<"a. New random box" <<endl;
	    cout<<"b. New custom box" <<endl;
	    cout<<"q. Quit program" <<endl;
	    cin>>option;
	    switch (option) {
	      case 'a':
	      {
	        Box new_box;
	        cout<< new_box.getX()<<", "<<new_box.getY()<<endl;
	        sf::RectangleShape boxes(sf::Vector2f(new_box.getWidth(), new_box.getHeight()));
	        boxes.setPosition(new_box.getX(), new_box.getY());
	        window->draw(boxes);
	        window->display();
	        linkedList.insertTail(new_box);
	        break;
	      }

	      case 'b':
	      {
	        Box new_box;
	        unsigned int custom;
	        cout << "Set width" <<endl;
	        cin>>custom;
	        new_box.setWidth(custom);
	        cout << "Set height" <<endl;
	        cin>>custom;
	        new_box.setHeight(custom);
	        cout<< new_box.getX()<<", "<<new_box.getY()<<endl;
	        sf::RectangleShape boxe(sf::Vector2f(new_box.getWidth(), new_box.getHeight()));
	        boxe.setPosition(new_box.getX(), new_box.getY());
	        window->draw(boxe);
	        window->display();
	        linkedList.insertTail(new_box);
	        break;
	      }

	      case 'q':
	        window->close();
	        break;
	    }
		}
	}
}
