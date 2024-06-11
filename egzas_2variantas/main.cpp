#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Preke {
private:
    std::string pavadinimas;
    double kaina;
public:
    Preke(std::string pavadinimas, double kaina) : pavadinimas(std::move(pavadinimas)), kaina(kaina) {}

    [[nodiscard]] std::string getPavadinimas() const {
        return pavadinimas;
    }

    [[nodiscard]] double getKaina() const {
        return kaina;
    }
};

class Sandelys {
private:
    std::vector<Preke> prekes;
    int sandelioDydis;
public:
    Sandelys(int sandelioDydis) : sandelioDydis(sandelioDydis) {}

    void pridetiPreke(std::string pavadinimas, double kaina) {
        if (prekes.size() < sandelioDydis) {
            prekes.emplace_back(pavadinimas, kaina);
        } else {
            std::cout << "Sandelyje nebera vietos.\n";
        }
    }

    Sandelys &operator<<(const Preke &preke) {
        pridetiPreke(preke.getPavadinimas(), preke.getKaina());
        return *this;
    }

    [[nodiscard]] std::string gautiPreke(double kaina) const {
        for (const auto &preke: prekes) {
            if (preke.getKaina() == kaina) {
                return preke.getPavadinimas();
            }
        }
        return "Preke nerasta";
    }

    [[nodiscard]] double gautiPreke(const std::string &pavadinimas) const {
        for (const auto &preke: prekes) {
            if (preke.getPavadinimas() == pavadinimas) {
                return preke.getKaina();
            }
        }
        return -1;
    }

    void pirktiPreke(const std::string &pavadinimas) {
        for (auto it = prekes.begin(); it != prekes.end(); ++it) {
            if (it->getPavadinimas() == pavadinimas) {
                prekes.erase(it);
                std::cout << "Preke " << pavadinimas << " buvo nupirkta.\n";
                return;
            }
        }
        std::cout << "Preke nerasta.\n";
    }
};

bool programa(Sandelys &sandelys, int pasirinkimas) {
    switch (pasirinkimas) {
        case 1: {
            std::string prekesPavadinimas;
            std::cout << "Prekes pavadinimas: ";
            std::cin >> prekesPavadinimas;

            double prekesKaina;
            std::cout << prekesPavadinimas << " kaina: ";
            std::cin >> prekesKaina;

            Preke naujaPreke(prekesPavadinimas, prekesKaina);
            sandelys << naujaPreke;

            std::cout << "Preke pridejote" << std::endl;
            break;
        }
        case 2: {
            std::string prekesPavadinimas;
            std::cout << "Iveskite prekes pavadinima: ";
            std::cin >> prekesPavadinimas;

            double kaina = sandelys.gautiPreke(prekesPavadinimas);
            if (kaina != -1) {
                std::cout << "Prekes kaina: " << kaina << "\n";
            } else {
                std::cout << "Preke nerasta.\n";
            }
            break;
        }
        case 3: {
            double prekesKaina;
            std::cout << "Iveskite prekes kaina: ";
            std::cin >> prekesKaina;

            std::string pavadinimas = sandelys.gautiPreke(prekesKaina);
            if (pavadinimas != "Preke nerasta") {
                std::cout << "Prekes pavadinimas: " << pavadinimas << "\n";
            } else {
                std::cout << "Preke nerasta.\n";
            }
            break;
        }
        case 4: {
            std::string prekesPavadinimas;
            std::cout << "Iveskite prekes pavadinima kuri norite nupirkti: ";
            std::cin >> prekesPavadinimas;
            sandelys.pirktiPreke(prekesPavadinimas);
            break;
        }
        case 5:
            return true;
        default:
            std::cout << "Neteisingas pasirinkimas.\n";
            break;
    }

    return false;
}

int main() {
    int sandelioDydis;
    std::cout << "kas yra jusu sandelio dydis? " << std::endl;
    std::cin >> sandelioDydis;

    Sandelys sandelys(sandelioDydis);

    while (true) {
        std::cout << "Pasirinkite veiksma:" << std::endl;
        std::cout << "1. Prideti preke." << std::endl;
        std::cout << "2. Gauti prekes kaina pagal pavadinima." << std::endl;
        std::cout << "3. Gauti prekes pavadinima pagal kaina." << std::endl;
        std::cout << "4. Pirkti preke." << std::endl << std::endl;
        std::cout << "5. Iseiti is programos." << std::endl;
        std::cout << "Pasirinkimas: ";

        int pasirinkimas;
        std::cin >> pasirinkimas;

        try {
            bool baigti = programa(sandelys, pasirinkimas);
            if (baigti) {
                break;
            }
        } catch (const std::runtime_error &e) {
            std::cerr << "Klaida: " << e.what() << std::endl;
            return 1;
        }
    }

    return 0;
}
