#include <iostream>
#include <random>
#include <time.h>

const char* INDENT = "\t";

const int EMPTY = 0;
    const int ENEMY = 1;
    const int TREASURE = 2;
    const int FOOD = 3;
    const int ENTRANCE = 4;
    const int EXIT = 5;
	const  int  MAX_RANDOM_TYPE = FOOD + 1;

	const int MAZE_WIDTH = 10;
	const int MAZE_HEIGHT = 6;


const char* EMPTY_TILE = "[ \xb0 ]";
	const char* ENEMY_TILE = "[ \x94 ]";
	const char* TREASURE_TILE = "[ $ ]";
	const char* FOOD_TILE = "[ \xcf ]";
	const char* ENTRANCE_TILE = "[ \x9d ]";
	const char* EXIT_TILE = "[ \xFE ]";

void main()
{

	// these are all consrant ints to define each room

	




	int height = 0;
	char firstLetterOfName = 0;
	int avatarHP = 0;

	// this is the 2D array

	int rooms[MAZE_HEIGHT][MAZE_HEIGHT];

	srand(time(nullptr));

	// fill array with random rooms 
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			int type = rand() % (MAX_RANDOM_TYPE * 2);
			if (type < MAX_RANDOM_TYPE)
				rooms[y][x] = type;
			else
				rooms[y][x] = EMPTY;
		}
	}

	// code to fill teh array/map with random room types 
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		std::cout << INDENT;
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			switch (rooms[y][x])
			{
			case EMPTY:
				std::cout << EMPTY_TILE;
				break;
			case ENEMY:
				std::cout << ENEMY_TILE;
				break;
			case TREASURE:
				std::cout << TREASURE_TILE;
				break;
			case FOOD:
				std::cout << FOOD_TILE;
				break;
			case ENTRANCE:
				std::cout << ENTRANCE_TILE;
				break;
			case EXIT:
				std::cout << EXIT_TILE;
				break;
			}
			      
		}
		std::cout << std::endl;
	}
	// set the enterence and exit of the map 
	rooms[0][0] = ENTRANCE;

	rooms[MAZE_HEIGHT - 1][MAZE_WIDTH - 1] = EXIT;


	system("cls");

	    std::cout << INDENT << INDENT << "Welcome to ZORP!" << std::endl; 
		std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning" << std::endl;


		std::cout << INDENT << "It is definitely not related to any other text-based adventure games" << std::endl << std::endl;


		std::cout << INDENT << "First, some questions..." << std::endl;


		// code to fill teh array/map with random room types 
		for (int y = 0; y < MAZE_HEIGHT; y++)
		{
			std::cout << INDENT;
			for (int x = 0; x < MAZE_WIDTH; x++)
			{
				switch (rooms[y][x])
				{
				case EMPTY:
					std::cout << EMPTY_TILE;
					break;
				case ENEMY:
					std::cout << ENEMY_TILE;
					break;
				case TREASURE:
					std::cout << TREASURE_TILE;
					break;
				case FOOD:
					std::cout << FOOD_TILE;
					break;
				case ENTRANCE:
					std::cout << ENTRANCE_TILE;
					break;
				case EXIT:
					std::cout << EXIT_TILE;
					break;
				}

			}
			std::cout << std::endl;
		}

		std::cout << INDENT << "How tall are you in centimeters?" << std::endl;


		std::cin >> height;
		std::cout << std::endl;
		if (std::cin.fail())
	{
			std::cout << INDENT << "You have failed the first challenge and are eaten by a grue" << std::endl;

	}

		else
		{
			std::cout << INDENT << "You entered: " << height << std::endl;
		}

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		std::cout << INDENT << "What is the first letter of your name? " << INDENT << std::endl;

		std::cin >> firstLetterOfName;

		if (std::cin.fail() || !isalpha(firstLetterOfName))
		{
			std::cout << INDENT << "You have failed the second challenge and are eaten by a grue" << std::endl;
		}

		else
		{
			std::cout << INDENT << "You entered: " << firstLetterOfName << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());

		if (firstLetterOfName != 0)
		{
			avatarHP = (float)height / (firstLetterOfName + 0.02f);
		}

		else
		{
			avatarHP = 0;
		}

		std::cout << std::endl << INDENT << "Using a complex deterministic algorithm, it has been calculated that you have " << avatarHP << " hit point(s)." << std::endl;


		std::cout << std::endl << INDENT << "Press 'Emter' to exit the program." << std::endl;
		std::cin.get();


	return;
}