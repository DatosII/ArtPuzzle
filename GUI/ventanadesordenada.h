#ifndef VENTANADESORDENADA_H
#define VENTANADESORDENADA_H

#include <QMainWindow>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "ventanafinal.h"
#include "Facade/facade.h"

/**
 * @file ventanaordenada.h
 * @brief The ventanaDesordenada class, muestra la imagen seleccionada y la desordenada
 * @author Jairo Daniel Ortega Calderon
 * @date October 31, 2015
 */
class ventanaDesordenada : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    QImage imgOrd;
    QImage imgDesord;
    cv::Mat matImgCapturada;
    cv::Mat matImgDesordenada;
    facade* pFacade;
public:
    ventanaDesordenada(QWidget *parent = 0);
    QImage convertirMatriz(cv::Mat matrixImage);
    void recibir(cv::Mat pMatrizO, cv::Mat pMatrizD);
public slots:
    void ordenar();
};

#endif // VENTANADESORDENADA_H
