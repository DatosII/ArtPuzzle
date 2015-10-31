#include "ventanafinal.h"
/**
 * @brief ventanaFinal::ventanaFinal, constructor de la clase
 * @param parent
 */
ventanaFinal::ventanaFinal(QWidget *parent){
    this->fondo = new QLabel(this);
}
/**
 * @brief ventanaFinal::recibir, recibe la imagen original y la ordenada
 * @param pMatrizCap
 * @param pMatrizOrd
 */
void ventanaFinal::recibir(cv::Mat pMatrizCap, cv::Mat pMatrizOrd){
    this->matImgCapturada=pMatrizCap;
    this->matImgOrdenada=pMatrizOrd;
    this->imgOrg=convertirMatriz(this->matImgCapturada);
    this->imgOrd=convertirMatriz(this->matImgOrdenada);
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QIcon iconoVolver(imagenVolver);
    QPushButton* botonVolver = new QPushButton(this);
    botonVolver->setGeometry(1100,0,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());
    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));
    QPixmap *pixmap=new QPixmap(imagenFondo.width(), imagenFondo.height());
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(135, 144, this->imgOrg.width(), this->imgOrg.height(), QPixmap::fromImage(this->imgOrg));
    painter->drawPixmap(750, 144, this->imgOrd.width(), this->imgOrd.height(), QPixmap::fromImage(this->imgOrd));
    painter->end();
    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}
/**
 * @brief ventanaFinal::volver, permite volver al menu principal
 */
void ventanaFinal::volver(){
    menuPrincipal* menu = new menuPrincipal();
    this->close();
    this->deleteLater();
}
/**
 * @brief ventanaFinal::convertirMatriz, convierte la matriz de tipo cv::Mat a QImage
 * @param matrixImage
 * @return imagen en formato QImage
 */
QImage ventanaFinal::convertirMatriz(cv::Mat matrixImage){
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
