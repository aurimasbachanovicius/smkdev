#ifndef ANTRASDARBAS_ANTRASVARIANTAS_STUDENTAS_H
#define ANTRASDARBAS_ANTRASVARIANTAS_STUDENTAS_H

#include <string>
#include <iostream>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::string grupe;
    float vidurkis;

public:
    Studentas() = default;

    Studentas(const std::string &vardas, const std::string &pavarde, const std::string &grupe, float vidurkis)
            : vardas(vardas), pavarde(pavarde), grupe(grupe), vidurkis(vidurkis) {}

    const std::string &getVardas() const { return vardas; }

    void setVardas(const std::string &vardas) { this->vardas = vardas; }

    const std::string &getPavarde() const { return pavarde; }

    void setPavarde(const std::string &pavarde) { this->pavarde = pavarde; }

    const std::string &getGrupe() const { return grupe; }

    void setGrupe(const std::string &grupe) { this->grupe = grupe; }

    float getVidurkis() const { return vidurkis; }

    void setVidurkis(float vidurkis) { this->vidurkis = vidurkis; }

    friend std::ostream &operator<<(std::ostream &os, const Studentas &studentas) {
        os << studentas.vardas << " " << studentas.pavarde << ", grupe: "
           << studentas.grupe << ", vidurkis: " << studentas.vidurkis;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Studentas &studentas) {
        is >> studentas.vardas >> studentas.pavarde >> studentas.grupe >> studentas.vidurkis;
        return is;
    }
};

#endif //ANTRASDARBAS_ANTRASVARIANTAS_STUDENTAS_H
