#include "line.h"

mymath::geometry::line<2>::linesCross mymath::geometry::line<2>::cross(const line<2>& other)
{
	point2 crossPoint;
	float n;
	if (p2[1] - p1[1] != 0)
	{
		float q = (p2[0] - p1[0]) / (p1[1] - p2[1]);
		float sn = (other.p1[0] - other.p2[0]) + (other.p1[1] - other.p2[1]) * q;
		if (!sn) return linesCross{ linesCross::crosstype::NoCross };

		float fn = (other.p1[0] - p1[0]) + (other.p1[1] - p1[1]) * q;
		n = fn / sn;
	}
	else
	{
		if (!(other.p1[1] - other.p2[1])) return linesCross{ linesCross::crosstype::NoCross };
		n = (other.p1[1] - p1[1]) / (other.p1[1] - other.p2[1]);
	}

	crossPoint[0] = other.p1[0] + (other.p2[0] - other.p1[0]) * n;
	crossPoint[1] = other.p1[1] + (other.p2[1] - other.p1[1]) * n;

	if (((crossPoint[0] >= std::min(p1[0], p2[0]) && crossPoint[0] <= std::max(p1[0], p2[0])) &&
		 (crossPoint[1] >= std::min(p1[1], p2[1]) && crossPoint[1] <= std::max(p1[1], p2[1]))) &&
		((crossPoint[0] >= std::min(other.p1[0], other.p2[0]) && crossPoint[0] <= std::max(other.p1[0], other.p2[0])) &&
		 (crossPoint[1] >= std::min(other.p1[1], other.p2[1]) && crossPoint[1] <= std::max(other.p1[1], other.p2[1]))))
		return linesCross{ linesCross::crosstype::Inside, crossPoint };
	else if ((crossPoint[0] >= std::min(p1[0], p2[0]) && crossPoint[0] <= std::max(p1[0], p2[0])) &&
			 (crossPoint[1] >= std::min(p1[1], p2[1]) && crossPoint[1] <= std::max(p1[1], p2[1])))
		return linesCross{ linesCross::crosstype::OutTheOther, crossPoint };
	else if ((crossPoint[0] >= std::min(other.p1[0], other.p2[0]) && crossPoint[0] <= std::max(other.p1[0], other.p2[0])) &&
			 (crossPoint[1] >= std::min(other.p1[1], other.p2[1]) && crossPoint[1] <= std::max(other.p1[1], other.p2[1])))
		return linesCross{ linesCross::crosstype::OutOfMe, crossPoint };

	return linesCross{ linesCross::crosstype::OutTheBoth, crossPoint };
}