#pragma once
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include<vector>
#include "commonFunc.h"
#include "baseObject.h"
#include "rocket.h"
using namespace std;
const int w_plane = 80; // chieu rong cua may bay
const int h_plane = 80; // chieu cao cua may bay

using namespace std;

class player :public BaseObject
{
public:
	player();
	~player();

	//di chuyen
	void handle_move(SDL_Event events);
	bool LoadImg(string path, SDL_Renderer* screen);
	bool Check_Collision(const SDL_Rect& rocket);

private:

	int x_val;
	int y_val;
};
#endif // PLAYER_H_INCLUDED