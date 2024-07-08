#include <SFML/Graphics.hpp>
#include <iostream>
#include "spectrum_visualize.h"

using namespace std;


int main()
{
	cout << "Type the file name of the audio you want visualized\n";
	cout << "File name: ";
	string fileName;
	cin >> fileName;
	cout << "\nLoading...";

	Spectrum_visualize sp(fileName);

	bool isPlayed = false;
	float time_per_frame = 1 / 60.f;
	float time_since_last_update = 0.f;
	sf::Clock c;
	
	float time_fps = 0.f;
	int count_frame = 0;

	sf::RenderWindow window(sf::VideoMode(1000, 600), "Sound Visualizer");
	sp.play();
	isPlayed = true;


	while (window.isOpen())
	{
		time_since_last_update += c.restart().asSeconds();

		while (time_since_last_update >= time_per_frame)
		{
			time_since_last_update -= time_per_frame;

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)					
				{
					
					isPlayed = true;
				}

			}

			
		}

		if (isPlayed)
		{
			sp.update(time_per_frame);
		}

		

		window.clear();
		sp.draw(window);
		window.display();

		time_fps += c.getElapsedTime().asSeconds();
		count_frame++;
		if (time_fps >= 1.f)
		{
			time_fps -= 1.f;
			//system("cls");
			//cout << "FPS: " << count_frame;
			count_frame = 0;
		}
	}

	return 0;
}
