#pragma once

#include "point.h"

#include <array>
#include <exception>
#include <numeric>
#include <cmath>

const auto sumOfSquares = [](float a, float b) { return pow<float, float>(a, 2) + pow<float, float>(b, 2); };

namespace mymath
{
	template <int size>
	class vec
	{
	private:

		std::array<float, size> data_;
		

	public:

		vec(std::array<float, size> data = { 0 }) : data_(data) { }

		geometry::point<size> to_point() const
		{
			return point<size>(data_);
		}

		float& operator[](int i)
		{
			if (i >= size) throw std::exception("out of range");
			return *&data_[i];
		}

		float operator[](int i) const
		{
			if (i >= size) throw std::exception("out of range");
			return data_[i];
		}

		float magnitude() const noexcept
		{
			float sum = std::accumulate(data_.begin(), data_.end(), 0, sumOfSquares);
			return sqrt(sum);
		}

		vec<size> operator+(const vec<size>& other) const
		{
			vec<size> result;
			for (int i = 0; i < size; i++)
			{
				result[i] = data_[i] + other.data_[i];
			}
			return result;
		}

		vec<size> operator-(const vec<size>& other) const
		{
			vec<size> result;
			for (int i = 0; i < size; i++)
			{
				result[i] = data_[i] - other.data_[i];
			}
			return result;
		}

		vec<size> operator*(float x) const
		{
			vec<size> result;
			for (int i = 0; i < size; i++)
			{
				result[i] = data_[i] * x;
			}
			return result;
		}

		vec<size> operator/(float x) const
		{
			vec<size> result;
			for (int i = 0; i < size; i++)
			{
				result[i] = data_[i] / x;
			}
			return result;
		}

		void operator*=(float x)
		{
			for (int i = 0; i < size; i++)
			{
				data_[i] *= x;
			}
		}

		void operator/=(float x)
		{
			vec<size> result;
			for (int i = 0; i < size; i++)
			{
				data_[i] /= x;
			}
		}

		vec<size> normalized() const
		{
			return (*this / magnitude());
		}
	};

	using vec2 = vec<2>;
	using vec3 = vec<3>;
	using vec4 = vec<4>;
}

