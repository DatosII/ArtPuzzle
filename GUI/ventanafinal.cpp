#include "ventanafinal.h"

ventanaFinal::ventanaFinal(QWidget *parent){
    this->fondo = new QLabel(this);
}

void ventanaFinal::resultadoFinal(){
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QIcon iconoVolver(imagenVolver);
    QPushButton* botonVolver = new QPushButton(this);
    botonVolver->setGeometry(1100, 0,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());
    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));
    this->fondo->setPixmap(imagenFondo);
    this->fondo->setGeometry(0, 0, imagenFondo.width(), imagenFondo.height());
    this->showMaximized();
}

void ventanaFinal::volver(){
    menuPrincipal* menu = new menuPrincipal();
    this->close();
    this->deleteLater();
}
