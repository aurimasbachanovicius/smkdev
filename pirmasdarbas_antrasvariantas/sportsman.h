//
// Created by Aurimas on 4/12/2024.
//

#ifndef PIRMASDARBAS_SPORTSMAN_H
#define PIRMASDARBAS_SPORTSMAN_H

#include <string>

class sportsman {
private:
    std::string name;
    std::string surname;
    int height;
    int weight;

public:
    sportsman(std::string name, std::string surname, int height, int weight);

    sportsman();

    [[nodiscard]]
    const std::string &getName() const;

    void setName(const std::string &name);

    [[nodiscard]]
    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    [[nodiscard]]
    int getHeight() const;

    void setHeight(int height);

    [[nodiscard]]
    int getWeight() const;

    void setWeight(int weight);

    void printInfo() const;
};

#endif //PIRMASDARBAS_SPORTSMAN_H
