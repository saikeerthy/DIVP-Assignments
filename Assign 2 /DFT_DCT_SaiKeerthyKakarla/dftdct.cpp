#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv/cv.h"
#include "opencv2/core/core.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    Mat dst,outp,dst_trunc,dst_t,dst_not, dst_not1;
    
    
    Mat img = imread("/Users/kakarlakeerthy/Desktop/dftex/zebras.jpg",0 );
    
    img.convertTo(dst, CV_32F);
    dft(dst,outp);// DFT_REAL_OUTPUT);
    
    namedWindow( "fig1", cv::WINDOW_AUTOSIZE );
    imshow( "fig1", img );// input image
    namedWindow( "fig2", cv::WINDOW_AUTOSIZE );
    imshow( "fig2", outp );// dft image
    imwrite("/Users/kakarlakeerthy/Desktop/dftex/dftim.jpg",outp);
    
    
    cout << "width : " << outp.size().width << endl;
    cout << "height: " << outp.size().height << endl;
    /*  int k1 = outp.size().width;
     
     int k2 = outp.size().height;
     
     
     for( int i=L; i<=k1-L+1;i++)
     {
     for(int j=L; j<=k2-L+1;i++)
     {
     outp.at<float>(i,j)=0;
     }
     }*/
    idft(outp,dst_not,DFT_SCALE); //| DFT_REAL_OUTPUT); inverse dft without truncation
    dst_not.convertTo(dst_not1, CV_8U);//convertion
    int k1 = dst.rows;
    int k2 = dst.cols;
    int L = 50;
    
    for (int i = L; i <= (k1 - L + 1); i++)
    {
        for (int j = L; j <= (k2 - L + 1); j++)
        {
            outp.at<float>(i,j) = 0;
        }
        
    }
    
    
    idft(outp,dst_trunc,DFT_SCALE); //| DFT_REAL_OUTPUT); inverse dft with truncation
    dst_trunc.convertTo(dst_t, CV_8U);//conversion
    namedWindow( "fig3", cv::WINDOW_AUTOSIZE );
    imshow( "fig3", outp );//changed dft image
    namedWindow( "fig4", cv::WINDOW_AUTOSIZE );
    imshow( "fig4", dst_not1 );// idft image without truncation
    namedWindow( "fig5", cv::WINDOW_AUTOSIZE );
    imshow( "fig5", dst_t );// idft image with truncation
    
    Mat dctim,dctim1,dctim2,dctim3,dctim4;
    
    dct(dst, dctim);// dct
    idct(dctim,dctim1);
    dctim1.convertTo(dctim2, CV_8U);
    namedWindow( "fig6", cv::WINDOW_AUTOSIZE );
    imshow( "fig6", dctim2 );// idct without truncation
    namedWindow( "fig9", cv::WINDOW_AUTOSIZE );
    imshow( "fig9", dctim );//dct image generated
    
    int Ld = 70;
    for (int i = Ld;i<=k1-1;i++)
    {
        for (int j = Ld; j <= k2 - 1; j++)
        {
            dctim.at<float>(i, j) = 0;
        }
    }
    namedWindow( "fig8", cv::WINDOW_AUTOSIZE );
    imshow( "fig8", dctim );//changed dct image
    idct(dctim,dctim3);
    dctim3.convertTo(dctim4, CV_8U);
    
    namedWindow( "fig7", cv::WINDOW_AUTOSIZE );
    imshow( "fig7", dctim4 );// idct image with truncation
    
    
    imwrite("/Users/kakarlakeerthy/Desktop/dftex/changdftim.jpg",outp);
    imwrite("/Users/kakarlakeerthy/Desktop/dftex/idftwouttrunc.jpg",dst_not1);
    imwrite("/Users/kakarlakeerthy/Desktop/dftex/idftwithtrunc.jpg",dst_t);
    imwrite("/Users/kakarlakeerthy/Desktop/dftex/idctwouttrunc.jpg",dctim2);
    imwrite("/Users/kakarlakeerthy/Desktop/dftex/idctwtrunc.jpg",dctim4);
    
    waitKey( 0 );
    
    
}
