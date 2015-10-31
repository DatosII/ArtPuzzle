#ifndef FACADE_H
#define FACADE_H

#include "Logic/algoritmoavido.h"
#include "Logic/desordenarimagen.h"
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>

class facade{
private:
    desordenarImagen* imagen;
public:
    facade();
    cv::Mat desordenar(cv::Mat pMatriz);
};

#endif // FACADE_H
