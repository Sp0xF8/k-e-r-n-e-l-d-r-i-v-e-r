#include "Draw.h"


void Draw::Line(Vector2 start, Vector2 end, Colour colour, float thickness) {
	

	ImGui::GetBackgroundDrawList()->AddLine(ImVec2(start.x, start.y), ImVec2(end.x, end.y), colour.to_imu32(), thickness);
}
