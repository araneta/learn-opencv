/*
 * BrightnessContrast.h
 *
 *  Created on: Sep 21, 2014
 *      Author: aldo
 */

#ifndef BRIGHTNESSCONTRAST_H_
#define BRIGHTNESSCONTRAST_H_

#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;

class BrightnessContrast {
protected:
	double alpha;//simple contrast control (gain) alpha value [1.0-3.0]
	int beta;//simple brightness control (bias) beta value [0-100]
public:
	BrightnessContrast();
	virtual ~BrightnessContrast();
	void demo(char * filename,double alpha, int beta);
	void help();
};

#endif /* BRIGHTNESSCONTRAST_H_ */
