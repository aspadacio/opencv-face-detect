/*
 * FramesWriter.h
 *
 *  Created on: 4 de set de 2016
 *      Author: xbtse
 */

#ifndef FRAMESWRITER_H_
#define FRAMESWRITER_H_

#include <string>
#include "cv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class FramesWriter
{
public:
    FramesWriter(const string vidPath, double fps, Size size, int fourcc);
    virtual ~FramesWriter();
    void write(Mat &frame);
private:
    VideoWriter _vid;
    Size _f_size;
};

#endif /* FRAMESWRITER_H_ */
