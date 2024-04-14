//
// Created by Aurimas on 4/12/2024.
//

#include "sportsman.h"

sportsman::sportsman() {
    name = "";
    surname = "";
    height = 0;
    weight = 0;
}

const std::string &sportsman::getName() const {
    return name;
}

void sportsman::setName(const std::string &newName) {
    this->name = newName;
}

const std::string &sportsman::getSurname() const {
    return surname;
}

void sportsman::setSurname(const std::string &newSurname) {
    this->surname = newSurname;
}

int sportsman::getHeight() const {
    return height;
}

void sportsman::setHeight(int newHeight) {
    this->height = newHeight;
}

int sportsman::getWeight() const {
    return weight;
}

void sportsman::setWeight(int newWeight) {
    this->weight = newWeight;
}

sportsman::sportsman(std::string name, std::string surname, int height, int weight) {
    this->name = std::move(name);
    this->surname = std::move(surname);
    this->height = height;
    this->weight = weight;
}

void sportsman::printInfo() const {
    printf(
            "#### Sportininkas: ####\n Vardas: %s \n Pavarde: %s\n Ugis: %s\n Svoris: %s\n",
            this->name.c_str(),
            this->surname.c_str(),
            std::to_string(this->height).c_str(),
            std::to_string(this->weight).c_str()
    );
}
