#pragma once
#include "structs.h"

namespace Draw {


	void Line(Vector2 start, Vector2 end, Colour colour, float thickness = 1.0f);
	void Box(Vector2 start, Vector2 end, Colour colour, float thickness = 1.0f);
	void FilledBox(Vector2 start, Vector2 end, Colour colour);

	void Circle(Vector2 position, float radius, Colour colour, float thickness = 1.0f);
	void FilledCircle(Vector2 position, float radius, Colour colour);

	void Text(Vector2 position, const char* text, Colour colour, float size = 12.0f);


}