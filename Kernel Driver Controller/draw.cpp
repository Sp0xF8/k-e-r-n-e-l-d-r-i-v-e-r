#include "draw.h"
#include "visualiser.h"


struct Vertex {
	float x, y;
	float r, g, b, a;
};

void Draw::Line(Vector2 start, Vector2 end, Colour colour, float thickness) {
	// Create a line

	Vertex line[] = {
		{ start.x, start.y, colour.r, colour.g, colour.b, colour.a },
		{ end.x, end.y, colour.r, colour.g, colour.b, colour.a }
	};

	D3D11_BUFFER_DESC bufferDesc = { sizeof(line), D3D11_USAGE_DEFAULT, D3D11_BIND_VERTEX_BUFFER, 0, 0, 0 };

	D3D11_SUBRESOURCE_DATA data = { line, 0, 0 };

	ID3D11Buffer* vertexBuffer = nullptr;

	Visualiser::pDevice->CreateBuffer(&bufferDesc, &data, &vertexBuffer);


	Visualiser::pDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	UINT stride = sizeof(Vector2);
	UINT offset = 0;

	Visualiser::pDeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

	Visualiser::pDeviceContext->Draw(2, 0);

	vertexBuffer->Release();




}