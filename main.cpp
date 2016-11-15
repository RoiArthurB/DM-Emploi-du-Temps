#include <iostream>
#include <fstream>

#include "Eleve.h"

int main()
{
    std::string eleveName;
    Eleve student1;
    char ch;
    std::fstream fin("data/students.txt", std::fstream::in);
    while (fin >> std::noskipws >> ch) {
        std::cout << ch; // Or whatever
        if (ch != '['){
            eleveName += ch;
        }else{
            student1.setName(eleveName);
        }

        if(ch == '\n'){
            break;
        }
    }

	std::cout << "Hello World" << std::endl;
	std::cout << student1.getName();
	return 0;
}

