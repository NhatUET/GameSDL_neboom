#pragma once
#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED

#include<windows.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//cai dat man hinh
const int SCR_HEIGHT = 780;
const int SCR_WIDTH = 500;
const int SCR_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 255;

#endif // COMMONFUNC_H_INCLUDED