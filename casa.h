#ifndef CASA_H
#define CASA_H

#include <iostream>
#include "propiedad.h"

class casa : public propiedad{
	private:
    		int M2Verdes;
		int M2Totales;
	public:
		casa(string, int, int, int, bool, direccion, int, int, int, chat**,int, int);
		int getM2Verdes();
    		int getM2Totales();
    		void setM2Verdes(int);
		void setM2Totales(int);
		~casa();
}

#endif
