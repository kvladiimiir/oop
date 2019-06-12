// Shape.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <fstream>
#include <iostream>
#include "CController.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Error number of arguments\n";
		return 1;
	}

	std::ifstream fileInput(argv[1]);

	if (!fileInput.is_open())
	{
		std::cout << "There is no such file\n";
		return 1;
	}

	CController menuShapes(fileInput, std::cout);
	menuShapes.Commands();

	menuShapes.PrintShapesInfo();

	return 0;
}