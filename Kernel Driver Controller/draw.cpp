#include "draw.h"
#include "visualiser.h"
#include <fstream>
#include <vector>

namespace Draw {
	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayout = nullptr;

}



struct Vertex {
	float x, y;
	float r, g, b, a;
};

void Draw::Line(Vector2 start, Vector2 end, Colour colour, float thickness) {
	// Create a line mesh

	Vertex line[] = {
		{ start.x, start.y, colour.r, colour.g, colour.b, colour.a },
		{ end.x, end.y, colour.r, colour.g, colour.b, colour.a }
	};

	D3D11_BUFFER_DESC bufferDesc = { sizeof(line), D3D11_USAGE_DEFAULT, D3D11_BIND_VERTEX_BUFFER, 0, 0, 0 };

	D3D11_SUBRESOURCE_DATA data = { line, 0, 0 };

	

	Visualiser::pDevice->CreateBuffer(&bufferDesc, &data, &vertexBuffer);


	/// set the shaders

	std::ifstream vsFile("LineVertexShader.cso", std::ios::binary);
	std::ifstream psFile("LinePixelShader.cso", std::ios::binary);
	

	std::vector<char> vsData = { std::istreambuf_iterator<char>(vsFile), std::istreambuf_iterator<char>() };
	std::vector<char> psData = { std::istreambuf_iterator<char>(psFile), std::istreambuf_iterator<char>() };

	Visualiser::pDevice->CreateVertexShader(vsData.data(), vsData.size(), nullptr, &vertexShader);
	Visualiser::pDevice->CreatePixelShader(psData.data(), psData.size(), nullptr, &pixelShader);


	D3D11_INPUT_ELEMENT_DESC layout[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOUR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 8, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	Visualiser::pDevice->CreateInputLayout(layout, 2, vsData.data(), vsData.size(), &inputLayout);



	/// draw the line

	Visualiser::pDeviceContext->IASetInputLayout(inputLayout);

	Visualiser::pDeviceContext->VSSetShader(vertexShader, nullptr, 0);
	Visualiser::pDeviceContext->PSSetShader(pixelShader, nullptr, 0);


	UINT stride = sizeof(Vector2);
	UINT offset = 0;

	Visualiser::pDeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);

	Visualiser::pDeviceContext->Draw(2, 0);


}