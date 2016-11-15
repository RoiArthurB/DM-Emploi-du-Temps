#include <iostream>
#include <fstream>
#include <vector>

#include "Eleve.h"

int main()
{
    // Variables
    std::string eleveName, nomUE;
    std::vector<std::string> listUE;
    Eleve student1;
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
                //Création du nouvel élève
                    // new Eleve unique
                // Met le nom
                student1.setName(eleveName);
                // Met la liste des UE
                student1.setUE(listUE);

                //Nettoyage variables
                nomUE = eleveName = ""; listUE.clear();
                std::cout << "Clear !" << std::endl;

               // student1.setUE()
                break;

            default:
                // None
                break;
        }

        // Enregistrement données pré-création Eleve
        if(lectureUE == false && ch >= 'a'){ // Lecture d'un nom d'élève (">=a" permet d'éviter les espaces, \n, etc..)
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

    // Affiche nom
	std::cout << student1.getName() << std::endl;
	// Affiche UE
	listUE = student1.getUE(); // Var = éco de var
    for (std::vector<std::string>::const_iterator i = listUE.begin(); i != listUE.end(); ++i)
        std::cout << *i << ' ';
	std::cout << std::endl; // Retour à la ligne après la liste

	return 0; // Bisouxx
}

