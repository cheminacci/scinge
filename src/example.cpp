// example.cpp

#include <array>
#include <chrono>
#include <algorithm>
#include "scinge.hpp"
#include "matrix.hpp"

#ifndef FMT_HEADER_ONLY
	#define FMT_HEADER_ONLY
	#include <fmt/core.h>
#endif

std::array<double, 11> tester{3.14159, 3.3, 7.45, 0, -4.3, -12.3, 19.5, 42, -23.1, 0, 0.75};
std::array<int, 8> sample{2,4,4,4,5,5,7,9};

int main()
{
	using fmt::print;

	using std::chrono::high_resolution_clock;
	using std::chrono::duration;
	using std::chrono::duration_cast;

		
	print("The average for the first 3 elements of tester array is:\t{}\n", scinge::moving_average(tester, 3, 0));
	print("The average of the tester array is:\t{}\n", scinge::average(tester)); 
	print("The circumference of a circle with radius 4 is:\t{}\n\n", scinge::circumference(4));	
	print("The standard deviation is:\t{}\n", scinge::standard_deviation(tester));
	print("The second sample standard is:\t{}\n", scinge::standard_deviation(sample));	
	print("The delta of 56 to 78 is:\t{}\n", scinge::delta(56, 78));

	scinge::Matrix<float> basic(10);
	scinge::Matrix<int> square(100,100);	
	scinge::Matrix<int> cube(100, 100, 100);
	scinge::Matrix<int> tesseract(100, 100, 100, 100);
	
	print("\nMy vector contains {} elements\n", basic.elements.capacity());
	basic.populate_vector(5, 4.2f);


	for(uint64_t i=0; i!=basic.elements.capacity(); i++)
	{	basic.print_vector_element(i);}

	print("\n\nMy matrix contains {} elements\n", square.elements.capacity());
	square.populate_square_matrix(15, 27, 42);
	square.print_square_element(15, 27);
	print("\n");

	print("\nMy cube contains {} elements\n", cube.elements.capacity());
	cube.populate_cube(1,6,23, 420);
	cube.print_cube_element(1,6,23);
	print("\n");

	print("\nMy tesseract contains {} elements\n\n", tesseract.elements.capacity());
	tesseract.populate_tesseract(10,50,75,25, 4200);
	tesseract.print_tesseract_element(10,50,75,25);	
	print("\n");

	auto t1 = high_resolution_clock::now();

	print("The 0th fibonacci number is:\t{}\n", scinge::fibonacci(0));
	print("The 1st fibonacci number is:\t{}\n", scinge::fibonacci(1));
	print("The 2nd fibonacci number is:\t{}\n", scinge::fibonacci(2));
	print("The 3rd fibonacci number is:\t{}\n", scinge::fibonacci(3));
	print("The 4th fibonacci number is:\t{}\n", scinge::fibonacci(4));
	print("The 5th fibonacci number is:\t{}\n", scinge::fibonacci(5));
	print("The 6th fibonacci number is:\t{}\n", scinge::fibonacci(6));
	print("The 7th fibonacci number is:\t{}\n", scinge::fibonacci(7));
	print("The 8th fibonacci number is:\t{}\n", scinge::fibonacci(8));
	print("The 9th fibonacci number is:\t{}\n", scinge::fibonacci(9));
	print("The 10th fibonacci number is:\t{}\n", scinge::fibonacci(10));
	print("The 20th fibonacci number is:\t{}\n", scinge::fibonacci(20));
	print("The 50th fibonacci number is:\t{}\n", scinge::fibonacci(50));

	print("The 75th fibonacci number is:\t{}\n", scinge::fibonacci(75));
	
	auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;
	duration<double, std::micro> us_double = t2 - t1;

	print("\nTotal run time was:\t{} milliseconds\n", ms_double.count());
	print("Total run time was:\t{} microseconds\n", us_double.count());


	return 0;
}
