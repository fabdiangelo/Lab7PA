#include <iostream>

using namespace std;

class direccion
{
private:
    string ciudad, calle, numero;
public:
    direccion(string ciudad, string calle, string numero);
    ~direccion();
    string getCiudad();
    string getCalle();
    string getNumero();
};
