#include "ventanacaptura.h"

ventanaCaptura::ventanaCaptura(QWidget *parent){
    this->fondo = new QLabel(this);    
    this->pFacade = new facade();
}

void ventanaCaptura::crearVentanaCapturada(cv::Mat pMatriz){
    this->matImgCapturada=pMatriz.clone();
    this->image=convertirMatriz(pMatriz);
    QPixmap imagenFondo(":/Imagenes/Resources/fondoGeneral.jpg");
    QPixmap imagenVolver(":/Imagenes/Resources/botonVolver.jpg");
    QPixmap imagenDesordenar(":/Imagenes/Resources/botonDesordenar.jpg");
    QIcon iconoVolver(imagenVolver);
    QIcon iconoDesordenar(imagenDesordenar);
    QPushButton* botonVolver = new QPushButton(this);
    QPushButton* botonDesordenar = new QPushButton(this);
    botonVolver->setGeometry(1100,0,imagenVolver.width(), imagenVolver.height());
    botonVolver->setIcon(iconoVolver);
    botonVolver->setIconSize(imagenVolver.rect().size());
    botonDesordenar->setGeometry(1050,650,imagenDesordenar.width(), imagenDesordenar.height());
    botonDesordenar->setIcon(iconoDesordenar);
    botonDesordenar->setIconSize(imagenDesordenar.rect().size());
    QObject::connect(botonVolver, SIGNAL(clicked()), this, SLOT(volver()));
    QObject::connect(botonDesordenar, SIGNAL(clicked()), this, SLOT(desordenar()));
    QPixmap *pixmap=new QPixmap(imagenFondo.width(), imagenFondo.height());
    QPainter *painter=new QPainter(pixmap);
    painter->drawPixmap(0, 0, imagenFondo.width(), imagenFondo.height(), imagenFondo);
    painter->drawPixmap(200, 100, this->image.width(), this->image.height(), QPixmap::fromImage(this->image));
    painter->end();
    this->fondo->setPixmap(*pixmap);
    this->fondo->resize(QSize(imagenFondo.width(),imagenFondo.height()));
    this->showMaximized();
}

QImage ventanaCaptura::convertirMatriz(cv::Mat matrixImage){
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


void ventanaCaptura::volver(){
    menuPrincipal* menu = new menuPrincipal();
    this->close();
    this->deleteLater();
}
void ventanaCaptura::desordenar(){
    ventanaDesordenada* ventana = new ventanaDesordenada();
    this->matImgDesordenada=this->pFacade->desordenar(this->matImgCapturada);
    ventana->recibir(this->matImgCapturada, this->matImgDesordenada);
    this->close();    
    this->deleteLater();
}
