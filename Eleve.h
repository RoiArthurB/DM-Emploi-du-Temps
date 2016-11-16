#ifndef ELEVE_H
#define ELEVE_H

#include <string>
#include <vector>

class Eleve
{
    public:
        Eleve();
        virtual ~Eleve();

        std::string getName();
        void setName(std::string nom);
        std::vector<std::string> getUE();
        void setUE(std::vector<std::string> newUE);

    protected:
        std::string name;
        std::vector<std::string> ue;
};

#endif // ELEVE_H
