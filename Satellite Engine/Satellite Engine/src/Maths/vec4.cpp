#include "vec4.h"

namespace Satellite
{
	namespace Maths
	{
		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;			
			this->z = z;
			this->w = w;
		}
		vec4::vec4(const vec4& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
		}

		vec4& vec4::add(const vec4& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return *this;
		}
		vec4& vec4::substract(const vec4& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return *this;
		}
		vec4& vec4::multiply(const vec4& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
			return *this;
		}
		vec4& vec4::divide(const vec4& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
			return *this;
		}

		// It is important to think about whether or not passing left and right as reference or as value.
		// It changes the way we can use those methods, and we need to be careful and think about the design.
		// If we make the left vec be passed as a reference, it will be overwritten. If it is passed without &
		// (which means that it is passed as a value) then it will not be overwritten.
		vec4 operator+(vec4 left, const vec4& right)
		{
			return left.add(right);
		}
		vec4 operator-(vec4 left, const vec4& right)
		{
			return left.substract(right);
		}
		vec4 operator*(vec4 left, const vec4& right)
		{
			return left.multiply(right);
		}
		vec4 operator/(vec4 left, const vec4& right)
		{
			return left.divide(right);
		}

		bool vec4::operator==(const vec4& other) 
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}
		bool vec4::operator!=(const vec4& other)
		{
			return !(*this == other);
		}

		vec4& vec4::operator+=(const vec4& other)
		{
			return add(other);
		}
		vec4& vec4::operator-=(const vec4& other)
		{
			return substract(other);
		}
		vec4& vec4::operator/=(const vec4& other)
		{
			return divide(other);
		}
		vec4& vec4::operator*=(const vec4& other)
		{
			return multiply(other);
		}

		// This allows us to use std::cout with our vec4.
		std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			stream << "vec4: (" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
			return stream;
		}
	}
}