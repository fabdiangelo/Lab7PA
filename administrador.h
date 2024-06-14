#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.h"

class administrador : public usuario{
	public:
		administrador(string correo, string contrasenia);
		~administrador();
};

#endif
