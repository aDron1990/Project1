#pragma once

#include "point.h"

#include <array>
#include <vector>
#include <algorithm>
#include <iostream>

namespace mymath::geometry
{
	template <int size, int dimention>
	std::array<point<dimention>, size> convexHull(std::vector<point<dimention>> vertices)
	{
		auto it = vertices.begin();
		for (auto iit = vertices.begin(); iit != vertices.end(); iit++)
		{
			if ((*iit)[0] == (*it)[0]) it = (*it)[1] < (*iit)[1] ? it : iit;
			if ((*iit)[0] > (*it)[0]) it = iit;
		}

		std::array<point<dimention>, size> result;
		result[0] = *it;



		return result;
	}

	template <int size, int dimention>
	class polygon
	{
	private:

		std::array<point<dimention>, size> vertices_;

	public:

		polygon(std::vector<point<dimention>> vertices) : vertices_(convexHull<size, dimention>(vertices))
		{
			
		}

		
	};
}