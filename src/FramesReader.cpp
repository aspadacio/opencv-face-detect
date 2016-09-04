/*
 * FramesReader.cpp
 *
 *  Created on: 4 de set de 2016
 *      Author: xbtse
 */

#include "FramesReader.h"

FramesReader::FramesReader(const string& vidPath, int startFrame, int endFrame, int delta):
_endFrame(endFrame), _delta(delta) {
	_vid.open(vidPath);
	if (startFrame != -1){
		_vid.set(CV_CAP_PROP_POS_FRAMES, startFrame);
	}
}

FramesReader::~FramesReader() {
	 _vid.release();
}

//to obtain the next frame in the video
bool FramesReader::getNext(Mat& img) {
	if (_delta != -1){
		_vid.set(CV_CAP_PROP_POS_FRAMES, _vid.get(CV_CAP_PROP_POS_FRAMES) + _delta);
	}
	if (_endFrame != -1 && _vid.get(CV_CAP_PROP_POS_FRAMES) > _endFrame){
		return false;
	}
	return _vid.read(img);
}

//to obtain the size of the frame (in pixels)
Size FramesReader::getSize() {
	return Size(
				_vid.get(CV_CAP_PROP_FRAME_WIDTH),
				_vid.get(CV_CAP_PROP_FRAME_HEIGHT)
			);
}
