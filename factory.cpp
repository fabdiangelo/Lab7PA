#include "factory.h"

ISistema * factory::getSistema() {
    return sistema::getInstance();
};


