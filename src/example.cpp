// example.cpp

#include <array>
#include <iostream>
#include <chrono>
#include <algorithm>
#include "scinge.hpp"
#include "matrix.hpp"



std::array<double, 11> tester{3.14159, 3.3, 7.45, 0, -4.3, -12.3, 19.5, 42, -23.1, 0, 0.75};
std::array<int, 8> sample{2,4,4,4,5,5,7,9};

int main()
{
	using std::chrono::high_resolution_clock;
	using std::chrono::duration;
	using std::chrono::duration_cast;

	auto t1 = high_resolution_clock::now();
		
	std::cout << "The average for the first 3 elements of tester array is:\t" <<  scinge::moving_average(tester, 3, 0) << '\n';
	std::cout << "The average of the tester array is:\t" << scinge::average(tester) << '\n'; 
	std::cout << "The circumference of a circle with radius 4 is:\t" << scinge::circumference(4) << "\n\n";	
	std::cout << "The standard deviation is:\t" << scinge::standard_deviation(tester) << '\n';
	std::cout << "The second sample standard is:\t" << scinge::standard_deviation(sample) << '\n';	

	std::cout << "The delta of 56 to 78 is:\t" << scinge::delta(56, 78) << '\n';


	scinge::Matrix<int> basic(25);
	scinge::Matrix<int> square(100,100);	
	scinge::Matrix<int> cube(100, 100, 100);
	scinge::Matrix<int> tesseract(100, 100, 100, 100);
	
	std::cout << "\nMy vector contains " << basic.elements.capacity() << " elements\n";
	std::cout << "My matrix contains " << square.elements.capacity() << " elements\n";
	std::cout << "My cube contains " << cube.elements.capacity() << " elements\n";
	std::cout << "My tesseract contains " << tesseract.elements.capacity() << " elements\n\n";

	basic.populate_vector(5,5);
	basic.print_vector_element(5);

	square.populate_square_matrix(0,0,42);
	square.print_square_element(0,0);

	cube.populate_cube(1,6,23, 420);
	cube.print_cube_element(1,6,23);

	tesseract.populate_tesseract(10,50,75,25, 4200);
	tesseract.print_tesseract_element(10,50,75,25);	


	std::cout << "\nThe 0th fibonacci number is:\t" << scinge::fibonacci(0) << "\n";
	std::cout << "The 1st fibonacci number is:\t" << scinge::fibonacci(1) << "\n";
	std::cout << "The 2nd fibonacci number is:\t" << scinge::fibonacci(2) << "\n";
	std::cout << "The 3rd fibonacci number is:\t" << scinge::fibonacci(3) << "\n";
	std::cout << "The 4th fibonacci number is:\t" << scinge::fibonacci(4) << "\n";
	std::cout << "The 5th fibonacci number is:\t" << scinge::fibonacci(5) << "\n";
	std::cout << "The 6th fibonacci number is:\t" << scinge::fibonacci(6) << "\n";
	std::cout << "The 7th fibonacci number is:\t" << scinge::fibonacci(7) << "\n";
	std::cout << "The 8th fibonacci number is:\t" << scinge::fibonacci(8) << "\n";
	std::cout << "The 9th fibonacci number is:\t" << scinge::fibonacci(9) << "\n";
	std::cout << "The 10th fibonacci number is:\t" << scinge::fibonacci(10) << "\n";
	std::cout << "The 20th fibonacci number is:\t" << scinge::fibonacci(20) << "\n";
	std::cout << "The 50th fibonacci number is:\t" << scinge::fibonacci(50) << "\n";
	std::cout << "The 75th fibonacci number is:\t" << scinge::fibonacci(75) << "\n";
	std::cout << "The 100th fibonacci number is:\t" << scinge::fibonacci_binet(100) << "\n";
	
	auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;

	std::cout << "\nTotal run time was:\t" << ms_double.count() << " milliseconds\n";

	
	
	return 0;
}
