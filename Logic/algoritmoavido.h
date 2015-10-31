#ifndef ALGORITMOAVIDO_H
#define ALGORITMOAVIDO_H

#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>

class algoritmoAvido{
private:
public:
    algoritmoAvido();
    cv::Mat ordenar(cv::Mat pMatriz);
};

#endif // ALGORITMOAVIDO_H
