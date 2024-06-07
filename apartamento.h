#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
#include "propiedad.h"

class apartamento : public propiedad{
	private:
		int M2Totales;
	public:
		apartamento(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* direccion, int m2Edificados, int precioAlquiler, int precioVenta, int M2T);
		int getM2Totales();
		void setM2Totales(int);
		~apartamento();
};

#endif
