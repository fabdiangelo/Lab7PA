#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include "chat.h"
#include "DataTypes/direccion.h"
#include "inmobiliaria.h"
#include "zona.h"
#include <iostream>

using namespace std;

class chat;
class inmobiliaria;
class zona;

class propiedad : public ICollectible
{
private:
    string codigo;
    int cantAmbientes, cantDormitorios, cantBanios, m2Edificados, precioAlquiler, precioVenta;
    bool garage;
    direccion *dir;
    zona *z;
    IDictionary *chats;
    inmobiliaria *inmo;
public:
    propiedad(string codigo, int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, direccion* dir, int m2Edificados , zona* z, inmobiliaria* inmo);
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
    IDictionary* getChats();
    inmobiliaria *getInmobiliaria();
    void setCantAmbientes(int cant);
    void setCantDormitorios(int cant);
    void setCantBanios(int cant);
    void setGarage(bool garage);
    void setDireccion(direccion* dir);
    void setM2Edificados(int m2);
    void setPrecioAlquiler(int precio);
    void setPrecioVenta(int precio);
    registroMensajes *MostrarMensajes(string correo);
    void CrearChat(string correo);
    void IngresarMensaje(string correo, string mensaje);
    int obtenerCantMensajes(string correo);
    virtual void CortarLazos() = 0;
    friend ostream& operator<<(ostream& os, propiedad *prop);
};

#endif