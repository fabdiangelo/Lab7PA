#include "departamento.h"

// CONSTRUCTOR:
departamento::departamento(string nombre, char id){
    this -> nombre = nombre;
    this -> id = id;
    this -> zonas = new OrderedDictionary();
}

// DESTRUCTOR:
departamento::~departamento(){
    cout << "destruct de departamento" << endl;
}

// GETTERS:
string departamento::getNombre(){
    return this -> nombre;
}

char departamento::getId(){
    return this -> id;
}

IDictionary *departamento::getZonas(){
    return this -> zonas;
}

// SETTERS:
void departamento::setNombre(string nombre){
    this -> nombre = nombre;
}

void departamento::setId(char id){
    this -> id = id;
}

// FUNCIONALIDADES:
void departamento::agregarZona(string nombre, string codigo){
    IKey *k = new String(codigo.c_str());
    if(this -> zonas -> member(k)){
        throw invalid_argument("Ya existe una zona con este código dentro de el departamento " + this -> getNombre() + "\n");
    }
    zona *z = new zona(nombre, codigo, this);
    this -> zonas -> add(k, z);
}

zona* departamento::seleccionarZona(string cod){
    for(IIterator *iter = this -> zonas -> getIterator(); iter -> hasCurrent(); iter -> next()){
        zona *z =(zona*) iter -> getCurrent();
        if (z -> getCodigo() == cod){
            return z;
        }
    }
    cout << "No se encontró una zona con ese código dentro de " << this -> getNombre();
    return NULL;
}

// SOBRECARGA:
ostream& operator<<(ostream& os, departamento* dep){
    os << "  " << dep -> getId() << ") " << dep -> getNombre() << endl;
    return os;
}