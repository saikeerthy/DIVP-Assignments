
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main( int argc, char* argv[] ) {
    
    cv::namedWindow( "Example2_11", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example2",   cv::WINDOW_AUTOSIZE );
    
    
    cv::VideoCapture capture( 0 );
    
    double fps = capture.get( cv::CAP_PROP_FPS );
    cv::Size size(
                  (int)capture.get( cv::CAP_PROP_FRAME_WIDTH ),
                  (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT )
                  );
    cv::VideoWriter writer;
    cv::VideoWriter downsam;
    writer.open("/Users/kakarlakeerthy/Desktop/Kakarla_VideoCaptureDisplay/original.mp4", CV_FOURCC('M','J','P','G'), fps, size );
    downsam.open("/Users/kakarlakeerthy/Desktop/Kakarla_VideoCaptureDisplay/downsampled.mp4", CV_FOURCC('M','J','P','G'), fps,size/2);
    cv::Mat bgr_frame,img2;
    
  
    for(;;) {
        
      
        capture >> bgr_frame;
        if( bgr_frame.empty() ) break; // end if done
        
        cv::imshow( "Example2_11", bgr_frame );
        cv::pyrDown( bgr_frame, img2);
        cv::imshow( "Example2", img2 );
        writer << bgr_frame;
        downsam << img2;
     
        char c = cv::waitKey(fps);
        
        
        
        if( c == 27) break;
        
    }
    
    
    return 0;
    
}
