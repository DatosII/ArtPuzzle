#ifndef VENTANACAPTURA_H
#define VENTANACAPTURA_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QIcon>
#include <QPainter>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "menuprincipal.h"
#include "Facade/facade.h"
#include "ventanadesordenada.h"

/**
 * @file ventanacaptura.h
 * @brief The ventanaCaptura class, permite observar la imagen capturada
 * @author Jairo Daniel Ortega Calderon
 * @date October 31, 2015
 */
class ventanaCaptura : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    QImage image;
    cv::Mat matImgCapturada;
    cv::Mat matImgDesordenada;
    cv::Mat _imagenArreglada[9];
    cv::Mat _imagenDesordenada[9];    
    facade* pFacade;
public:
    ventanaCaptura(QWidget *parent = 0);
    QImage convertirMatriz(cv::Mat matrixImage);
public slots:
    void desordenar();
    void crearVentanaCapturada(cv::Mat pMatriz);
private slots:
    void volver();
};

#endif // VENTANACAPTURA_H
