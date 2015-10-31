#ifndef VENTANAAYUDA_H
#define VENTANAAYUDA_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include "GUI/menuprincipal.h"

/**
 * @file ventanayuda.h
 * @brief The ventanaAyuda class, muestra un pequeno tutorial del programa
 * @author Jairo Daniel Ortega Calderon
 * @date October 31, 2015
 */
class ventanaAyuda : public QMainWindow{
    Q_OBJECT
public:
    ventanaAyuda(QWidget *parent = 0);

private slots:
    void volver();

};

#endif // VENTANAAYUDA_H
