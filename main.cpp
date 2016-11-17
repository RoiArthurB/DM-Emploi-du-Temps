#include <iostream>
#include <fstream>
#include <vector>

#include "Eleve.h"
#include "UE.h"

// Variables
std::vector<Eleve> promo; //Tous les élèves
std::vector<UE> course; //Tous les élèves

/*  +---------------------------+
    |                           |
    |   Remplissage Promotion   |
    |                           |
    +---------------------------+   */

void fillPromo(){
    // Variables
    Eleve student; // Un élève
    std::string eleveName, nomUE;
    std::vector<UE*> listUE;
    char ch;
    bool lectureUE = false;
    UE* adressUE;

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


                //Rajoute l'élève à la promotion
                promo.push_back(student);

                //Nettoyage des variables
                nomUE = eleveName = ""; listUE.clear();
                break;

            default:
                // None
                break;
        }

        // Enregistrement données pré-création Eleve
        if(lectureUE == false && ch >= 'a'){ // Lecture d'un nom d'élève (">=a" permet d'éviter les espaces, \n, etc..)
            eleveName += ch;
        }else{
            if(lectureUE){ // On est dans les UE (risque si ch != [a-z] mais UE == false)
                if(ch >= 'a'){ // Garde les lettres
                    nomUE += ch;
                }else{
                    if(nomUE != ""){
                        int i;
                        for(i = 0; i < sizeof(course); i++){
                            if(nomUE == course[i].getName()){
                                adressUE = &course[i];
                                break;
                            }
                        }
                        if( i == sizeof(course) ){
                            exit(1);
                        }
                        bool next=false;
                        for(UE *ue:listUE){
                            if(ue->getName()==adressUE->getName()){
                                next=true;
                            }
                        }
                        if(!next)
                            listUE.push_back(adressUE);    //Met le nom dans le vecteur
                        nomUE = "";                 //Clear variable
                    }
                }
            }
        }
    }
}

void displayPromo(){
    std::vector<UE*> listUE;

    for (int j = 0; j < promo.size(); j++){
        // Affiche nom
        std::cout << promo[j].getName() << std::endl;
        // Affiche UE
        listUE = promo[j].getUE(); // Var = éco de var

        for(int i = 0; i < listUE.size(); i++){
            std::cout << listUE[i]->getName() << ' ';
        }
        std::cout << std::endl << std::endl; // Retour à la ligne après la liste
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

                //Rajoute la matière au programme
                course.push_back(ue);

                //Nettoyage des variables
                ueName = dateName = "";
                listCourse.clear();
                break;

            default:
                // None
                break;
        }

        // Enregistrement données pré-création Eleve
        if(lectureDate == false && ch >= 'a'){ // Lecture d'un nom d'élève (">=a" permet d'éviter les espaces, \n, etc..)
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
        listCourses = course[j].getTimeTable(); // Var = éco de var
        for (std::vector<date>::const_iterator i = listCourses.begin(); i != listCourses.end(); ++i)
            std::cout << "[Jour : " << i->day << " / dbt: " << i->hourStart << " / fin: " << i->hourEnd << ']' << std::endl; // Affiche détails
        std::cout << std::endl; // Retour à la ligne après la liste
    }
}

void verificationConflicts(){
    for(Eleve e: promo){    // Parcours la promotion
        bool conflict = false;
        std::cout<<"Problems for "<<e.getName()<<':'<<std::endl;
        for(int i=0; i < e.getUE().size(); i++){    // Parcours tous les UEs de l'élève
            for(int j=i+1; j < e.getUE().size(); j++){  // Parcours tous les UEs après le courant
                for(date d: e.getUE()[i]->getTimeTable()){  //  Parcours chaque horaire de l'UE courant
                    for(date dComp: e.getUE()[j]->getTimeTable()){  //  Parcours chaque horaire de l'UE de comparaison
                        if(((d.hourStart <= dComp.hourStart && d.hourEnd >= dComp.hourStart ) || (d.hourStart <= dComp.hourEnd && d.hourEnd >= dComp.hourEnd)) && (d.day == dComp.day)){
                            conflict = true;
                            std::cout<<"-> "<<e.getUE()[i]->getName()<<" day: "<<d.day<<" start: "<<d.hourStart<<" end: "<<d.hourEnd<<std::endl;
                            std::cout<<"conflicts with"<<std::endl;
                            std::cout<<"-> "<<e.getUE()[j]->getName()<<" day: "<<dComp.day<<" start: "<<dComp.hourStart<<" end: "<<dComp.hourEnd<<std::endl;
                        }
                    }
                }
            }
        }
        // Affiche "ok" s'il n'y a pas d'erreurs
        if(!conflict){
            std::cout<<"OK"<<std::endl;
        }
        std::cout<<std::endl;
    }
}

/*  +-------------------+
    |                   |
    |   main function   |
    |                   |
    +-------------------+   */

int main(){

    //  Remplir le programme
    fillCourse();
//    displayCourse();    //  Affiche tous les cours avec leurs horaires

    //  Remplir la promo
    fillPromo();
//    displayPromo();    //  Affiche tous les élèves avec leurs UEs

    verificationConflicts();
    return 0; // Fin
}

