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
    std::string cut;
    bool arobase = false;
    bool hyphen = false;

    newDate.day = newDate.hourEnd = newDate.hourStart = "";

    for(int i = 0; i < stringBrut.length(); i++){

        if(arobase){    // Si l'arobase est pass�
            if(stringBrut[i] == '-'){
                hyphen = true;
                continue;    // On passe
            }

            if(hyphen){ // Si le tiret est pass�
                newDate.hourEnd += stringBrut[i];
            }else{  // Si l'arobase est pass� mais pas le tiret
                newDate.hourStart += stringBrut[i];
            }
        }else{  // Si ni l'arobase ni le tiret ne sont pass�s
            if (stringBrut[i] == '@'){
                arobase = true;
                continue;    // On passe
            }
            newDate.day += stringBrut[i];
        }

    }

    return(newDate);

};

