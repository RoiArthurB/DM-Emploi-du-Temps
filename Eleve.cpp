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
