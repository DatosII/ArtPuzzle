#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include "ventanaayuda.h"
#include "ventanacaptura.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/**
 * @file menuPrincipal.h
 * @brief The menuPrincipal class, muestra el menu inicial del programa
 * @author Jairo Daniel Ortega Calderon
 * @date October 31, 2015
 */
class menuPrincipal : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    CvCapture* _CaptureCam;
    IplImage* _SaveImage;
    cv::Mat _imagenCapturada;
public:
    menuPrincipal(QWidget *parent = 0);
    ~menuPrincipal();
private slots:
    void crearVentanaCaptura();
    void crearVentanaAyuda();

};

#endif // MENUPRINCIPAL_H
