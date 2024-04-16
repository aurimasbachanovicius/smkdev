#ifndef PIRMASDARBAS_PIRMASVARIANTAS_ADRESUKNYGUTE_H
#define PIRMASDARBAS_PIRMASVARIANTAS_ADRESUKNYGUTE_H

#include <stdexcept>
#include <fstream>
#include <vector>
#include <algorithm>
#include "asmuo.h"

class adresuknygute {
    asmuo *asmenys;
    int asmenuKiekis;
public:
    adresuknygute(asmuo *asmenys, int asmenuKiekis) {
        adresuknygute::asmenuKiekis = asmenuKiekis;
        adresuknygute::asmenys = asmenys;
    };

    int gyvenanciuAsmenuKiekisMieste(const std::string &miestas) const {
        int count = 0;
        for (int i = 0; i < asmenuKiekis; i++) {
            if (asmenys[i].getMiestas() == miestas) {
                count++;
            }
        }
        return count;
    }

    asmuo *paieskaPagalVardaPavarde(const std::string &vardas, const std::string &pavarde) const {
        for (int i = 0; i < asmenuKiekis; i++) {
            if (asmenys[i].getVardas() == vardas && asmenys[i].getPavarde() == pavarde) {
                return &asmenys[i];
            }
        }
        return nullptr;
    }

    asmuo *paieskaPagalVardaPavardeMiesta(const std::string &vardas, const std::string &pavarde,
                                          const std::string &miestas) const {
        for (int i = 0; i < asmenuKiekis; i++) {
            if (asmenys[i].getVardas() == vardas && asmenys[i].getPavarde() == pavarde &&
                asmenys[i].getMiestas() == miestas) {
                return &asmenys[i];
            }
        }
        return nullptr;
    }

    void rikiuotiPagalPavardeMiesta() {
        std::sort(asmenys, asmenys + asmenuKiekis, [](const asmuo &a, const asmuo &b) {
            if (a.getPavarde() == b.getPavarde()) {
                return a.getMiestas() < b.getMiestas();
            }
            return a.getPavarde() < b.getPavarde();
        });
    }

    void atvaizduotiVisus() {
        printf("\n");
        for (int i = 0; i < asmenuKiekis; i++) {
            asmenys[i].atvaizduoti();
        }
    }

    static adresuknygute uzkrautiIsFailo(const char *failoPavadinimas) {
        std::ifstream failas(failoPavadinimas);
        if (!failas.is_open()) {
            throw std::runtime_error("Failas nerastas.");
        }

        std::vector<asmuo> asmenysVec;
        std::string vardas, pavarde, miestas, telefonoNumeris;

        while (failas >> vardas >> pavarde >> miestas >> telefonoNumeris) {
            asmenysVec.emplace_back(vardas, pavarde, miestas, telefonoNumeris);
        }

        asmuo *asmenys = new asmuo[asmenysVec.size()];
        std::copy(asmenysVec.begin(), asmenysVec.end(), asmenys);

        return {
                asmenys,
                static_cast<int>(asmenysVec.size())
        };
    };
};

#endif