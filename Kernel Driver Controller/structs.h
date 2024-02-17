#pragma once

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

	
	float* ReturnFloats() {
		float result[4] = { r, g, b, a };
		return result;
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

		float _x = x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2] + matrix[0][3];
		float _y = x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2] + matrix[1][3];

		float w = x * matrix[3][0] + y * matrix[3][1] + z * matrix[3][2] + matrix[3][3];

		float inv_w = 1.0f / w;

		_x *= inv_w;
		_y *= inv_w;

		float x = Data::screen_width / 2;
		float y = Data::screen_height / 2;

		x += 0.5f * _x * Data::screen_width + 0.5f;

		y -= 0.5f * _y * Data::screen_height + 0.5f;

		return { x, y, w };
	}

	float x, y, z;
};