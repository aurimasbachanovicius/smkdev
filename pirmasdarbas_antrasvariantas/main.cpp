#include <iostream>
#include "team.h"
#include "sportsman.h"
#include "teamFileLoader.h"

bool programLoop(team loadedTeam);

void println(const char *text) {
    printf("%s\n", text);
}

int main() {
    teamFileLoader teamFileLoader("dream_team.txt");
    team loadedTeam = teamFileLoader.loadTeamFromFile();

    println("Sveiki, pasirinkite ka norite daryti su komanda:");
    println("1. Vidutinio komandos ugio skaiciavimas.");
    println("2. Paieska nurodzius varda ir pavarde.");
    println("3. Paieska nurodzius varda, pavarde ir ugi.");
    println("4. Sportininku saraso rikiavimas pagal pavarde.");
    println("5. Sportininku saraso rikiavimas pagal ugi.");
    println("");
    println("6. Iseiti is programos.");

    programLoop(loadedTeam);

    try {
        while (true) {
            if (programLoop(loadedTeam)) {
                break;
            } else {
                println("Pasirinkite sekancia komanda: ");
            }
        }
    } catch (const std::runtime_error &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    println("programa baigia darba.");
    return 0;
}

bool programLoop(team loadedTeam) {
    int command;
    scanf("%d", &command); // NOLINT(*-err34-c)

    char name[100] = {0};
    char surname[100] = {0};
    int height = 0;
    sportsman *foundSportsman;

    switch (command) {
        case 1:
            println("Vidutinis ugis: ");
            printf("%.2f\n", loadedTeam.averageHeight());
            break;
        case 2:
            println("Iveskite varda ir pavarde: ");
            scanf("%s %s", name, surname); // NOLINT(*-err34-c)
            foundSportsman = loadedTeam.findSportsman(name, surname);
            if (foundSportsman != nullptr) {
                foundSportsman->printInfo();
            } else {
                println("Sportininkas nerastas.");
            }

            break;
        case 3:
            println("Iveskite varda, pavarde ir ugi: ");
            scanf("%s %s %d", name, surname, &height); // NOLINT(*-err34-c)
            foundSportsman = loadedTeam.findSportsman(name, surname, height);
            if (foundSportsman != nullptr) {
                foundSportsman->printInfo();
            } else {
                println("Sportininkas nerastas.");
            }
            break;
        case 4:
            println("Rikiuojama pagal pavarde: ");
            loadedTeam.sortSportsmenByName();
            loadedTeam.printAll();
            break;
        case 5:
            println("Rikiuojama pagal ugi: ");
            loadedTeam.sortSportsmenByHeight();
            loadedTeam.printAll();
            break;
        case 6:
            return true;
        default:
            println("Neteisingas pasirinkimas.");
            break;
    }

    return false;
}
