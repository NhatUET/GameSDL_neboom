#pragma once
#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED
#include "commonFunc.h"
using namespace std;

class BaseObject {
public:
	BaseObject();
	~BaseObject();

	void SetRect(const int& x, const int& y) { rect.x = x; rect.y = y; }
	SDL_Rect GetRect() const { return rect; }
	SDL_Texture* GetObject() { return p_object; }

	virtual bool LoadImg(string path, SDL_Renderer* screen);
	void Render(SDL_Renderer *des, const SDL_Rect* clip);
	void Free();
protected:
	SDL_Texture* p_object;
	SDL_Rect rect;
};


#endif // BASEOBJECT_H_INCLUDED