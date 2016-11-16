#include <iostream>
#include <fstream>
#include <vector>

#include "Eleve.h"
#include "UE.h"

// Variables
std::vector<Eleve> promo; //Tous les �l�ves
std::vector<UE> course; //Tous les �l�ves

/*  +---------------------------+
    |                           |
    |   Remplissage Promotion   |
    |                           |
    +---------------------------+   */

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
            if(lectureUE){ //On est dans les UE (risque si ch != [a-z] mais UE == false)
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


/*  +------------------+
    |                  |
    |   EdT Matieres   |
    |                  |
    +------------------+   */

void fillCourse(){
    // Variables
    UE ue; // Un UE
    std::string ueName, dateName;
    std::vector<date> listCourse;
    char ch;
    bool lectureDate = false;

    //Lecture fichier schedule.txt
    std::fstream fin("data/schedule.txt", std::fstream::in);
    while (fin >> std::noskipws >> ch) {

        // Lisons nous des UE ou non?
        switch (ch){
            case '[':
                lectureDate = true;
                break;

            case ']':
                lectureDate = false;
                // Met le nom
                ue.setName(ueName);
                ue.setTimeTable(listCourse);

                //Rajoute la mati�re au programme
                course.push_back(ue);

                //Nettoyage des variables
                ueName = dateName = "";
                listCourse.clear();
                break;

            default:
                // None
                break;
        }

        // Enregistrement donn�es pr�-cr�ation Eleve
        if(lectureDate == false && ch >= 'a'){ // Lecture d'un nom d'�l�ve (">=a" permet d'�viter les espaces, \n, etc..)
            ueName += ch;
        }else{
            if(lectureDate){ //On est dans les horaires (risque si ch != [a-z] mais Date == false)
                if(ch >= '-' && ch <= 'Z'){ //Garde les chiffres - lettres majuscules - tiret et arobase
                    dateName += ch;
                }else{
                    if(dateName != ""){
                        listCourse.push_back( strtodate(dateName) );    //Met le nom dans le vecteur
                        dateName = "";                 //Clear variable
                    }
                }
            }
        }
    }
}

void displayCourse(){
    std::vector<date> listCourses;

    for (int j = 0; j < course.size(); j++){
        // Affiche nom
        std::cout << course[j].getName() << std::endl;
        // Affiche horaires
        listCourses = course[j].getTimeTable(); // Var = �co de var
        for (std::vector<date>::const_iterator i = listCourses.begin(); i != listCourses.end(); ++i)
            std::cout << "[Jour : " << i->day << " / dbt: " << i->hourStart << " / fin: " << i->hourEnd << ']' << std::endl; // Affiche d�tails
        std::cout << std::endl; // Retour � la ligne apr�s la liste
    }
}


/*  +-------------------+
    |                   |
    |   main function   |
    |                   |
    +-------------------+   */

int main(){

    //  Remplir la promo
    fillPromo();
    displayPromo();

    fillCourse();
    displayCourse();

	return 0; // Bisouxx
}

