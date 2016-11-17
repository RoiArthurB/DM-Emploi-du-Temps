#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <vector>

#include "ue.h"

class Eleve
{
    public:
        Eleve();
        virtual ~Eleve();

        std::string getName();
        void setName(std::string nom);
        std::vector<UE*> getUE();
        void setUE(std::vector<UE *> newUE);

    protected:
        std::string name;
        std::vector<UE*> ue;
};

#endif // ELEVE_H
