#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;
int main ( int argc, char** argv ){
    Mat img, img_gry, img_cny,img_lap, img_sob;
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_8U;
    namedWindow( "Examplebird", WINDOW_AUTOSIZE);
    namedWindow( "Examplegray", WINDOW_AUTOSIZE);
    namedWindow( "Examplecany", WINDOW_AUTOSIZE);
    namedWindow( "Examplelap", WINDOW_AUTOSIZE);
    namedWindow( "Examplesob", WINDOW_AUTOSIZE);
    img = imread( argv[1]);
    if(img.empty()) return -1;
    imshow( "Examplebird", img);
    cv::cvtColor( img, img_gry, cv::COLOR_BGR2GRAY);
    imshow("Examplegray", img_gry);
    cv::Canny( img_gry, img_cny, 10, 100, 3, true );
    imwrite("/Users/kakarlakeerthy/Desktop/saikeerthy_edge_detect/images/canny.jpg",img_cny);
    imshow( "Examplecany", img_cny);
    cv::Laplacian(img_gry, img_lap,ddepth,kernel_size, scale, delta, BORDER_DEFAULT);
    //Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
   
    imshow("Examplelap",img_lap);
    imwrite("/Users/kakarlakeerthy/Desktop/saikeerthy_edge_detect/images/laplacian.jpg",img_lap);

    cv::Sobel(img_gry,img_sob, ddepth,1,1,kernel_size,scale,delta);
    //Sobel( InputArray src, OutputArray dst, int ddepth,int dx, int dy, int ksize = 3,
    //double scale = 1, double delta = 0,
    //int borderType = BORDER_DEFAULT );
    imshow("Examplesob",img_sob);
    imwrite("/Users/kakarlakeerthy/Desktop/saikeerthy_edge_detect/images/sobel.jpg",img_sob);


    waitKey(0);
    destroyWindow( " Examplebird");
}
