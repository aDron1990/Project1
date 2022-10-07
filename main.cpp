#include "point.h"
#include "line.h"
#include "triangle.h"
#include "vec.h"
#include "pointcast.h"
#include "polygon.h"

#include <iostream>

using namespace mymath;
using namespace mymath::geometry;

int main()
{
	point2 p1{ {5, 1} };
	point2 p2{ {4, 4} };
	point2 p3{ {1, 1} };

	line l1{ p1, p2 };

	castinfo info = pointcast(point2({ 3, 1 }), vec2({ -1, 1 }), l1);
	if (info.is_hit) std::cout << info.hit_point[0] << '\t' << info.hit_point[1] << std::endl;

	polygon<3, 2> pol1{ {p1, p2, p3} };

	return 0;
}