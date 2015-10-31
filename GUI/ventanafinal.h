#ifndef VENTANAFINAL_H
#define VENTANAFINAL_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "menuprincipal.h"

/**
 * @file ventanafinal.h
 * @brief The ventanaFinal class, Muestra la imagen original y la "ordenada"
 * @author Jairo Daniel Ortega Calderon
 * @date October 31, 2015
 */
class ventanaFinal : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    QImage imgOrg;
    QImage imgOrd;
    cv::Mat matImgCapturada;
    cv::Mat matImgOrdenada;
public:
    ventanaFinal(QWidget *parent = 0);
    void recibir(cv::Mat pMatrizCap, cv::Mat pMatrizOrd);
    QImage convertirMatriz(cv::Mat matrixImage);
public slots:
    void volver();

};

#endif // VENTANAFINAL_H
