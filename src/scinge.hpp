// scinge.hpp

#include <cmath>
#include <iterator>
#include <numeric>
#include <functional>
#include <algorithm>
#include <numbers>

namespace scinge
{
	using std::numbers::pi;
	constexpr double gravity_acceleration_g = 9.80665;
	constexpr double gravitational_constant_G = 6.67408e-11;
	
	template<typename T>
	constexpr double average(T& value)
	{ return (std::accumulate(begin(value), end(value), 0.0) / static_cast<double>(value.size()) ); }
	
	template<typename T>
	constexpr double moving_average(T& value, size_t period, size_t position)
	{ return (std::accumulate( begin(value)+(position), end(value)+(position+period), 0.0) / static_cast<double>(period) ); }

	template<typename T>
	constexpr double standard_deviation(T& value)
	{	
		double mean = average(value);
		return sqrt( std::transform_reduce(begin(value), end(value), 0.0, std::plus{}, [mean](auto &x){return pow((x - mean),2);}) / static_cast<double>(value.size()) );
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
	{return (2*pi*(double)radius); }

	template<typename T>
	constexpr double circle_area(T radius)
	{return ( pi * pow(radius,2) ); }

	template<typename T>
	constexpr double sphere_volume(T radius)
	{return ( (4.0/3.0) * pi * pow(radius, 3) ); }

	template<typename T>
	constexpr double cone_volume(T radius, T height)
	{return ((pi * pow(radius, 2)) * height) / 3.0 ; }
	
	template<typename T>
	constexpr double cone_surface_area(T radius, T height)
	{return ( pi * radius * sqrt(pow(radius, 2) + pow(height, 2)) ) ; }
	
	template<typename T>
	constexpr double cylinder_volume(T radius, T height)
	{return ( pi * pow(radius, 2) * height ) ; }
	
	template<typename T>
	constexpr double cylinder_surface_area(T radius, T height)
	{return (( 2 * pi * radius * height ) + (2 * pi * pow(radius, 2))) ; }

	template<typename T>
	constexpr double sphere_surface_area(T radius)
	{return  (4 * pi * pow(radius, 2) ); }

	template<typename T>
	constexpr double triangle_area(T base, T height)
	{return ((base * height)/2.0) ;}

	template<typename T>
	constexpr double trapezoid_area(T base_side, T top_side, T height)
	{return ((top_side + base_side) * height) / 2.0   ;}

	template<typename T>
	constexpr T square_area(T length)
	{return (length*length) ;}

	template<typename T>
	constexpr T square_perimeter(T length)
	{return (length * 4) ;}

	template<typename T>
	constexpr T rectangle_area(T length, T width)
	{return (length * width) ;}

	template<typename T>
	constexpr T rectangle_perimeter(T length, T width)
	{return (2 * length) + (2 * width) ;}

	template<typename T>
	constexpr T box_volume(T height, T width, T depth)
	{return (height * width * depth) ;}

	template<typename T>
	constexpr T box_surface_area(T height, T width, T depth)
	{return (2 * height * width) + (2 * height * depth) * (2 * width * depth) ;}

	template<typename T>
	constexpr double cube_volume(T length)
	{return pow(length, 3) ;}

	template<typename T>
	constexpr double cube_surface_area(T length)
	{return 6 * pow(length, 2) ;}

	template<typename T>
	constexpr T voltage(T current, T resistance)
	{ return current * resistance ;}

	constexpr double current(double voltage, double resistance)
	{ return voltage/resistance ;}

	constexpr double resistance(double voltage, double current)
	{ return voltage/current ;}

	constexpr double kinetic_energy(double mass, double velocity)
	{ return ( mass * pow(velocity, 2)) / 2 ;}

	constexpr double electrical_power(double current, double voltage)
	{ return ( current * voltage ) ;}

	constexpr double potential_energy(double mass, double height)
	{ return mass * gravity_acceleration_g * height ;}

	constexpr double efficiency(double power_output, double power_input)
	{ return (power_output/power_input)/100 ;}

	constexpr double thermal_energy(double mass, double specific_heat, double T1, double T2)
	{ return (mass * specific_heat * delta(T1,T2)) ;}

		


};
