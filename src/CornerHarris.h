/*
 * CornerHarris.h
 *
 *  Created on: Sep 13, 2014
 *      Author: aldo
 */

#ifndef CORNERHARRIS_H_
#define CORNERHARRIS_H_

#include <cv.h>
#include <highgui.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;
class CornerHarris{
protected:
	/// Global variables
	Mat src, src_gray;
	int thresh;
	int max_thresh;

	std::string source_window;
	std::string corners_window;

public:
	CornerHarris();
	void demo(char * filepath);
	static void on_trackbar(int newval, void * obj);


};




#endif /* CORNERHARRIS_H_ */
