#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#ifndef CV2UTILS_H_INCLUDED
#define CV2UTILS_H_INCLUDED

using namespace std;

class Cv2utils {

public:
  cv::Mat loadFile(string);
  cv::Mat medianBlur_k3(cv::Mat);
};

#endif