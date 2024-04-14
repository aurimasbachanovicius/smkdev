//
// Created by Aurimas on 4/12/2024.
//

#include "teamFileLoader.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

teamFileLoader::teamFileLoader(std::string fileName) {
    this->fileName = std::move(fileName);
}

team teamFileLoader::loadTeamFromFile() {
    std::ifstream file(this->fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + this->fileName);
    }

    std::vector<sportsman> sportsmans;
    int teamSize = 0;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, surname;
        int height, weight;

        if (!(iss >> name >> surname >> height >> weight)) {
            throw std::runtime_error("Error reading line from file " + this->fileName);
        }

        sportsman sportsman(name, surname, height, weight);
        teamSize++;
        sportsmans.push_back(sportsman);
    }
    file.close();

    team team(teamSize);
    for (const auto &sportsman: sportsmans) {
        team.addSportsman(sportsman);
    }

    return team;
}
