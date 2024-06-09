#ifndef ANTRASDARBAS_ANTRASVARIANTAS_STUDENTUGRUPESVALDYMAS_H
#define ANTRASDARBAS_ANTRASVARIANTAS_STUDENTUGRUPESVALDYMAS_H

#include "Sarasas.h"
#include "Studentas.h"
#include <fstream>
#include <algorithm>

class StudentuGrupesValdymas : public Sarasas<Studentas> {
public:
    StudentuGrupesValdymas() = default;

    void rikiuotiPagalVidurki() {
        std::sort(this->sarasas.begin(), this->sarasas.end(), [](const Studentas &a, const Studentas &b) {
            return a.getVidurkis() > b.getVidurkis();
        });
    }
};

#endif //ANTRASDARBAS_ANTRASVARIANTAS_STUDENTUGRUPESVALDYMAS_H
