/*
 * FramesWriter.cpp
 *
 *  Created on: 4 de set de 2016
 *      Author: xbtse
 */

#include "FramesWriter.h"

FramesWriter::FramesWriter(const string vidPath, double fps, Size size, int fourcc): _f_size(size) {
	_vid.open(vidPath, fourcc, fps, _f_size, true);
}

FramesWriter::~FramesWriter() {
	_vid.release();
}

void FramesWriter::write(Mat& frame) {
	_vid << frame;
}
