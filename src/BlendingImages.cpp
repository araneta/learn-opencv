/*
 * BlendingImages.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: aldo
 */
#include "BlendingImages.h"

void BlendingImages::demo(char * filename1,char * filename2, double inputAlpha){
	 double alpha = 0.5;
	 double beta;

	 Mat src1, src2, dst;

	 /// We use the alpha provided by the user if it is between 0 and 1
	 if( inputAlpha >= 0.0 && inputAlpha <= 1.0 )
	 {
		 alpha = inputAlpha;
	 }

	 /// Read image ( same size, same type )
	 src1 = imread(filename1);
	 src2 = imread(filename2);

	 if( !src1.data ) {
		 printf("Error loading src1 \n");
		 return;
	 }
	 if( !src2.data ) {
		 printf("Error loading src2 \n");
		 return;
	 }

	 /// Create Windows
	 namedWindow("Linear Blend", 1);

	 beta = ( 1.0 - alpha );
	 addWeighted( src1, alpha, src2, beta, 0.0, dst);

	 imshow( "Linear Blend", dst );

	 waitKey(0);
}



