#include "ventanadesordenada.h"

ventanaDesordenada::ventanaDesordenada(QWidget *parent){
    this->fondo = new QLabel(this);
    this->pFacade = new facade();
}

void ventanaDesordenada::recibir(cv::Mat pMatrizO, cv::Mat pMatrizD){
    this->matImgCapturada=pMatrizO;
    this->matImgDesordenada=pMatrizD;
    this->imgOrd=convertirMatriz(this->matImgCapturada);
    this->imgDesord=convertirMatriz(this->matImgDesordenada);
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenOrdenar(":/Imagenes/Resources/botonOrdenar.jpg");
    QIcon iconoOrdenar(imagenOrdenar);
    QPushButton* botonOrdenar = new QPushButton(this);
    botonOrdenar->setGeometry(1050,650,imagenOrdenar.width(), imagenOrdenar.height());
    botonOrdenar->setIcon(iconoOrdenar);
    botonOrdenar->setIconSize(imagenOrdenar.rect().size());
    QObject::connect(botonOrdenar, SIGNAL(clicked()), this, SLOT(ordenar()));
    QPixmap *pixmap=new QPixmap(imagenFondo.width(), imagenFondo.height());
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(135, 144, this->imgOrd.width(), this->imgOrd.height(), QPixmap::fromImage(this->imgOrd));
    painter->drawPixmap(750, 144, this->imgDesord.width(), this->imgDesord.height(), QPixmap::fromImage(this->imgDesord));
    painter->end();
    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}

void ventanaDesordenada::ordenar(){
    ventanaFinal* ventana = new ventanaFinal();
    ventana->recibir(this->matImgCapturada, pFacade->ordenar(this->matImgDesordenada));
    this->close();
    this->deleteLater();
}

QImage ventanaDesordenada::convertirMatriz(cv::Mat matrixImage){
    if(matrixImage.type()==CV_8UC1){
        QVector<QRgb> colorTable;
        for (int i=0; i<266; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_Indexed8);
        newImage.setColorTable(colorTable);
        return newImage;
    }
    else if(matrixImage.type()==CV_8UC3){
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_RGB888);
        return newImage.rgbSwapped();
    }
}
