//
// Created by Aurimas on 4/12/2024.
//

#include "team.h"
#include <cmath>

void team::addSportsman(sportsman newSportsman) {
    if (this->currentSize < this->maxTeamSize) {
        this->sportsmen[this->currentSize] = std::move(newSportsman);
        this->currentSize++;
    }
}

team::team(int size) {
    maxTeamSize = size;
    sportsmen = new sportsman[size];
}

double team::averageHeight() const {
    if (currentSize == 0) return 0;

    double totalHeight = 0;
    for (int i = 0; i < currentSize; i++) {
        totalHeight += sportsmen[i].getHeight();
    }


    return totalHeight / currentSize;
}

sportsman *team::findSportsman(const std::string &name, const std::string &surname) {
    for (int i = 0; i < currentSize; i++) {
        if (sportsmen[i].getName() == name && sportsmen[i].getSurname() == surname) {
            return &sportsmen[i];
        }
    }

    return nullptr;
}

sportsman *team::findSportsman(const std::string &name, const std::string &surname, double height) {
    for (int i = 0; i < currentSize; i++) {
        if (sportsmen[i].getName() == name && sportsmen[i].getSurname() == surname &&
            sportsmen[i].getHeight() == height) {
            return &sportsmen[i];
        }
    }

    return nullptr;
}

void team::sortSportsmenByName() {
    for (int i = 0; i < currentSize - 1; i++) {
        for (int j = 0; j < currentSize - i - 1; j++) {
            if (sportsmen[j].getSurname()[0] > sportsmen[j + 1].getSurname()[0]) {
                // Swap sportsmen[j] and sportsmen[j + 1]
                sportsman temp = std::move(sportsmen[j]);
                sportsmen[j] = std::move(sportsmen[j + 1]);
                sportsmen[j + 1] = std::move(temp);
            }
        }
    }
}

void team::sortSportsmenByHeight() {
    for (int i = 0; i < currentSize - 1; i++) {
        for (int j = 0; j < currentSize - i - 1; j++) {
            if (sportsmen[j].getHeight() > sportsmen[j + 1].getHeight()) {
                // Swap sportsmen[j] and sportsmen[j + 1]
                sportsman temp = std::move(sportsmen[j]);
                sportsmen[j] = std::move(sportsmen[j + 1]);
                sportsmen[j + 1] = std::move(temp);
            }
        }
    }
}

void team::printAll() const {
    for (int i = 0; i < currentSize; i++) {
        sportsmen[i].printInfo();
    }
}
