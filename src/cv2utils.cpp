#include "cv2utils.h"

using namespace cv;


Mat Cv2utils::loadFile(string f){

     Mat img = imread(f);

     return img;
    
}

Mat Cv2utils::medianBlur_k3(Mat src){
    Mat dst = Mat::zeros( src.size(), src.type() );
    uint kernal_size = 3;
     medianBlur( src, dst, kernal_size );

     return dst;
}
