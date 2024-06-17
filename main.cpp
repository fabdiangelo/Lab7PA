#include "factory.h"
#include "ISistema.h"

int main() {
    ISistema *s = factory::getSistema();
    cout << "soy feliz" << endl;

    return 0;
}
