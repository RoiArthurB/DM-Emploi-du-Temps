#include <iostream>
#include "ue.h"

UE::UE()
{
    //ctor
}

UE::~UE()
{
    //dtor
}

std::string UE::getName(){
    return this->name;
};

void UE::setName(std::string newName){
    this->name = newName;
};

std::vector<date> UE::getTimeTable(){
    return this->timeTable;
};

void UE::setTimeTable(std::vector<date> newTimeTable){
    this->timeTable = newTimeTable;
};

// String To Date
date strtodate(std::string stringBrut){
    date newDate;
    std::string cut, hourEnd, hourStart;
    bool arobase = false;
    bool hyphen = false;

    newDate.day = "";

    for(int i = 0; i < stringBrut.length(); i++){

        if(arobase){    // Si l'arobase est passé
            if(stringBrut[i] == '-'){
                hyphen = true;
                continue;    // On passe
            }

            if(hyphen){ // Si le tiret est passé
                hourEnd += stringBrut[i];
            }else{  // Si l'arobase est passé mais pas le tiret
                hourStart += stringBrut[i];
            }
        }else{  // Si ni l'arobase ni le tiret ne sont passés
            if (stringBrut[i] == '@'){
                arobase = true;
                continue;    // On passe
            }
            newDate.day += stringBrut[i];
        }

    }

    if(std::stoi(hourStart) < std::stoi(hourEnd)){
        if( std::stoi(hourStart) <= 19 && std::stoi(hourStart) >= 8)
            newDate.hourStart = std::stoi(hourStart);
        else
            std::cout << "Error hours Start" << std::endl;

        if( std::stoi(hourEnd) <= 19 && std::stoi(hourEnd) >= 8)
            newDate.hourEnd = std::stoi(hourEnd);
        else
            std::cout << "Error hours End" << std::endl;
    }else{
        std::cout << "Error hours order" << std::endl;
    }

    return(newDate);

};

