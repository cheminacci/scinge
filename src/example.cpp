// example.cpp

#include "scinge.hpp"
#include <array>
#include <iostream>

std::array<double, 11> tester{3.14159, 3.3, 7.45, 0, -4.3, -12.3, 19.5, 42, -23.1, 0, 0.75};
std::array<int, 8> sample{2,4,4,4,5,5,7,9};

int main()
{
	std::cout << scinge::moving_average(tester, 3, 0) << '\n';
	std::cout << scinge::average(tester) << '\n'; 
	std::cout << scinge::circumference(4) << "\n\n";	
	std::cout << "The standard deviation is:\t" << scinge::standard_deviation(tester) << '\n';
	std::cout << "The second sample standard is:\t" << scinge::standard_deviation(sample) << '\n';	
	
	return 0;
}
