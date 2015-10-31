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
#include "Facade/facade.h"

class menuPrincipal : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    CvCapture* _CaptureCam;
    IplImage* _SaveImage;
    cv::Mat _imagenCapturada;
    cv::Mat _imagenDesordenada;
    facade* pFacade;
public:
    menuPrincipal(QWidget *parent = 0);
    ~menuPrincipal();
private slots:
    void crearVentanaCaptura();
    void crearVentanaAyuda();

};

#endif // MENUPRINCIPAL_H
