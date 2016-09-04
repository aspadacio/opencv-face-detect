/*
 * FramesReader.h
 *
 *  Created on: 4 de set de 2016
 *      Author: xbtse
 */

#ifndef FRAMESREADER_H_
#define FRAMESREADER_H_

#include <string>
#include "cv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class FramesReader {
public:
    FramesReader(const string &vidPath, int startFrame, int endFrame, int delta);
    virtual ~FramesReader();
    bool getNext(Mat &frame);
    Size getSize();
private:
    VideoCapture _vid;
    int _endFrame,
		_delta;
};

#endif /* FRAMESREADER_H_ */
