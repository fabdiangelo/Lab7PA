#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "propiedad.h"
#include "edificio.h"

using namespace std;

class edificio;
class direccion;
class zona;

class apartamento : public propiedad{
	private:
		int M2Totales;
		edificio* ed;
	public:
		apartamento(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion, int m2Edificados, zona *z, edificio* ed, string nombreInmo);
		~apartamento();
		int getM2Totales();
		void setM2Totales(int);
		void CortarLazos();
};

#endif
