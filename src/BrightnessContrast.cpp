/*
 * BrightnessContrast.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: aldo
 */

#include "BrightnessContrast.h"

BrightnessContrast::BrightnessContrast() {
	// TODO Auto-generated constructor stub

}

BrightnessContrast::~BrightnessContrast() {
	// TODO Auto-generated destructor stub
}
void BrightnessContrast::help(){
	 std::cout<<" Basic Linear Transforms "<<std::endl;
	 std::cout<<"-------------------------"<<std::endl;
	 std::cout<<"* Enter the alpha value [1.0-3.0]: "<<std::endl;
}
void BrightnessContrast::demo(char * filename, double alpha, int beta){
	Mat image = imread(filename);
	Mat new_image = Mat::zeros(image.size(), image.type());
	/// Do the operation new_image(i,j) = alpha*image(i,j) + beta
	for(int y=0;y<image.rows;y++){
		for(int x=0;x<image.cols;x++){
			//for each chanel rgb
			for(int c=0;c<3;c++){
				new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y,x)[c])+beta);
			}
		}
	}
	//show stuff
	imshow("original image",image);
	imshow("new image", new_image);
	waitKey(0);
}
