#include "rocket.h"

rocket::rocket()
{
	rect.x = SCR_WIDTH * 0.5;
	rect.y = 0;
	rect.w = w_rocket;
	rect.h = h_rocket;

	x_val = 0;
	y_val = 0;
}

rocket::~rocket()
{

}
void rocket::handle_move(const int &x_border, const int &y_border)
{
	rect.y += y_val;
	if (rect.y > SCR_HEIGHT)
	{
		rect.y = 0;
		int rand_x = rand() % 400;
		if (rand_x > SCR_WIDTH - 100)
		{
			rand_x = SCR_WIDTH * 0.3;
		}
		rect.x = rand_x;
	}

}
void rocket::handle_action(SDL_Event events)
{

}