#include "UE.h"

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

    newDate.hourEnd = std::stoi(hourEnd);
    newDate.hourStart = std::stoi(hourStart);
    return(newDate);

};

