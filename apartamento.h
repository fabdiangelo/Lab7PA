#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
#include propiedad.h

class apartamento : public propiedad{
	private:
		int M2Totales;
	public:
		apartamento(string, int, int, int, bool, direccion, int, int, int, chat**, int);
		int getM2Totales();
		void setM2Totales(int);
		~apartamento();
}

#endif
