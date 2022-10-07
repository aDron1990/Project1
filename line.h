#pragma once

#include "point.h"

namespace mymath::geometry
{
	template <int dimention>
	class line
	{
	public:

		class linesCross
		{   
		public:

			enum class crosstype
			{
				NoCross = 0,
				Inside = 1,
				OutOfMe = 2,
				OutTheOther = 3,
				OutTheBoth = 4,
			};

			crosstype type;
			point<dimention> cross_point;
		};

		point<dimention> p1;
		point<dimention> p2;

		line(point<dimention> p1_, point<dimention> p2_) : p1(p1_), p2(p2_) {}

		linesCross cross(const line& other);
	};
}