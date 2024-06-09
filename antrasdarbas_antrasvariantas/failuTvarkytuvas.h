
#ifndef ANTRASDARBAS_ANTRASVARIANTAS_FAILUTVARKYTUVAS_H
#define ANTRASDARBAS_ANTRASVARIANTAS_FAILUTVARKYTUVAS_H

#include <string>
#include <fstream>
#include "sarasas.h"

template<typename T>
class FailuTvarkytuvas {
private:
    Sarasas<T> &sarasas;
public:
    explicit FailuTvarkytuvas(Sarasas<T> &sarasas) : sarasas(sarasas) {}

    void uzkrautiIsFailo(const std::string &failoPavadinimas) {

        std::string failoPav = std::move(failoPavadinimas);

        std::ifstream failas(failoPavadinimas);
        if (!failas.is_open()) {
            throw std::runtime_error("Failas nerastas.");
        }

        T elementas;
        while (failas >> elementas) {
            sarasas.prideti(elementas);
        }
    }

    void issaugotiIFaila(const std::string &failoPavadinimas) const {
        std::string failoPav = std::move(failoPavadinimas);
        std::ofstream failas(failoPav);
        if (!failas.is_open()) {
            throw std::runtime_error("Nepavyko atidaryti failo.");
        }

        for (const auto &irasas: sarasas) {
            failas << irasas << std::endl;
        }
    }
};

#endif //ANTRASDARBAS_ANTRASVARIANTAS_FAILUTVARKYTUVAS_H
