
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
    
    cv::Mat bgr_frame,img2;
    
    int k=0;
    for(;;) {
        
        k++;
        char filename[80];
        capture >> bgr_frame;
        if( bgr_frame.empty() ) break; // end if done
        
        cv::imshow( "Example2_11", bgr_frame );
        cv::pyrDown( bgr_frame, img2);
        cv::imshow( "Example2", img2 );
        
        sprintf(filename,"/Users/kakarlakeerthy/Desktop/saikeerthy_edge_detect/images/frames%d.jpg",k);
        imwrite(filename, img2);
        
        
        char c = cv::waitKey(fps);
        
        
        
        if( c == 27) break;
        
    }
    
    
    return 0;
    
}
