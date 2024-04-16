#include <iostream>
#include "adresuknygute.h"

bool programa(adresuknygute adresuknygute, int pasirinkimas) {
    switch (pasirinkimas) {
        case 1: {
            std::string miestas;
            printf("Iveskite miesta: ");
            std::cin >> miestas;
            printf("Gyvenanciu asmenu kiekis mieste %s: %d\n", miestas.c_str(),
                   adresuknygute.gyvenanciuAsmenuKiekisMieste(miestas)
            );
            break;
        };
        case 2: {
            std::string vardas, pavarde;
            printf("Iveskite varda ir pavarde: ");
            std::cin >> vardas >> pavarde;
            asmuo *rastasAsmuo = adresuknygute.paieskaPagalVardaPavarde(vardas, pavarde);
            if (rastasAsmuo) {
                printf("Rastas asmuo:");
                rastasAsmuo->atvaizduoti();
            } else {
                printf("Asmuo nerastas.\n");
            }
            break;
        };
        case 3: {
            std::string vardas, pavarde, miestas;
            printf("Iveskite varda, pavarde ir miesta: ");
            std::cin >> vardas >> pavarde >> miestas;
            asmuo *rastasAsmuo = adresuknygute.paieskaPagalVardaPavardeMiesta(vardas, pavarde, miestas);
            if (rastasAsmuo) {
                printf("Rastas asmuo:");
                rastasAsmuo->atvaizduoti();
            } else {
                printf("Asmuo nerastas.\n");
            }
            break;
        };
        case 4: {
            adresuknygute.rikiuotiPagalPavardeMiesta();
            adresuknygute.atvaizduotiVisus();
            break;
        }
        case 5:
            return false;
        default:
            printf("Neteisingas pasirinkimas.\n");
            return true;
    }

    return true;
}

int main() {
    printf("Pasirinkite adresu knygutes veiksma:\n");
    printf("1. Nurodytame mieste gyvenanciu asmenu kiekio paieska.\n");
    printf("2. Paieska nurodzius varda ir pavarde.\n");
    printf("3. Paieska nurodzius varda, pavarde ir miesta.\n");
    printf("4. Rikiavimas pagal pavarde ir miesta.\n\n");
    printf("5. Iseiti is programos.");

    adresuknygute knygute = adresuknygute::uzkrautiIsFailo("adresu_knyga.txt");

    while (true) {
        int pasirinkimas;
        scanf("%d", &pasirinkimas);
        bool rezultatas = programa(knygute, pasirinkimas);
        if (!rezultatas) {
            break;
        }
        printf("Pasirinkite sekancia komanda: ");
    }

    return 0;
}