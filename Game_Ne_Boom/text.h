#pragma once
#include "commonFunc.h"
#include "BaseObject.h"

class TextObject {
	string str_val;
	SDL_Color text_color;
	SDL_Texture* texture;
	int width;
	int height;
public:
	TextObject();
	~TextObject();

	enum TextColor { RED_TEXT, WHITE_TEXT, BlACK_TEXT };

	void LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
	void Free();

	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void SetColor(int type);
	void RenderText(SDL_Renderer* screen,
		int x_pos, int y_pos,
		SDL_Rect* clip = NULL,
		double angle = 0.0,
		SDL_Point* center = NULL,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	int GetWidth() const { return width; }
	int GetHeight() const { return height; }
	void SetText(const string& _text) { str_val = _text; }
	string GetText() const { return str_val; }
};