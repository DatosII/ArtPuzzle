#include "facade.h"

/**
 * @brief facade::facade, construtor de la clase
 */
facade::facade(){
    this->imagen = new desordenarImagen();
    this->avido = new algoritmoAvido();
}
/**
 * @brief facade::desordenar, Se comunica con la logica para desacomodar la imagen
 * @param pMatriz, matriz de la fotografia tomada
 * @return la matriz desordenada
 */
cv::Mat facade::desordenar(cv::Mat pMatriz){
    return this->imagen->desordenar(pMatriz);
}
/**
 * @brief facade::ordenar, Se comunica con la logica para acomodar la imagen
 * @param pMatriz, matriz desordenada
 * @return La matriz ordenada
 */
cv::Mat facade::ordenar(cv::Mat pMatriz){
    return this->avido->ordenar(pMatriz);
}
