#include "desordenarimagen.h"

cv::Mat _imagenResultado (CONSTANTSLOGIC::TAMANOIMAGEN , CONSTANTSLOGIC::TAMANOIMAGEN, CV_8UC3);
/**
 * @brief desordenarImagen::desordenarImagen, constructor de la clase
 */
desordenarImagen::desordenarImagen(){
    this->_y = CONSTANTSLOGIC::CERO;
    this->_x = CONSTANTSLOGIC::CERO;
    this->_x1 = CONSTANTSLOGIC::TAMANOCUADRO;
    this->_yz = CONSTANTSLOGIC::TAMANOCUADRO;
    this->_indiceCicloPartes = CONSTANTSLOGIC::CERO;
    this->_indiceArregloDesordenado = CONSTANTSLOGIC::CERO;
    this->_fila=CONSTANTSLOGIC::CERO;
    this->_columna=CONSTANTSLOGIC::CERO;
}
/**
 * @brief desordenarImagen::desordenar, recibe la imagen y se encarga de distribuirla en el proceso
 * @param pMatriz
 * @return la imagen desordenada
 */
cv::Mat desordenarImagen::desordenar(cv::Mat pMatriz){
    _imagenPrincipal=pMatriz.clone();
    desarmarImagen();
    _imagenDesordenada[CONSTANTSLOGIC::TOTALELEMENTOS]= _imagenArreglada[CONSTANTSLOGIC::TOTALELEMENTOS];
    desordenarimagen();
    crearImagen();
    return  _imagenResultado;
}
/**
 * @brief desordenarImagen::desarmarImagen, descompone la imagen en cuadros
 */
void desordenarImagen::desarmarImagen(){
    for(;_y<CONSTANTSLOGIC::TAMANOIMAGEN;_y+=CONSTANTSLOGIC::TAMANOCUADRO,_yz+CONSTANTSLOGIC::TAMANOCUADRO){
        for(;_x<CONSTANTSLOGIC::TAMANOIMAGEN;_x+=CONSTANTSLOGIC::TAMANOCUADRO,_x1+CONSTANTSLOGIC::TAMANOCUADRO){
            _imagenArreglada[_indiceCicloPartes]=_imagenPrincipal(cv::Rect(_x,_y,_x1,_yz));
            _indiceCicloPartes+=CONSTANTSLOGIC::UNO;
        }
        _x=CONSTANTSLOGIC::CERO;
        _x1=CONSTANTSLOGIC::TAMANOCUADRO;
    }
}
/**
 * @brief desordenarImagen::crearImagen
 */
void desordenarImagen::crearImagen(){
    while(_columna<CONSTANTSLOGIC::TAMANOIMAGEN){
        while(_fila<CONSTANTSLOGIC::TAMANOIMAGEN){
            if(_indiceArregloDesordenado!=CONSTANTSLOGIC::TOTALELEMENTOS){
                llenarCanvas(_fila,_columna,_indiceArregloDesordenado,_fila);
                _fila+=CONSTANTSLOGIC::TAMANOCUADRO;
                _indiceArregloDesordenado+=1;
            }else{
                _fila+=CONSTANTSLOGIC::TAMANOCUADRO;
                _indiceArregloDesordenado+=CONSTANTSLOGIC::UNO;
            }
        }
        _fila=CONSTANTSLOGIC::CERO;
        _columna+=CONSTANTSLOGIC::TAMANOCUADRO;
    }
}
/**
 * @brief desordenarImagen::llenarCanvas
 * @param px
 * @param py
 * @param pindice
 * @param lim
 */
void desordenarImagen::llenarCanvas(int px,int py, int pindice,int lim){
    for(int y=CONSTANTSLOGIC::CERO;y<CONSTANTSLOGIC::TAMANOCUADRO;y++){
        for(int x=CONSTANTSLOGIC::CERO;x<CONSTANTSLOGIC::TAMANOCUADRO;x++){
            _imagenResultado.at<cv::Vec3b>(py,px)=_imagenDesordenada[pindice].at<cv::Vec3b>(y,x);
            px+=CONSTANTSLOGIC::UNO;
        }
        px=lim;
        py+=CONSTANTSLOGIC::UNO;
    }
}
/**
 * @brief desordenarImagen::desordenarimagen, se encarga de armar la imagen de manera aleatoria
 */
void desordenarImagen::desordenarimagen(){
    srand((unsigned) time(&_t));
    for(_indiceCicloDesordenarImagenes=CONSTANTSLOGIC::CERO;_indiceCicloDesordenarImagenes<CONSTANTSLOGIC::TOTALELEMENTOS;_indiceCicloDesordenarImagenes++){
        _arrayTemporal[_indiceCicloDesordenarImagenes]=_imagenArreglada[_indiceCicloDesordenarImagenes];
        _estalibre[_indiceCicloDesordenarImagenes]=CONSTANTSLOGIC::UNO;
    }
    for(_indiceCicloDesordenarImagenes=CONSTANTSLOGIC::CERO;_indiceCicloDesordenarImagenes<CONSTANTSLOGIC::TOTALELEMENTOS;_indiceCicloDesordenarImagenes++) {
        _posIndiceDesordenarImagenes=rand()%CONSTANTSLOGIC::TOTALELEMENTOS;
        while (_estalibre[_posIndiceDesordenarImagenes]==CONSTANTSLOGIC::CERO)
            _posIndiceDesordenarImagenes=rand()%CONSTANTSLOGIC::TOTALELEMENTOS;
        _arregloDesordenadoCopia[_posIndiceDesordenarImagenes]=_arrayTemporal[_indiceCicloDesordenarImagenes];
        _estalibre[_posIndiceDesordenarImagenes]=CONSTANTSLOGIC::CERO;
        _imagenDesordenada[_posIndiceDesordenarImagenes]=_arregloDesordenadoCopia[_posIndiceDesordenarImagenes];
    }
}
