#pragma once

#include <iostream>

namespace Satellite
{
	namespace Maths
	{
		struct vec3
		{
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);
			vec3(const vec3& other);

			vec3& add(const vec3& other);
			vec3& substract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

			friend vec3 operator+(vec3 left, const vec3& right);
			friend vec3 operator-(vec3 left, const vec3& right);
			friend vec3 operator/(vec3 left, const vec3& right);
			friend vec3 operator*(vec3 left, const vec3& right);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator/=(const vec3& other);
			vec3& operator*=(const vec3& other);

			// Implementing the output stream operator
			friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		};
	}
}