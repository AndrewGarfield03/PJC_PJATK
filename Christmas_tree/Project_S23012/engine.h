#pragma once
#include <iostream>
#include <io.h>  
#include <cstdlib>   
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>

namespace base
{
	void start();
	void increasePicture();
	void decreasePicture();
	void writeTo(char symbol);
	void fileOpen();
	void fileClose();
	std::string* createChristmassTree();
	void displayChristmassTree(std::string* tree);
	void clearConsole();

}

