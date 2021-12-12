#include "vec3.h"

namespace Satellite
{
	namespace Maths
	{
		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}
		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		vec3::vec3(const vec3& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
		}

		vec3& vec3::add(const vec3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}
		vec3& vec3::substract(const vec3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}
		vec3& vec3::multiply(const vec3& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return *this;
		}
		vec3& vec3::divide(const vec3& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return *this;
		}

		// It is important to think about whether or not passing left and right as reference or as value.
		// It changes the way we can use those methods, and we need to be careful and think about the design.
		// If we make the left vec be passed as a reference, it will be overwritten. If it is passed without &
		// (which means that it is passed as a value) then it will not be overwritten.
		vec3 operator+(vec3 left, const vec3& right)
		{
			return left.add(right);
		}
		vec3 operator-(vec3 left, const vec3& right)
		{
			return left.substract(right);
		}
		vec3 operator*(vec3 left, const vec3& right)
		{
			return left.multiply(right);
		}
		vec3 operator/(vec3 left, const vec3& right)
		{
			return left.divide(right);
		}

		bool vec3::operator==(const vec3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}
		bool vec3::operator!=(const vec3& other)
		{
			return !(*this == other);
		}

		vec3& vec3::operator+=(const vec3& other)
		{
			return add(other);
		}
		vec3& vec3::operator-=(const vec3& other)
		{
			return substract(other);
		}
		vec3& vec3::operator/=(const vec3& other)
		{
			return divide(other);
		}
		vec3& vec3::operator*=(const vec3& other)
		{
			return multiply(other);
		}

		// This allows us to use std::cout with our vec2.
		std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			stream << "vec3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}
	}
}