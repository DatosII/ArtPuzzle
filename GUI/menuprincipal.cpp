#include "menuprincipal.h"

menuPrincipal::menuPrincipal(QWidget *parent){
    this->fondo = new QLabel(this);
    QPixmap imagenFondo(":/Imagenes/Resources/menuPrincipal.jpg");
    QPixmap imagenCapturar(":/Imagenes/Resources/botonCapturar.jpg");
    QPixmap imagenAyuda(":/Imagenes/Resources/botonAyuda.jpg");
    QPixmap imagenSalir(":/Imagenes/Resources/botonSalir.jpg");
    QIcon iconoCapturar(imagenCapturar);
    QIcon iconoAyuda(imagenAyuda);
    QIcon iconoSalir(imagenSalir);
    QPushButton* botonCapturar = new QPushButton(this);
    QPushButton* botonAyuda = new QPushButton(this);
    QPushButton* botonSalir = new QPushButton(this);
    botonCapturar->setGeometry(400,400,imagenCapturar.width(), imagenCapturar.height());
    botonCapturar->setIcon(iconoCapturar);
    botonCapturar->setIconSize(imagenCapturar.rect().size());
    botonAyuda->setGeometry(500,500,imagenAyuda.width(), imagenAyuda.height());
    botonAyuda->setIcon(iconoAyuda);
    botonAyuda->setIconSize(imagenAyuda.rect().size());
    botonSalir->setGeometry(500,600,imagenSalir.width(),imagenSalir.height());
    botonSalir->setIcon(iconoSalir);
    botonSalir->setIconSize(imagenSalir.rect().size());
    QObject::connect(botonCapturar, SIGNAL(clicked()), this, SLOT(crearVentanaCaptura()));
    QObject::connect(botonAyuda, SIGNAL(clicked()), this, SLOT(crearVentanaAyuda()));
    QObject::connect(botonSalir, SIGNAL(clicked()), this, SLOT(close()));
    this->fondo->setPixmap(imagenFondo);
    this->fondo->setGeometry(0, 0, imagenFondo.width(), imagenFondo.height());
    this->showMaximized();
}

menuPrincipal::~menuPrincipal(){
}

void menuPrincipal::crearVentanaCaptura(){
    ventanaCaptura * captura = new ventanaCaptura();
    this->_CaptureCam=cvCreateCameraCapture(0);
    this->_SaveImage=cvQueryFrame(_CaptureCam);
    cvSaveImage("/home/jairodaniel_23/QT Projects/ArtPuzzle/Resources/imagenCapturada.jpg",_SaveImage);
    cv::Mat matTmp =cv::imread("/home/jairodaniel_23/QT Projects/ArtPuzzle/Resources/imagenCapturada.jpg");
    this->_imagenCapturada=matTmp(cv::Rect(0,0,matTmp.cols-160, matTmp.rows));
    cvReleaseCapture(&_CaptureCam);
    captura->crearVentanaCapturada(this->_imagenCapturada);
    this->close();
    this->deleteLater();
}

void menuPrincipal::crearVentanaAyuda(){
    ventanaAyuda* ayuda = new ventanaAyuda();
    this->close();
    this->deleteLater();
}
