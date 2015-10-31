#ifndef DESORDENARIMAGEN_H
#define DESORDENARIMAGEN_H

#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include "constansLogic.h"

class desordenarImagen{
private:
    int _y;
    int _x;
    int _x1;
    int _yz;
    int _indiceCicloPartes;
    int _indiceArregloDesordenado;
    int _fila;
    int _columna;
    int _indiceCicloDesordenarImagenes;
    int _posIndiceDesordenarImagenes;
    int _estalibre[8];
    cv::Mat _imagenArreglada[9];
    cv::Mat _imagenDesordenada[9];
    cv::Mat _arregloDesordenadoCopia[8];
    cv::Mat _arrayTemporal[8];
    cv::Mat _imagenPrincipal;
    cv::Mat _imagenSecundaria;
    time_t _t;
    void llenarCanvas(int px,int py, int pindice,int lim);
    void desordenarimagen();
    void desarmarImagen();
    void crearImagen();
public:
    desordenarImagen();
    cv::Mat desordenar(cv::Mat pMatriz);
};

#endif // DESORDENARIMAGEN_H
