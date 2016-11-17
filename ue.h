#ifndef UE_H
#define UE_H

#include <string>
#include <vector>

struct date{
    std::string day;
    int hourStart, hourEnd;
};

class UE
{
    public:
        UE();
        virtual ~UE();

        std::string getName();
        void setName(std::string newName);
        std::vector<date> getTimeTable();
        void setTimeTable(std::vector<date> newTimeTable);

    protected:
        std::string name;
        std::vector<date> timeTable;
};

date strtodate(std::string stringBrut);

#endif // UE_H
