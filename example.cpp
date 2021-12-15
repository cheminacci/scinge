// example.cpp

#include "scinge.hpp"
#include "matrix.hpp"
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

	return 0;
}
