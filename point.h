#pragma once

#include <array>
#include <ostream>
#include <exception>

namespace mymath{ template <int size> class vec; }

namespace mymath::geometry
{
	template <int dimention>
	class point
	{
	protected:

		std::array<float, dimention> data_;

	public:

		point(std::array<float, dimention> data = { 0 }) : data_(data) { }
		float& operator[](int i)
		{
			if (i >= dimention) throw std::exception("out of range");
			return data_[i];
		}

		float operator[](int i) const
		{
			if (i >= dimention) throw std::exception("out of range");
			return data_[i];
		}

		vec<dimention> to_vec() const
		{
			return vec{ data_ };
		}
	};

	using point2 = point<2>;
	using point3 = point<3>;
	using point4 = point<4>;
}

