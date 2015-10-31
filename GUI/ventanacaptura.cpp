#include "ventanacaptura.h"

ventanaCaptura::ventanaCaptura(QWidget *parent){
    this->fondo = new QLabel(this);
}

void ventanaCaptura::crearVentanaCapturada(cv::Mat pMatriz, cv::Mat pMatrizDesordenada){
    this->matImgCapturada=pMatriz.clone();
    this->matImgDesordenada=pMatrizDesordenada.clone();
    convertirMatriz(this->matImgDesordenada);
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QPixmap imagenOrdenar(":/Imagenes/Resources/botonOrdenar.jpg");
    QIcon iconoVolver(imagenVolver);
    QIcon iconoOrdenar(imagenOrdenar);
    QPushButton* botonVolver = new QPushButton(this);
    QPushButton* botonOrdenar = new QPushButton(this);
    botonVolver->setGeometry(1100,0,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());
    botonOrdenar->setGeometry(1050,650,imagenOrdenar.width(), imagenOrdenar.height());
    botonOrdenar->setIcon(iconoOrdenar);
    botonOrdenar->setIconSize(imagenOrdenar.rect().size());
    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));
    QPixmap *pixmap=new QPixmap(imagenFondo.width(), imagenFondo.height());
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(200, 100, this->image.width(), this->image.height(), QPixmap::fromImage(this->image));
    painter->end();
    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}

void ventanaCaptura::convertirMatriz(cv::Mat matrixImage){
    if(matrixImage.type()==CV_8UC1){
        QVector<QRgb> colorTable;
        for (int i=0; i<266; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_Indexed8);
        newImage.setColorTable(colorTable);
        this->image = newImage;
    }
    else if(matrixImage.type()==CV_8UC3){
        const uchar *qImageBuffer = (const uchar*)matrixImage.data;
        QImage newImage(qImageBuffer, matrixImage.cols, matrixImage.rows, matrixImage.step, QImage::Format_RGB888);
        this->image = newImage.rgbSwapped();
    }
}


void ventanaCaptura::volver(){
    menuPrincipal* menu = new menuPrincipal();
    this->close();
    this->deleteLater();
}
void ventanaCaptura::desordenar(){
    this->close();
}
