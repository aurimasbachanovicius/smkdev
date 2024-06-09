#include <iostream>
#include "StudentuGrupesValdymas.h"
#include "failuTvarkytuvas.h"

bool programa(StudentuGrupesValdymas &grupe, FailuTvarkytuvas<Studentas> &failuTvarkytuvas, int pasirinkimas) {
    switch (pasirinkimas) {
        case 1: {
            std::string failoPavadinimas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failoPavadinimas;
            failuTvarkytuvas.uzkrautiIsFailo(failoPavadinimas);
            break;
        }
        case 2: {
            std::string failoPavadinimas;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failoPavadinimas;
            failuTvarkytuvas.issaugotiIFaila(failoPavadinimas);
            break;
        }
        case 3: {
            grupe.rikiuotiPagalVidurki();
            std::cout << grupe;
            break;
        }
        case 4:
            return false;
        default:
            std::cout << "Neteisingas pasirinkimas." << std::endl;
            return true;
    }

    return true;
}

int main() {
    StudentuGrupesValdymas grupe;
    FailuTvarkytuvas<Studentas> failuTvarkytuvas(grupe);

    std::cout << "Pasirinkite veiksma:" << std::endl;
    std::cout << "1. Uzkrauti studentu grupe is failo." << std::endl;
    std::cout << "2. Issaugoti studentu grupe i faila." << std::endl;
    std::cout << "3. Rikiuoti pagal vidurki ir atvaizduoti." << std::endl;
    std::cout << "4. Iseiti is programos." << std::endl;

    while (true) {
        int pasirinkimas;
        std::cin >> pasirinkimas;
        bool rezultatas = programa(grupe, failuTvarkytuvas, pasirinkimas);
        if (!rezultatas) {
            break;
        }

        std::cout << "Pasirinkite sekanti veiksma: ";
    }

    return 0;
}