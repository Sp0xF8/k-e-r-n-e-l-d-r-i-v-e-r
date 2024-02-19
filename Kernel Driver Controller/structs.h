#pragma once

#include "Imgui/imgui.h"

#include <numbers>
#include <cmath>
#include "RepeatableData.h"

struct view_matrix_t {
	float* operator[](int index) {
		return m[index];
	}

	float m[4][4];
};



struct Colour {
	float r, g, b, a;

	constexpr Colour(
		const float r = 0.0f,
		const float g = 0.0f,
		const float b = 0.0f,
		const float a = 0.0f) noexcept :
		r(r), g(g), b(b), a(a) { }


	Colour from_float(const float r, const float g, const float b, const float a) const noexcept {
		return Colour(r, g, b, a);
	}

	
	ImU32 to_imu32() const noexcept {
		return IM_COL32(static_cast<int>(r * 255), static_cast<int>(g * 255), static_cast<int>(b * 255), static_cast<int>(a * 255));
	}

};


struct Vector2 {

	constexpr Vector2(
		const float x = 0.0f,
		const float y = 0.0f) noexcept :
		x(x), y(y) { }

	constexpr const Vector2 operator-(const Vector2& other) const noexcept {
		return Vector2(x - other.x, y - other.y);
	}

	constexpr const Vector2 operator+(const Vector2& other) const noexcept {
		return Vector2(x + other.x, y + other.y);
	}

	constexpr const Vector2 operator*(const float other) const noexcept {
		return Vector2(x * other, y * other);
	}

	constexpr const Vector2 operator/(const float other) const noexcept {
		return Vector2(x / other, y / other);
	}

	float x, y;
};




struct Vector3 {
	constexpr Vector3(
		const float x = 0.0f,
		const float y = 0.0f,
		const float z = 0.0f) noexcept :
		x(x), y(y), z(z) { }


	//converts 3d vector to 2d vector
	constexpr Vector2 to_vector2() const noexcept {
		return Vector2(x, y);
	}

	constexpr const Vector3 operator-(const Vector3& other) const noexcept {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	constexpr const Vector3 operator+(const Vector3& other) const noexcept {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	constexpr const Vector3 operator*(const float other) const noexcept {
		return Vector3(x * other, y * other, z * other);
	}

	constexpr const Vector3 operator/(const float other) const noexcept {
		return Vector3(x / other, y / other, z / other);
	}

	Vector3 WTS(view_matrix_t matrix) {

		float _w = matrix[3][0] * x + matrix[3][1] * y + matrix[3][2] * z + matrix[3][3];

		if (_w < 0.01f)
			return { -1, -1, 0 };

		float _x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
		float _y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];


		_x = (Data::screen_width / 2) * (1 + _x / _w);
		_y = (Data::screen_height / 2) * (1 - _y / _w);

		



		return { _x, _y, _w };
	}

	float x, y, z;
};


// struct matrix 4x2 floats
struct matrix4x2_t {
	float m[4][2];

	Vector3 WTS(view_matrix_t matrix) {


		float w = matrix[3][0] * m[0][0] + matrix[3][1] * m[1][0] + matrix[3][2] * m[2][0] + matrix[3][3];

		if (w < 0.01f)
			return { -1, -1, 0 };

		float x = matrix[0][0] * m[0][0] + matrix[0][1] * m[1][0] + matrix[0][2] * m[2][0] + matrix[0][3];
		float y = matrix[1][0] * m[0][0] + matrix[1][1] * m[1][0] + matrix[1][2] * m[2][0] + matrix[1][3];


		x = (Data::screen_width / 2) * (1 + x / w);
		y = (Data::screen_height / 2) * (1 - y / w);




	
		return { x, y, w };
	}
};

// bones 

struct Bones {
	matrix4x2_t bones[104];
};


