#include "vec2.h"

namespace Satellite
{
	namespace Maths
	{
		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}
		vec2::vec2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}
		vec2::vec2(const vec2& other)
		{
			this->x = other.x;
			this->y = other.y;
		}

		vec2& vec2::add(const vec2& other)
		{
			this->x += other.x;
			this->y += other.y;
			return *this;
		}
		vec2& vec2::substract(const vec2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return *this;
		}
		vec2& vec2::multiply(const vec2& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			return *this;
		}
		vec2& vec2::divide(const vec2& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			return *this;
		}

		// It is important to think about whether or not passing left and right as reference or as value.
		// It changes the way we can use those methods, and we need to be careful and think about the design.
		// If we make the left vec be passed as a reference, it will be overwritten. If it is passed without &
		// (which means that it is passed as a value) then it will not be overwritten.
		vec2 operator+(vec2 left, const vec2& right)
		{
			return left.add(right);
		}
		vec2 operator-(vec2 left, const vec2& right)
		{
			return left.substract(right);
		}
		vec2 operator*(vec2 left, const vec2& right)
		{
			return left.multiply(right);
		}
		vec2 operator/(vec2 left, const vec2& right)
		{
			return left.divide(right);
		}

		bool vec2::operator==(const vec2& other) 
		{
			return x == other.x && y == other.y;
		}
		bool vec2::operator!=(const vec2& other)
		{
			return !(*this == other);
		}

		vec2& vec2::operator+=(const vec2& other)
		{
			return add(other);
		}
		vec2& vec2::operator-=(const vec2& other)
		{
			return substract(other);
		}
		vec2& vec2::operator/=(const vec2& other)
		{
			return divide(other);
		}
		vec2& vec2::operator*=(const vec2& other)
		{
			return multiply(other);
		}

		// This allows us to use std::cout with our vec2.
		std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << "vec2: (" << vector.x << ", " << vector.y << ")";
			return stream;
		}
	}
}