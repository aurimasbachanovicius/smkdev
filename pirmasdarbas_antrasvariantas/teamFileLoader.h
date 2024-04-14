//
// Created by Aurimas on 4/12/2024.
//

#ifndef PIRMASDARBAS_TEAMFILELOADER_H
#define PIRMASDARBAS_TEAMFILELOADER_H


#include <string>
#include "team.h"

class teamFileLoader {
private:
    std::string fileName;
public:
    explicit teamFileLoader(std::string fileName);

    team loadTeamFromFile();
};


#endif //PIRMASDARBAS_TEAMFILELOADER_H
