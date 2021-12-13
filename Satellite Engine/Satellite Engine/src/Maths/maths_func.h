#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace Satellite
{
	namespace Maths
	{
		inline float toRadians(float degrees)
		{
			return degrees * (float)M_PI / 180.0f;
		}

		inline float toDegrees(float radians)
		{
			return radians * 180.0f / (float)M_PI;
		}
	}
}