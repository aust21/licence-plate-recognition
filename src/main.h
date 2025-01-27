#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

cv::CascadeClassifier loadCascade(std::string filepath);
cv::VideoCapture loadCam(std::string filepath);

#endif // MAIN_H
