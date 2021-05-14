#pragma once
#ifndef ROCKET_H_INCLUDED
#define ROCKET_H_INCLUDED
#include "commonFunc.h"
#include "baseObject.h"

#define w_rocket 45
#define h_rocket 61
using namespace std;


class rocket :public BaseObject
{
public:
	rocket();
	~rocket();

	void handle_move(const int &x_border, const int &y_border);
	void handle_action(SDL_Event events);

	void set_x_val(const int &val) { x_val = val; }
	void set_y_val(const int &val) { y_val = val; }
	int get_x_val()const { return x_val; }
	int get_y_val()const { return y_val; }
private:
	double x_val;
	double y_val;

};


#endif // ROCKET_H_INCLUDED