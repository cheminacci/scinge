// scinge.hpp

#include <cmath>
#include <cstdint>
#include <numeric>
#include <algorithm>
#include <numbers>
#include <concepts>

//#include <boost/multiprecision/cpp_int.hpp>

namespace scinge
{	
	using std::numbers::pi;

	constexpr const double gravity_acceleration_g = 9.80665;
	constexpr const double gravitational_constant_G = 6.67408e-11;
	constexpr const double speed_of_light_in_vacuum = 2.99792458e8;
	constexpr const double plancks_constant = 6.626069e-34;
	constexpr const double reduced_planck_bar = 1.054571817e-34;
	constexpr const double planck_length = 1.616255e-35;
	constexpr const double planck_mass = 2.176434e-8;
	constexpr const double planck_temperature = 1.416784e32;
	constexpr const double elementary_charge = 1.602176634e-19;
	constexpr const double electron_volt = 1.602176634e-19;
	constexpr const double vacuum_magnetic_permeability = 1.25663706212e-6;
	constexpr const double vacuum_electric_permittivity = 8.8541878128e-12;
	constexpr const double electron_mass = 9.1093837015e-31;
	constexpr const double proton_mass = 1.67262192369e-27;
	constexpr const double proton_electron_mass_ratio = 1836.15267343;
	constexpr const double boltzmann_constant = 1.380649e-23;
	constexpr const double avogadro_number = 6.02214076e-23;
	constexpr const double molar_gas_constant_R = 8.314462618;
	constexpr const double faraday_constant = 96485.33212;
	constexpr const double stefan_boltzmann = 5.670374419e-8; 

	template<typename T>
	concept regular_number = (std::integral<T> || std::floating_point<T>) ;

	template<typename T>
	constexpr double average(const T& value)
	{ return (std::accumulate(begin(value), end(value), 0.0) / static_cast<double>(value.size())); }
	
	template<typename T>
	constexpr double moving_average(const T& value, const size_t period, const size_t position)
	{ return (std::accumulate(begin(value)+position, begin(value)+position+period, 0.0) / static_cast<double>(period)); }

	template<typename T>
	constexpr double standard_deviation(const T& value)
	{	
		const double mean = average(value);
		return sqrt( std::transform_reduce(begin(value), end(value), 0.0, std::plus{}, [mean](auto &x){return pow((x - mean),2);}) / static_cast<double>(value.size()) );
	}
	
	template<typename T>
	requires regular_number<T>
	constexpr T delta(const T start, const T finish)
	{ return (finish - start); }

	template<typename T>
	requires regular_number<T>
	constexpr T delta_2nd(const T start1, const T finish1, const T start2, const T finish2)
	{ return (delta(finish1 - start1) - delta(finish2 - start2)); }
	
	template<typename T, typename U>
	requires regular_number<T> && regular_number<U>
	constexpr double velocity(const T distance, const U time)
	{ return (distance / (T)time); }	

	template<typename T, typename U>
	requires regular_number<T> && regular_number<U>
	constexpr double acceleration(const T distance1, const U time1, const T distance2, const U time2)
	{ return velocity(distance2, time2) - velocity(distance1, time1); }	

	template<typename T>
	requires regular_number<T> 
	constexpr double circumference(const T radius)
	{return (2*pi*(double)radius); }

	template<typename T>
	requires regular_number<T> 
	constexpr double circle_area(const T radius)
	{return ( pi * pow(radius,2) ); }

	template<typename T>
	requires regular_number<T> 
	constexpr double sphere_volume(const T radius)
	{return ( (4.0/3.0) * pi * pow(radius, 3) ); }

	template<typename T>
	requires regular_number<T> 
	constexpr double cone_volume(const T radius, const T height)
	{return ((pi * pow(radius, 2)) * height) / 3.0; }
	
	template<typename T>
	requires regular_number<T> 
	constexpr double cone_surface_area(const T radius, const T height)
	{return ( pi * radius * sqrt(pow(radius, 2) + pow(height, 2)) ); }
	
	template<typename T>
	requires regular_number<T> 
	constexpr double cylinder_volume(const T radius, const T height)
	{return ( pi * pow(radius, 2) * height ); }
	
	template<typename T>
	requires regular_number<T> 
	constexpr double cylinder_surface_area(const T radius, const T height)
	{return (( 2 * pi * radius * height ) + (2 * pi * pow(radius, 2))); }

	template<typename T>
	requires regular_number<T> 
	constexpr double sphere_surface_area(const T radius)
	{return  (4 * pi * pow(radius, 2) ); }

	template<typename T>
	requires regular_number<T> 
	constexpr double triangle_area(const T base, const T height)
	{return ((base * height)/2.0);}

	template<typename T>
	requires regular_number<T> 
	constexpr double trapezoid_area(const T base_side, const T top_side, const T height)
	{return ((top_side + base_side) * height) / 2.0;}

	template<typename T>
	requires regular_number<T> 
	constexpr T square_area(const T length)
	{return (length*length);}

	template<typename T>
	requires regular_number<T> 
	constexpr T square_perimeter(const T length)
	{return (length * 4);}

	template<typename T>
	requires regular_number<T> 
	constexpr T rectangle_area(const T length, const T width)
	{return (length * width);}

	template<typename T>
	requires regular_number<T> 
	constexpr T rectangle_perimeter(const T length, const T width)
	{return (2 * length) + (2 * width);}

	template<typename T>
	requires regular_number<T> 
	constexpr T box_volume(const T height, const T width, const T depth)
	{return (height * width * depth);}

	template<typename T>
	requires regular_number<T> 
	constexpr T box_surface_area(const T height, const T width, const T depth)
	{return (2 * height * width) + (2 * height * depth) * (2 * width * depth);}

	template<typename T>
	requires regular_number<T> 
	constexpr double cube_volume(const T length)
	{return pow(length, 3);}

	template<typename T>
	requires regular_number<T> 
	constexpr double cube_surface_area(const T length)
	{return 6 * pow(length, 2);}

//  Fibonacci using a loop
/*	
	constexpr boost::multiprecision::uint128_t fibonacci_big(const uint64_t fib_count)
	{	
		boost::multiprecision::uint128_t temp_sum = 0, val1 = 0, val2 = 1;

		if(fib_count==0)
		{return 0;}
		else if(fib_count==1)
		{return 1;}

		else
		for(uint64_t i=2; i<=fib_count; i++)
		{
			temp_sum = val1 + val2;
			val1 = val2;
			val2 = temp_sum;
		}
		return temp_sum;
	}
*/

//  Fibonacci using a loop

	template<typename T> 
	requires std::integral<T>
	constexpr std::uint64_t fibonacci(const T fib_count)
	{	
		std::uint64_t temp_sum = 0, val1 = 0, val2 = 1;

		if(fib_count==0)
		{return 0;}
		else if(fib_count==1)
		{return 1;}

		else 
		for(T i=2; i<=fib_count; i++)
		{
			temp_sum = val1 + val2;
			val1 = val2;
			val2 = temp_sum;
		}
		return temp_sum;
	}

//  Fibonacci Using recursion (VERY SLOW)
	template<typename T>
	requires std::integral<T>
	constexpr std::uint64_t fibonacci_recursive(const T fib_count)  
	{
		if(fib_count==0)
		{return 0;}
		else if(fib_count==1)
		{return 1;}
		else
		return fibonacci_recursive(fib_count-2) + fibonacci_recursive(fib_count-1);
	}

//  Fibonacci Using Binet's formula (VERY FAST, But less accurate for larger numbers)
	template<typename T>
	requires std::integral<T>
	constexpr double fibonacci_binet(const T fib_count)
	{	
		return pow(5, -0.5) * (pow((1 + sqrt(5))/2, static_cast<double>(fib_count)) - pow((1 - sqrt(5))/2, static_cast<double>(fib_count)));
	}

	template<typename T>
	requires regular_number<T> 
	constexpr T voltage(const T current, const T resistance)
	{ return current * resistance ;}

	constexpr double current(const double voltage, const double resistance)
	{ return voltage/resistance ;}

	constexpr double resistance(const double voltage, const double current)
	{ return voltage/current ;}

	constexpr double kinetic_energy(const double mass, const double velocity)
	{ return ( mass * pow(velocity, 2)) / 2 ;}

	constexpr double electrical_power(const double current, const double voltage)
	{ return ( current * voltage ) ;}

	constexpr double potential_energy(const double mass, const double height)
	{ return mass * gravity_acceleration_g * height ;}

	constexpr double efficiency(const double power_output, const double power_input)
	{ return (power_output/power_input)/100 ;}

	constexpr double thermal_energy(const double mass, const double specific_heat, const double T1, const double T2)
	{ return (mass * specific_heat * delta(T1,T2)) ;}

		



};