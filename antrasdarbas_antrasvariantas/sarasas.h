#ifndef ANTRASDARBAS_ANTRASVARIANTAS_SARASAS_H

#define ANTRASDARBAS_ANTRASVARIANTAS_SARASAS_H

#include <vector>
#include <stdexcept>

template<typename T>
class Sarasas {
protected:
    std::vector<T> sarasas;

public:
    Sarasas() = default;

    void prideti(const T &elementas) {
        sarasas.push_back(elementas);
    }

    void salinti(const T &elementas) {
        sarasas.erase(std::remove(sarasas.begin(), sarasas.end(), elementas), sarasas.end());
    }

    friend std::ostream &operator<<(std::ostream &os, const Sarasas<T> &sar) {
        for (const auto &elementas: sar.sarasas) {
            os << elementas << std::endl;
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Sarasas<T> &sar) {
        T elementas;
        while (is >> elementas) {
            sar.prideti(elementas);
        }
        return is;
    }

    typename std::vector<T>::const_iterator begin() const {
        return sarasas.cbegin();
    }

    typename std::vector<T>::const_iterator end() const {
        return sarasas.cend();
    }
};


#endif //ANTRASDARBAS_ANTRASVARIANTAS_SARASAS_H
