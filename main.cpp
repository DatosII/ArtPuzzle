#include "GUI/menuprincipal.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication aplicacion(argc, argv);
    menuPrincipal *principal = new menuPrincipal();
    return aplicacion.exec();
}
