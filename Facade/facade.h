#ifndef FACADE_H
#define FACADE_H

#include "Logic/algoritmoavido.h"
#include "Logic/desordenarimagen.h"
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>

/**
 * @file facade.h
 * @brief The facade class, Comunica GUI con Logic. Esta clase permite la comunicacion
 *  entre ambas partes, pasando la imagen seleccionada
 * @author Jairo Daniel Ortega Calderon
 * @date October 31, 2015
 */
class facade{
private:
    desordenarImagen* imagen;
    algoritmoAvido* avido;
public:
    facade();
    cv::Mat desordenar(cv::Mat pMatriz);
    cv::Mat ordenar(cv::Mat pMatriz);
};

#endif // FACADE_H
