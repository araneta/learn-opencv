/*
 * LoadAndSaveImage.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: aldo
 */
#include "CornerHarris.h"

CornerHarris::CornerHarris(){
	thresh = 200;
	max_thresh = 255;

	source_window = "Source image";
	corners_window = "Corners detected";
}
void CornerHarris::demo(char * filepath){
	cout << "3"<<filepath;

	/// Load source image and convert it to gray
	  src = imread(filepath, 1 );

	  cout << "4";

	  cvtColor( src, src_gray, CV_BGR2GRAY );
	  cout << "5";
	  /// Create a window and a trackbar
	  namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	  cout<<"6";

	  cv::createTrackbar("Threshold: ", source_window, &thresh, max_thresh, &CornerHarris::on_trackbar,this );
	  cout << "7";

	  imshow( source_window, src );
	  cout<<"8";

	  //on_trackbar( 0, 0 );
	  cout<<"9";
	  //return;
	  waitKey(0);

}
void CornerHarris::on_trackbar(int newval, void * obj){
	CornerHarris* myClass = (CornerHarris*) obj;
	if(myClass==NULL)
		return;
	Mat dst, dst_norm, dst_norm_scaled;
	 dst = Mat::zeros( myClass->src.size(), CV_32FC1 );

	  /// Detector parameters
	  int blockSize = 2;
	  int apertureSize = 3;
	  double k = 0.04;

	  /// Detecting corners
	  cv::cornerHarris( myClass->src_gray, dst, blockSize, apertureSize, k, BORDER_DEFAULT );

	  /// Normalizing
	  normalize( dst, dst_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
	  convertScaleAbs( dst_norm, dst_norm_scaled );

	  /// Drawing a circle around corners
	  for( int j = 0; j < dst_norm.rows ; j++ )
	     { for( int i = 0; i < dst_norm.cols; i++ )
	          {
	            if( (int) dst_norm.at<float>(j,i) > myClass->thresh )
	              {
	               circle( dst_norm_scaled, Point( i, j ), 5,  Scalar(0), 2, 8, 0 );
	              }
	          }
	     }
	  /// Showing the result
	  namedWindow( myClass->corners_window, CV_WINDOW_AUTOSIZE );
	  imshow( myClass->corners_window, dst_norm_scaled );
}
