#pragma once

#include "Maths.h"

namespace Satellite
{
	namespace Maths
	{
		struct mat4
		{
			/* I FUCKING DON'T KNOW WHY BUT I CANNOT USE UNIONS, BECAUSE WHEN I DO MY mat4.cpp file stops working.
			*  From what I've been able to see, I get a problem in the constructor mat4(float diagonal), because all the
			*  functions that give an error when adding the union give the error in the return, being the return a mat4(float 1.0f).
			union
			{
				float elements[16];

				struct
				{
					vec4 columns[4];
				};
			};
			*/

			float elements[16];

			mat4();
			mat4(float diagonal);

			// THIS SHOULDN'T EXIST, WE CANNOT MODIFY THE MATRIX BECAUSE WE ARE MAKING A COPY, BUT
			// UNIONS DON'T SEEM TO WORK, I DON'T KNOW WHY
			vec4 getColumn(int index)
			{
				index *= 4;
				return vec4(elements[index], elements[index + 1], elements[index + 2], elements[index + 3]);
			}

			static mat4 identity();

			mat4& multiply(const mat4& other);
			friend mat4 operator*(mat4 left, const mat4& right);
			mat4& operator*=(const mat4& other);

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);
		};
	}
}