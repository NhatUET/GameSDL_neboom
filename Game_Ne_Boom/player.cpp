#include "player.h"
#include "rocket.h"
player::player() {
	rect.x = 0;
	rect.y = 0;
	rect.w = w_plane;
	rect.h = h_plane;


	x_val = 50; // van toc theo chieu x
	y_val = 50; // van toc theo chieu y
}

player::~player() {

}
bool player::LoadImg(string path, SDL_Renderer* screen)
{
	bool ret = BaseObject::LoadImg(path, screen);
	return ret;
}
void player::handle_move(SDL_Event events) {
	// keyboard
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			rect.y -= y_val;
			if (rect.y - h_plane < 0) rect.y -= y_val; // khong vuot qua goc tren
			break;

		case SDLK_DOWN:
			rect.y += y_val;
			if (rect.y + h_plane > SCR_HEIGHT) rect.y -= y_val; // khong vuot qua goc duoi
			break;

		case SDLK_LEFT:
			rect.x -= x_val;
			if (rect.x < 0) rect.x += x_val; // khong vuot qua goc trai
			break;

		case SDLK_RIGHT:
			rect.x += x_val;
			if (rect.x + w_plane > SCR_WIDTH) rect.x -= x_val; // khong vuot qua goc phai
			break;
		default:
			break;
		}
	}
}

bool player::Check_Collision(const SDL_Rect& rocket) {
	// plane
	int left_Plane = rect.x;
	int right_Plane = rect.x + rect.w;
	int top_Plane = rect.y;
	int bottom_Plane = rect.y + rect.h;

	// rocket
	int left_Rocket = rocket.x;
	int right_Rocket = rocket.x + rocket.w;
	int top_Rocket = rocket.y;
	int bottom_Rocket = rocket.y + rocket.h;


	if (right_Plane > left_Rocket && right_Plane < right_Rocket) {
		if (bottom_Plane > top_Rocket && bottom_Plane < bottom_Rocket)
			return true;
		if (top_Plane > top_Rocket && top_Plane < bottom_Rocket)
			return true;
	}

	if (left_Plane > left_Rocket && left_Plane < right_Rocket) {
		if (bottom_Plane > top_Rocket && bottom_Plane < bottom_Rocket)
			return true;
		if (top_Plane > top_Rocket && top_Plane < bottom_Rocket)
			return true;
	}


	if (right_Rocket > left_Plane && right_Rocket < right_Plane) {
		if (bottom_Rocket > top_Plane && bottom_Rocket < bottom_Plane)
			return true;
		if (top_Rocket > top_Plane && top_Rocket < bottom_Plane)
			return true;
	}

	if (left_Rocket > left_Plane && left_Rocket < right_Plane) {
		if (bottom_Rocket > top_Plane && bottom_Rocket < bottom_Plane)
			return true;
		if (top_Rocket > top_Plane && top_Rocket < bottom_Plane)
			return true;
	}


	if (left_Plane == left_Rocket && right_Plane == right_Rocket && top_Plane == top_Rocket && bottom_Plane == bottom_Rocket)
		return true;

	return false;
}