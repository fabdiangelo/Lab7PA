#include "factory.h"

sistema * factory::getSistema() {
    return sistema::getInstance(); // hay que crear esta funcionalidad en el sistema o se coloco mal?
};


