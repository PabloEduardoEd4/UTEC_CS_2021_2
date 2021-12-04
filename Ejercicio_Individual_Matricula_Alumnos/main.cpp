#include <iostream>
#include "Sistema.h"

int main() {
    Sistema* sistema = new Sistema();
    sistema->ejecutar();
    delete sistema;
}
