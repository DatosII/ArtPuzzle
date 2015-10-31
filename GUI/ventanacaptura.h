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

class ventanaCaptura : public QMainWindow{
    Q_OBJECT
private:
    QLabel* fondo;
    QImage image;
    cv::Mat matImgCapturada;
    cv::Mat matImgDesordenada;
    cv::Mat _imagenArreglada[9];
    cv::Mat _imagenDesordenada[9];
public:
    ventanaCaptura(QWidget *parent = 0);
    void convertirMatriz(cv::Mat matrixImage);
public slots:
    void desordenar();
    void crearVentanaCapturada(cv::Mat pMatriz, cv::Mat pMatrizDesordenada);
private slots:
    void volver();
};

#endif // VENTANACAPTURA_H
