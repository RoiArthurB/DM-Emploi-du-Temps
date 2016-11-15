#ifndef ELEVE_H
#define ELEVE_H

#include <string>

class Eleve
{
    public:
        Eleve();
        Eleve(std::string nom);
        virtual ~Eleve();

        std::string getName();
        void setName(std::string nom);

    protected:
        std::string name;
        std::string **ue;
};

#endif // ELEVE_H
