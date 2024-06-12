#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <iostream>
#include "DataTypes/direccion.h"
#include "ICollection/collections/List.h"
#include "DataTypes/registroMensajes.h"
#include "chat.h"
#include "zona.h"

using namespace std;

class propiedad : public ICollectible
{
private:
    string codigo;
    int cantAmbientes, cantDormitorios, cantBanios, m2Edificados, precioAlquiler, precioVenta;
    bool garage;
    direccion *dir;
    zona * z;
    List *chats;
public:
    propiedad(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir, int m2Edificados , zona* z);
    ~propiedad();
    string getCodigo();
    int getCantAmbientes();
    int getCantDormitorios();
    int getCantBanios();
    bool getGarage();
    direccion *getDireccion();
    int getM2Edificados();
    int getPrecioAlquiler();
    int getPrecioVenta();
    zona* getZona();
    void setCantAmbientes(int cant);
    void setCantDormitorios(int cant);
    void setCantBanios(int cant);
    void setGarage(bool garage);
    void setDireccion(direccion* dir);
    void setM2Edificados(int m2);
    void setPrecioAlquiler(int precio);
    void setPrecioVenta(int precio);
    void CortarLazos(string codigo);
    registroMensajes *MostrarMensajes();
    chat *CrearChat();
    void IngresarMensaje(string mensaje);
    int obtenerCantMensajes();
};

#endif