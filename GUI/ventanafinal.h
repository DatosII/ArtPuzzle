#ifndef VENTANAFINAL_H
#define VENTANAFINAL_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include "menuprincipal.h"

class ventanaFinal : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
public:
    ventanaFinal(QWidget *parent = 0);
    void resultadoFinal();
public slots:
    void volver();

};

#endif // VENTANAFINAL_H
