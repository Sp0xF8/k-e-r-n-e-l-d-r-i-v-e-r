#pragma once


#include "structs.h"

namespace Draw {

	void Line(Vector2 start, Vector2 end, Colour colour, float thickness = 1.0f);

	void Rect(Vector2 position, Vector2 position2, Colour colour, float thickness = 1.0f);
	void RectFilled(Vector2 position, Vector2 position2, Colour colour);

	void Circle(Vector2 position, float radius, Colour colour, float thickness = 1.0f, int segments = 32);

	void Text(Vector2 position, const char* text, Colour colour, bool center = false);
}
