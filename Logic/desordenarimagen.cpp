#include "desordenarimagen.h"

cv::Mat _imagenResultado (600 , 600, CV_8UC3);

desordenarImagen::desordenarImagen(){
    this->_y = 0;
    this->_x = 0;
    this->_x1 = 200;
    this->_yz = 200;
    this->_indiceCicloPartes = 0;
    this->_indiceArregloDesordenado = 0;
    this->_fila=0;
    this->_columna=0;
}

cv::Mat desordenarImagen::desordenar(cv::Mat pMatriz){
    _imagenPrincipal=pMatriz;
    desarmarImagen();
    _imagenDesordenada[8]= _imagenArreglada[8];
    desordenarimagen();
    crearImagen();
    return  _imagenResultado;
}

void desordenarImagen::desarmarImagen(){
    for(;_y<600;_y+=200,_yz+200){
        for(;_x<600;_x+=200,_x1+200){
            _imagenArreglada[_indiceCicloPartes]=_imagenPrincipal(cv::Rect(_x,_y,_x1,_yz));
            _indiceCicloPartes+=1;
        }
        _x=0;
        _x1=200;
    }
}

void desordenarImagen::crearImagen(){
    while(_columna<600){
        while(_fila<600){
            if(_indiceArregloDesordenado!=8){
                llenarCanvas(_fila,_columna,_indiceArregloDesordenado,_fila);
                _fila+=200;
                _indiceArregloDesordenado+=1;
            }else{
                _fila+=200;
                _indiceArregloDesordenado+=1;
            }
        }
        _fila=0;
        _columna+=200;
    }
}
void desordenarImagen::llenarCanvas(int px,int py, int pindice,int lim){
    for(int y=0;y<200;y++){
        for(int x=0;x<200;x++){
            _imagenResultado.at<cv::Vec3b>(py,px)=_imagenDesordenada[pindice].at<cv::Vec3b>(y,x);
            px+=1;
        }
        px=lim;
        py+=1;
    }
}
void desordenarImagen::desordenarimagen(){
    srand((unsigned) time(&_t));
    for(_indiceCicloDesordenarImagenes=0;_indiceCicloDesordenarImagenes<8;_indiceCicloDesordenarImagenes++){
        _arrayTemporal[_indiceCicloDesordenarImagenes]=_imagenArreglada[_indiceCicloDesordenarImagenes];
        _estalibre[_indiceCicloDesordenarImagenes]=1;
    }
    for(_indiceCicloDesordenarImagenes=0;_indiceCicloDesordenarImagenes<8;_indiceCicloDesordenarImagenes++) {
        _posIndiceDesordenarImagenes=rand()%8;
        while (_estalibre[_posIndiceDesordenarImagenes]==0)
            _posIndiceDesordenarImagenes=rand()%8;
        _arregloDesordenadoCopia[_posIndiceDesordenarImagenes]=_arrayTemporal[_indiceCicloDesordenarImagenes];
        _estalibre[_posIndiceDesordenarImagenes]=0;
        _imagenDesordenada[_posIndiceDesordenarImagenes]=_arregloDesordenadoCopia[_posIndiceDesordenarImagenes];
    }
}
