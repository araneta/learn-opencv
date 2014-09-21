/*
 * LoadAndSaveImage.cpp
 *
 *  Created on: Sep 5, 2014
 *      Author: aldo
 */


#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <stdlib.h>

#include "CornerHarris.h"
#include "BlendingImages.h"
#include "BrightnessContrast.h"
/*
int main (int argc, char** argv){
	if(argc!=3){
		cout << "usage LoadAndSaveImage filepath outputpath" << endl;
		return -1;
	}
	char* imageName = argv[1];
	Mat image;
	image = imread(imageName,CV_LOAD_IMAGE_COLOR);
	if(!image.data){
		cout << "could not  load the image" << endl;
		return -1;
	}
	char* outputFile = argv[2];
	Mat gray_image;
	cvtColor(image, gray_image,CV_BGR2GRAY);

	imwrite(outputFile, gray_image);

	namedWindow(imageName, CV_WINDOW_AUTOSIZE);
	namedWindow("Gray Image", CV_WINDOW_AUTOSIZE);

	imshow(imageName,image);
	imshow("Gray Image",gray_image);

	waitKey(0);
	return 0;


}
*/
int main (int argc, char** argv){
	/*cornerharris corner detection*/
	/*
	char* imageName = argv[1];
	if(argc!=2){
		cout << "usage LoadAndSaveImage filepathx" << endl;
		return -1;
	}
	CornerHarris c;
	c.demo(imageName);
	*/
	// blending image
	/*if(argc!=4){
		cout << "usage LoadAndSaveImage image1 image2 alpha" << endl;
		return -1;
	}
	char* imageName = argv[1];
	char* imageName2 = argv[2];
	double alpha = atof(argv[3]);
	BlendingImages bi;
	bi.demo(imageName,imageName2,alpha);
	*/
	if(argc!=4){
		cout << "usage LoadAndSaveImage image1 alpha beta" << endl;
		return -1;
	}
	char* imageName = argv[1];
	double alpha = atof(argv[2]);
	int beta = atoi(argv[3]);
	BrightnessContrast bc;
	bc.demo(imageName,alpha,beta);
	return 0;
}
