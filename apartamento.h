#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "edificio.h"
#include "propiedad.h"

class edificio;
class propiedad;

class apartamento : public propiedad{
	private:
		int M2Totales;
		edificio* ed;
	public:
		apartamento(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion, int m2Edificados, zona *z, edificio* ed, inmobiliaria* inmo);
		~apartamento();
		int getM2Totales();
		void setM2Totales(int);
		void CortarLazos();
};

#endif
