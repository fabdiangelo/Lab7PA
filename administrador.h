#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include "usuario.h"

class administrador : public usuario{
	public:
		administrador(string, string);
		~administrador();
};

#endif
