#include <iostream>
#include <fstream>
#include <vector>

#include "Eleve.h"

// Variables
std::vector<Eleve> promo; //Tous les �l�ves

void displayPromo(){
    std::vector<std::string> listUE;

    for (int j = 0; j < promo.size(); j++){
        // Affiche nom
        std::cout << promo[j].getName() << std::endl;
        // Affiche UE
        listUE = promo[j].getUE(); // Var = �co de var
        for (std::vector<std::string>::const_iterator i = listUE.begin(); i != listUE.end(); ++i)
            std::cout << *i << ' ';
        std::cout << std::endl << std::endl; // Retour � la ligne apr�s la liste
    }
}

void fillPromo(){
    // Variables
    Eleve student; // Un �l�ve
    std::string eleveName, nomUE;
    std::vector<std::string> listUE;
    char ch;
    bool lectureUE = false;

    //Lecture fichier students.txt
    std::fstream fin("data/students.txt", std::fstream::in);
    while (fin >> std::noskipws >> ch) {

        // Lisons nous des UE ou non?
        switch (ch){
            case '[':
                lectureUE = true;
                break;

            case ']':
                lectureUE = false;
                //Cr�ation du nouvel �l�ve
                    // new Eleve unique
                // Met le nom
                student.setName(eleveName);
                // Met la liste des UE
                student.setUE(listUE);

                //Rajoute l'�l�ve � la promotion
                promo.push_back(student);

                //Nettoyage des variables
                nomUE = eleveName = ""; listUE.clear();
                break;

            default:
                // None
                break;
        }

        // Enregistrement donn�es pr�-cr�ation Eleve
        if(lectureUE == false && ch >= 'a'){ // Lecture d'un nom d'�l�ve (">=a" permet d'�viter les espaces, \n, etc..)
            eleveName += ch;
        }else{
            if(lectureUE == true){ //On est dans les UE (risque si ch != [a-z] mais UE == false)
                if(ch >= 'a'){ //Garde les lettres
                    nomUE += ch;
                }else{
                    if(nomUE != ""){
                        listUE.push_back(nomUE);    //Met le nom dans le vecteur
                        nomUE = "";                 //Clear variable
                    }
                }
            }
        }
    }
}

int main(){

    //  Remplir la promo
    fillPromo();
    displayPromo();

	return 0; // Bisouxx
}

