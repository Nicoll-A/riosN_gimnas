#include <iostream>
#include <string>
using namespace std;

class Tarifa {
private:
    string nomTarifa;
    double preuMensual;

public:
    Tarifa(string nom, double preu) {
        nomTarifa = nom;
        preuMensual = preu;
    }

    string getNomTarifa() const {
        return nomTarifa;
    }

    double getPreuMensual() const {
        return preuMensual;
    }

};

// COMPOSICIÓ: Soci TÉ UNA Tarifa
class Soci {
protected: //Accessible per a la classe filla
    string nom;
    int idSoci;
    Tarifa tarifa; //Atribut objecte

public:
    // Llista d'inicialització
    Soci(string nom1, int id1, Tarifa tar)
        : nom(nom1), idSoci(id1), tarifa(tar) {
    }

    double calcularQuota() const {
        return tarifa.getPreuMensual();
    }

    void mostrarDades() {
        cout << "Nom: " << nom << endl;
        cout << "ID: " << idSoci << endl;
        cout << "Tipus de tarifa: " << tarifa.getNomTarifa() << endl;
        cout << "Quota: " << calcularQuota() << endl;
    }
};

// HERÈNCIA: SociVIP ÉS UN Soci
class SociVIP : public Soci {
private:
    double descompteEntrenador;

public:
    SociVIP(string nom1, int id1, Tarifa tar, double descompte)
        : Soci(nom1, id1, tar), descompteEntrenador(descompte) {
    }

    double calcularQuota() const {
        double preuSenseDescompte = tarifa.getPreuMensual();
        double preuDescompte = preuSenseDescompte - descompteEntrenador;
        return preuDescompte;
    }

    void mostrarDades() const {
        cout << "Nom: " << nom << endl;
        cout << "ID: " << idSoci << endl;
        cout << "Tipus de tarifa: " << tarifa.getNomTarifa() << endl;
        cout << "Quota sense descompte: " << tarifa.getPreuMensual() << endl;
        cout << "Descompte: " << descompteEntrenador << " euros" << endl;
        cout << "Quota amb descompte: " << calcularQuota() << endl;
    }
};

int main()
{
    cout << "--- Gimnas 'FitLife' ---" << endl;
    Tarifa tarifa1("Estandard", 40.0);
    Tarifa tarifa2("Premium", 60.0);

    Soci s1("Nicoll", 111, tarifa1);
    SociVIP s2("Alejandra", 222, tarifa2, 15.0);

    s1.mostrarDades();
    s2.mostrarDades();

    return 0;
}