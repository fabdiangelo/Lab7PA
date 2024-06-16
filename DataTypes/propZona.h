#ifndef PROPZONA_H
#define PROPZONA_H

#include "../zona.h"
#include "../propiedad.h"

class zona;
class propiedad;

class propZona : public ICollectible
{
private:
    zona *z;
    IDictionary *propiedades;
public:
    propZona(zona *z);
    ~propZona();
    zona* getZona();
    IDictionary *getPropiedades();
    void agregarProp(propiedad* prop);
};

#endif