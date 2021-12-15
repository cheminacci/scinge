// scinge.hpp

#include <cmath>
#include <iterator>
#include <numeric>
#include <functional>
#include <algorithm>
#include <numbers>

namespace scinge
{
	template<typename T>
	constexpr double average(T& value)
	{ return (std::accumulate(begin(value), end(value), 0.0) / (double)value.size() ); }
	
	template<typename T>
	constexpr double moving_average(T& value, size_t period, size_t position)
	{ return (std::accumulate( begin(value)+(position), end(value)+(position+period), 0.0) / (double)period ); }

	template<typename T>
	constexpr double standard_deviation(T& value)
	{
		double mean = average(value);
		return sqrt( std::transform_reduce(begin(value), end(value), 0.0, std::plus{}, [mean](auto& x){return pow((x - mean),2);}) / (double)value.size());
	}

	template<typename T>
	constexpr T delta(T start, T finish)
	{ return (finish - start); }

	template<typename T>
	constexpr T delta_2nd(T start1, T finish1, T start2, T finish2)
	{ return (delta(finish1 - start1) - delta(finish2 - start2)); }
	
	template<typename T, typename U>
	constexpr double velocity(T distance, U time)
	{ return (distance / (T)time); }	

	template<typename T, typename U>
	constexpr double acceleration(T distance1, U time1, T distance2, U time2)
	{ return velocity(distance2, time2) - velocity(distance1, time1); }	

	template<typename T>
	constexpr double circumference(T radius)
	{return (2*(std::numbers::pi)*(double)radius); }

	template<typename T>
	constexpr double circle_area(T radius)
	{return ( (std::numbers::pi) * pow(radius,2) ); }

	template<typename T>
	constexpr double triangle_area(T base, T height)
	{return ((base * height)/2.0) ;}



};