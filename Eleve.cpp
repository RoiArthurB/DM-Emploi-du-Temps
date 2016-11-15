#include <string>
#include "Eleve.h"

Eleve::Eleve(){
    // Bisous
}

Eleve::Eleve(std::string nom){
    this->name = nom;
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

std::vector<std::string> Eleve::getUE(){
    return this->ue;
};

void Eleve::setUE(std::vector<std::string> newUE){
    this->ue = newUE;
};
