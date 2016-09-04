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
}
