#include "mat4.h"

namespace Satellite
{
	namespace Maths
	{
		mat4::mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}
		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		// We are going to use Column Major Ordering because it is the way OpenGL does it.
		// elements[row + col * size] = elements[row + col * 4]
		// If we wanted to use Row Major Ordering, it would be: elements[col + row * size]

		mat4& mat4::multiply(const mat4& other)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;

					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}

					elements[x + y * 4];
				}
			}

			return *this;
		}

		mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

		mat4& mat4::operator*=(const mat4& other)
		{
			return multiply(other);
		}

		mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = 2 / (right - left);
			result.elements[1 + 1 * 4] = 2 / (top - bottom);
			result.elements[2 + 2 * 4] = -2 / (far - near);

			result.elements[0 + 3 * 4] = -((right + left) / (right - left));
			result.elements[1 + 3 * 4] = -((top + bottom) / (top - bottom));
			result.elements[2 + 3 * 4] = -((far + near) / (far - near));

			return result;
		}

		mat4 mat4::perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 result(1.0f);

			float t = tan(toRadians(fov * 0.5f));

			result.elements[0 + 0 * 4] = 1 / (aspectRatio * t);
			result.elements[1 + 1 * 4] = 1 / t;
			result.elements[2 + 2 * 4] = - ((far + near) / (far - near));
			result.elements[3 + 2 * 4] = -1.0f;
			result.elements[2 + 3 * 4] = -((2 * far * near) / (far - near));
			result.elements[3 + 3 * 4] = 0.0f;

			return result;
		}

		mat4 mat4::translate(const vec3& translation)
		{
			mat4 result(1.0f);

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;

			return result;
		}

		mat4 mat4::rotate(float angle, const vec3& axis)
		{
			mat4 result(1.0f);

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[1 + 0 * 4] = y * x * omc + z * s;
			result.elements[2 + 0 * 4] = x * z * omc - y * s;

			result.elements[0 + 1 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[2 + 1 * 4] = y * z * omc + x * s;

			result.elements[0 + 2 * 4] = x * z * omc + y * s;
			result.elements[1 + 2 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}

		mat4 mat4::scale(const vec3& scale)
		{
			mat4 result(1.0f);

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}
	}
}