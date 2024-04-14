//
// Created by Aurimas on 4/12/2024.
//

#ifndef PIRMASDARBAS_TEAM_H
#define PIRMASDARBAS_TEAM_H


#include "sportsman.h"

class team {
private:
    sportsman *sportsmen;
    int maxTeamSize;
    int currentSize = 0;
public:
    explicit team(int size);

    void addSportsman(sportsman);

    [[nodiscard]]
    double averageHeight() const;

    sportsman *findSportsman(const std::string &name, const std::string &surname);

    sportsman *findSportsman(const std::string &name, const std::string &surname, double height);

    void sortSportsmenByName();

    void sortSportsmenByHeight();

    void printAll() const;
};


#endif //PIRMASDARBAS_TEAM_H
