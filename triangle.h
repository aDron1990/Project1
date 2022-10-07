#pragma once

#include "point.h"

namespace mymath::geometry
{
	template <int dimention>
	class triangle
	{
	private:

		std::array<point<dimention>, 3> points_;

	public:

		triangle(point<dimention> p1, point<dimention> p2, point<dimention> p3) : points_(p1, p2, p3) {}

		float getSquare() const
		{
			return 0;
		}
	};
}