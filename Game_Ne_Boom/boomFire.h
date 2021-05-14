#pragma once

#include "commonFunc.h"
#include "BaseObject.h"


#define NUM_FRAME_EXP 8

const int EXP_WIDTH = 150;
const int EXP_HEIGHT = 165;

class Fire : public BaseObject {
	int frame;
	SDL_Rect frame_clip[NUM_FRAME_EXP];
public:
	Fire();
	~Fire();
	void set_clip();
	void set_frame(const int& _frame) { frame = _frame; }
	void Show(SDL_Renderer* screen);
};