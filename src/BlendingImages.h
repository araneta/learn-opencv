/*
 * BlendingImages.h
 *
 *  Created on: Sep 13, 2014
 *      Author: aldo
 */

#ifndef BLENDINGIMAGES_H_
#define BLENDINGIMAGES_H_

#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;

class BlendingImages{
public:
	void demo(char * filename1,char * filename2, double inputAlpha);
};


#endif /* BLENDINGIMAGES_H_ */
