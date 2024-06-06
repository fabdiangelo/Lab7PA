#include <iostream>

using namespace std;

class fecha
{
private:
    string dia, mes, anio;
public:
    fecha(string dia, string mes, string anio);
    ~fecha();
    string getDia();
    string getMes();
    string getAnio();
};