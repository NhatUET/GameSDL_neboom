/* game né bom
												HỌ TÊN: VŨ MINH NHẬT
												MSSV: 20021407                               */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <ctime>
#include "commonFunc.h"
#include "baseObject.h"
#include "player.h"
#include "rocket.h"
#include "text.h"
///////////////////// /////////////

BaseObject g_background;
BaseObject g_background_after;
player plane;
rocket* p_rocket = new rocket();
rocket* p1_rocket = new rocket();
rocket* p2_rocket = new rocket();
rocket* p3_rocket = new rocket();
TTF_Font* font_time;
TextObject time_game;

/////////////////////////////////////

bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0) {
		return false;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	g_window = SDL_CreateWindow("Game Ne BOOM", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN);

	if (g_window == NULL)
	{
		success = false;
	}
	else
	{
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL)
		{
			success = false;
		}
		else
		{
			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags))
			{
				success = false;
			}
		}
	}
	TTF_Init();
	font_time = TTF_OpenFont("Font//dlxfont_.ttf", 12);
	return success;
};

void LoadBackground()
{	
	g_background.LoadImg("img//bg0.JPG", g_screen);
	g_background_after.LoadImg("img//bg0.JPG", g_screen);
	g_background_after.SetRect(0, -1200);
	
}

void load_player()
{
	plane.SetRect(SCR_WIDTH / 2, SCR_HEIGHT - 100);
	plane.LoadImg("img//plane.PNG", g_screen);
}

void load_rocket()
{
	p_rocket->LoadImg("img//rocket.PNG", g_screen);
	p1_rocket->LoadImg("img//bullet1.PNG", g_screen);
	p2_rocket->LoadImg("img//plane_bullet.PNG", g_screen);
	p3_rocket->LoadImg("img//rocket.PNG", g_screen);
	p_rocket->SetRect(SCR_WIDTH*0.5, 0);
	p1_rocket->SetRect(SCR_WIDTH*0.9, 0);
	p2_rocket->SetRect(SCR_WIDTH*0.2, 0);
	p3_rocket->SetRect(SCR_WIDTH*0.1, 0);
	//p_rocket->set_x_val(0);
	p_rocket->set_y_val(2);
	p1_rocket->set_y_val(4);
	p2_rocket->set_y_val(5);
	p3_rocket->set_y_val(3);
}
void close()
{
	g_background.Free();

	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;

	SDL_DestroyWindow(g_window);
	g_window = NULL;

	IMG_Quit();
	SDL_Quit();
}
int main(int argc, char* argv[])
{
	if (InitData() == false)
		return -1;
	LoadBackground();
	load_player();
	load_rocket();

	bool is_quit = false;
	while (!is_quit) {
		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
			}
			//// plane
			plane.handle_move(g_event);

			////// rocket
			p_rocket->handle_action(g_event);
			p1_rocket->handle_action(g_event);
			p2_rocket->handle_action(g_event);
			p3_rocket->handle_action(g_event);

			//// colision
			bool is_cls = plane.Check_Collision(p_rocket->GetRect());
			bool is_cls1 = plane.Check_Collision(p1_rocket->GetRect());
			bool is_cls2 = plane.Check_Collision(p2_rocket->GetRect());
			bool is_cls3 = plane.Check_Collision(p3_rocket->GetRect());

			if (is_cls == true || is_cls1 == true || is_cls2 == true || is_cls3 == true)
			{
				if (MessageBox(NULL, L"GAME OVER!", L"Information", MB_OK) == IDOK) {
					is_quit = false;
					return 1;
				}
			}
		}
		// render

		SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(g_screen);

		g_background.SetRect(0, g_background.GetRect().y + 1);
		g_background_after.SetRect(0, g_background_after.GetRect().y + 1);

		if (g_background.GetRect().y > SCR_HEIGHT) {
			g_background.SetRect(0, -1200);
		}
		if (g_background_after.GetRect().y > SCR_HEIGHT) {
			g_background_after.SetRect(0, -1200);
		}

		//////rocket init random

		int rand_x = rand() % (SCR_WIDTH + 100);
		if (rand_x > SCR_WIDTH - 100)
		{
			rand_x = SCR_WIDTH * 0.3;
		}
		p_rocket->handle_move(rand_x, SCR_HEIGHT);
		p1_rocket->handle_move(rand_x + 100, SCR_HEIGHT);
		p2_rocket->handle_move(rand_x + 200, SCR_HEIGHT);
		p3_rocket->handle_move(rand_x + 300, SCR_HEIGHT);

		// show ///////////////

		g_background.Render(g_screen, NULL);
		g_background_after.Render(g_screen, NULL);

		plane.Render(g_screen, NULL);
		p_rocket->Render(g_screen, NULL);
		p1_rocket->Render(g_screen, NULL);
		p2_rocket->Render(g_screen, NULL);
		p3_rocket->Render(g_screen, NULL);
		/////////////////////
		Uint32 time_val = SDL_GetTicks() / 1000;
		string str_time = "SCORE: " + to_string(time_val);
		time_game.SetText(str_time);
		time_game.LoadFromRenderText(font_time, g_screen);
		time_game.RenderText(g_screen, SCR_WIDTH - 150, 15);
		/////////////////////
		SDL_RenderPresent(g_screen);
		SDL_Delay(8);
	}
	close();
	return 0;
}