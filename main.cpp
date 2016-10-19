/*Jesús Horacio Rojas Cortés A01020026
A01020026@itesm.mx
Main class with SFML functions to draw a list of boxes
*/
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
	LinkedList<Box> box_LinkedList;//create the linked list
	sf::RenderWindow window(sf::VideoMode(800, 600), "Boxes");//create the window
	window.setActive(false);
	sf::Thread thread(&makeList, &box_LinkedList);//create the thread to show the options and make the list
	thread.launch();
	sf::Font font;
	font.loadFromFile("arial.ttf");//font for write the numbers in the list
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//check if the window is closed externally
			{
				thread.terminate();
				window.close();//finish the program
			}
		}
			window.clear();

		for(int i = 0; box_LinkedList.size() > i ; i++)
		{
			sf::Text text(std::to_string(i), font, SIZE_TEXT);//create the text dialog
			text.setColor(sf::Color::White);
			sf::RectangleShape boxes(sf::Vector2f(box_LinkedList.getDataAtPosition(i).getWidth(), box_LinkedList.getDataAtPosition(i).getHeight()));//create the box
			boxes.setPosition(box_LinkedList.getDataAtPosition(i).getX(), box_LinkedList.getDataAtPosition(i).getY());//and set its size, position and color according to the data in the linked list
			boxes.setFillColor(sf::Color(box_LinkedList.getDataAtPosition(i).getRed(), box_LinkedList.getDataAtPosition(i).getGreen(), box_LinkedList.getDataAtPosition(i).getBlue()));
			text.setPosition( (box_LinkedList.getDataAtPosition(i).getX() + 0.5*box_LinkedList.getDataAtPosition(i).getWidth()) , (box_LinkedList.getDataAtPosition(i).getY() + 0.5*box_LinkedList.getDataAtPosition(i).getHeight()));
			window.draw(boxes);
			window.draw(text);//draw the box and the number of the box
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
		std::cout<<"c. New random box at position" <<std::endl;
		std::cout<<"d. New custom box at position" <<std::endl;
		std::cout<<"e. Delete the list" <<std::endl;
		std::cout<<"f. Delete the last box" <<std::endl;
		std::cout<<"g. Delete a specific box" <<std::endl;
		std::cout<<"h. Delete the first box" <<std::endl;
	    std::cout<<"q. Quit program" <<std::endl;
		std::cout<<"Enter your selection" <<std::endl;
	    cin>>option;
	    switch (option)
	    {
			case 'a':
	    	{
	        	Box new_box;
	        	box_LinkedList->insertTail(new_box);//insert a random box
	    
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
	        	box_LinkedList->insertTail(new_box);
	        	
	        break;
	    	}
	    	
	    	case 'c':
	    	{
	    		int position;
	    		std::cout << "Enter the position you want to insert" << std::endl;
	    		std::cin >> position;
	    		Box new_box;
	    		box_LinkedList->insertAtPosition(new_box, position);
	    		
	        break;
	    	}
	    	
	    	case 'd':
	    	{
	        	unsigned int x, y, width, height;
	        	int position;
	        	std::cout << "Set width" <<std::endl;
	        	cin>>width;
	        	std::cout << "Set height" <<std::endl;
	        	cin>>height;
	        	std::cout << "Enter the distance from the top of the screen: " <<std::endl;
	        	cin>>y;
	        	std::cout << "Enter the distance from the left of the screen: " <<std::endl;
	        	cin>>x;
	        	std::cout << "Enter the position you want to insert" << std::endl;
	        	std::cin >> position;
	        	Box new_box(x, y, width, height);
	        	box_LinkedList->insertAtPosition(new_box, position);
	        break;
	    	}
	    	
	    	case 'e':
	    		box_LinkedList->clear();
	    	break;
	    	
	    	case 'f':
	    		box_LinkedList->removeTail();
	    	break;
	    	
	    	case 'g':
	    		int position;
	    		std::cout << "Enter the position you want to delete " << std::endl;
	    		std::cin >> position;
	    		box_LinkedList->removeFromPosition(position);
	    	break;
	    	
	    	case 'h':
	    		box_LinkedList->removeHead();
	    	break;
	    	
	    	case 'q':
	    		std::cout << "End of the program" <<std::endl;
	    		exit(0);
	    	break;
	    }
	}
}