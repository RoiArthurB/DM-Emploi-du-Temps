#include <string>

#include "eleve.h"
#include "ue.h"

Eleve::Eleve(){
    //ctor
}

Eleve::~Eleve()
{
    //dtor
}

std::string Eleve::getName(){
    return this->name;
};

void Eleve::setName(std::string nom){
    this->name = nom;
};

std::vector<UE*> Eleve::getUE(){
    return this->ue;
};

void Eleve::setUE(std::vector<UE*> newUE){

    this->ue = newUE;
};
