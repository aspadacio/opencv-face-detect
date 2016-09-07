/*
 * FaceDetector.cpp
 *
 *  Created on: 4 de set de 2016
 *      Author: xbtse
 */

#include "FaceDetector.h"

//Constructor
FaceDetector::FaceDetector(const string& cascadePath, double scaleFactor,
		int minNeighbors, double minSizeRatio, double maxSizeRatio):
		_scaleFactor(scaleFactor), _minNeighbors(minNeighbors), _minSizeRatio(minSizeRatio), _maxSizeRatio(maxSizeRatio) {
	_cascade.load(cascadePath);
}

//Destructor
FaceDetector::~FaceDetector() {}

void FaceDetector::findFacesInImage(const Mat& img, vector<Rect>& res) {
	Mat tmp;
	int width  = img.size().width,
		height = img.size().height;
	Size minScaleSize = Size(_minSizeRatio  * width, _minSizeRatio  * height),
		 maxScaleSize = Size(_maxSizeRatio  * width, _maxSizeRatio  * height);

	//convert the image to grayscale and normalize histogram:
	cvtColor(img, tmp, CV_BGR2GRAY);
	equalizeHist(tmp, tmp);

	//clear the vector:
	res.clear();

	//detect faces:
	_cascade.detectMultiScale(tmp, res, _scaleFactor, _minNeighbors, 0, minScaleSize, maxScaleSize);
}
