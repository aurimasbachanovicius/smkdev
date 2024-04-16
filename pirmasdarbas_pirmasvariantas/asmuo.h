#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
#ifndef PIRMASDARBAS_PIRMASVARIANTAS_ASMUO_H
#define PIRMASDARBAS_PIRMASVARIANTAS_ASMUO_H


#include <string>

// vardas, pavardė, miestas, telefono numeris
class asmuo {
private:
    std::string vardas;
    std::string pavarde;
    std::string miestas;
    std::string telefonoNumeris;
protected:
public:
    const std::string &getVardas() const { return vardas; }

    void setVardas(const std::string &nvardas) {
        asmuo::vardas = nvardas;
    }

    const std::string &getPavarde() const {
        return pavarde;
    }

    void setPavarde(const std::string &npavarde) {
        asmuo::pavarde = npavarde;
    }

    const std::string &getMiestas() const {
        return miestas;
    }

    void setMiestas(const std::string &nmiestas) {
        asmuo::miestas = nmiestas;
    }

    const std::string &getTelefonoNumeris() const {
        return telefonoNumeris;
    }

    void setTelefonoNumeris(const std::string &ntelefonoNumeris) {
        asmuo::telefonoNumeris = ntelefonoNumeris;
    }

public:
    asmuo() = default;

    asmuo(std::string vardas, std::string pavarde, std::string miestas, std::string telefonoNumeris) {
        setVardas(vardas);
        setPavarde(pavarde);
        setMiestas(miestas);
        setTelefonoNumeris(telefonoNumeris);
    }

    void atvaizduoti() {
        printf(
                "%s %s, %s, Tel. nr.: %s\n",
                vardas.c_str(),
                pavarde.c_str(),
                miestas.c_str(),
                telefonoNumeris.c_str()
        );
    }
};


#endif //PIRMASDARBAS_PIRMASVARIANTAS_ASMUO_H

#pragma clang diagnostic pop