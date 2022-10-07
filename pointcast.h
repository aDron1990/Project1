#pragma once

#include "line.h"
#include "vec.h"

namespace mymath::geometry
{
	template <int dimention>
	class castinfo
	{
	public:
		bool is_hit;
		point<dimention> hit_point;
	};

	template<int dimention> castinfo<dimention> pointcast(const point<dimention> startpoint, const vec<dimention> direction, const line<dimention> target);
	castinfo<2> pointcast(const point2 startpoint, const vec2 direction, const line<2> target)
	{
		vec2 ray = (direction + startpoint.to_vec()).normalized();
		ray *= std::max((startpoint.to_vec() - target.p1.to_vec()).magnitude(), (startpoint.to_vec() - target.p2.to_vec()).magnitude());
		line l{ startpoint, ray.to_point() };
		line<2>::linesCross cross = l.cross(target);

		if (cross.type == line<2>::linesCross::crosstype::Inside || cross.type == line<2>::linesCross::crosstype::OutOfMe)
		{
			return castinfo{ true, cross.cross_point };
		}
		
		return castinfo{ false, point2() };
	}
}