#ifndef VENTANADESORDENADA_H
#define VENTANADESORDENADA_H

#include <QMainWindow>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include "ventanafinal.h"

class ventanaDesordenada : public QMainWindow{
    Q_OBJECT
public:
    ventanaDesordenada(QWidget *parent = 0);
public slots:
    void ordenar();
};

#endif // VENTANADESORDENADA_H
