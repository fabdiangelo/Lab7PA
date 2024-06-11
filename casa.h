#ifndef CASA_H
#define CASA_H

#include <iostream>
#include "propiedad.h"

class casa : public propiedad{
	private:
    	int M2Verdes;
		int M2Totales;
	public:
		casa(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir, int m2Edificados, int precioAlquiler, int precioVenta, int mv2);
		int getM2Verdes();
    	int getM2Totales();
    	void setM2Verdes(int);
		void setM2Totales(int);
		~casa();
};

#endif
