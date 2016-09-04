/*
 * PersonRecognizer.h
 *
 *  Created on: 4 de set de 2016
 *      Author: xbtse
 */

#ifndef PERSONRECOGNIZER_H_
#define PERSONRECOGNIZER_H_

#define PERSON_LABEL 10 //some arbitrary label

#include <string>
#include "cv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/contrib/contrib.hpp"

using namespace std;
using namespace cv;

class PersonRecognizer {
public:
	PersonRecognizer(const vector<Mat> &imgs, int radius, int neighbors, int grid_x, int grid_y, double threshold);
	virtual ~PersonRecognizer();
	bool recognize(const Mat &face, double &confidence) const;
private:
    Ptr<FaceRecognizer> _model;
    Size _faceSize;
};

#endif /* PERSONRECOGNIZER_H_ */
