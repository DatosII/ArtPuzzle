#include "facade.h"

facade::facade(){
    this->imagen = new desordenarImagen();
}

cv::Mat facade::desordenar(cv::Mat pMatriz){
    return this->imagen->desordenar(pMatriz);
}
