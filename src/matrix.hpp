#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <iostream>

namespace scinge
{
	template <typename T>
	class Matrix
	{
		std::uint64_t number_of_x_elements;
		std::uint64_t number_of_y_elements;
		std::uint64_t number_of_z_elements;
		std::uint64_t number_of_w_elements;
		
		public:
		std::vector<T> elements{0};
		Matrix()
		{
		
		}	

		Matrix(std::uint64_t number_of_x_elements)
		{ 
			elements.reserve(number_of_x_elements);
	       		Matrix::number_of_x_elements = number_of_x_elements;	
		}

		Matrix(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements)
		{
	       		elements.reserve(number_of_x_elements * number_of_y_elements);
			Matrix::number_of_x_elements = number_of_x_elements;
			Matrix::number_of_y_elements = number_of_y_elements;
	       	}
		
		Matrix(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements, std::uint64_t number_of_z_elements)
		{ 
			elements.reserve(number_of_x_elements * number_of_y_elements * number_of_z_elements);	
			
			Matrix::number_of_x_elements = number_of_x_elements;
			Matrix::number_of_y_elements = number_of_y_elements;
			Matrix::number_of_z_elements = number_of_z_elements;
		}
		
		Matrix(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements, std::uint64_t number_of_z_elements, std::uint64_t number_of_w_elements)
		{ 
			elements.reserve(number_of_x_elements * number_of_y_elements * number_of_z_elements * number_of_w_elements); 
			Matrix::number_of_x_elements = number_of_x_elements;
			Matrix::number_of_y_elements = number_of_y_elements;
			Matrix::number_of_z_elements = number_of_z_elements;
			Matrix::number_of_w_elements = number_of_w_elements;
		
		}


		void populate_vector(uint64_t x_position, T value)
		{	
			Matrix::elements[x_position] = value;
		}

		void populate_square_matrix(uint64_t x_position, uint64_t y_position, T value)
		{	
			uint64_t location = ((y_position * number_of_x_elements) + x_position ); 
			Matrix::elements[location] = value;
		}

		void populate_cube(uint64_t x_position, uint64_t y_position, uint64_t z_position, T value)
		{	
			uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position);
			Matrix::elements[location] = value;
		}

		void populate_tesseract(uint64_t x_position, uint64_t y_position, uint64_t z_position, uint64_t w_position, T value)
		{	
			uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position) + \
					    (number_of_x_elements * number_of_y_elements * number_of_z_elements * w_position);	
			Matrix::elements[location] = value;
		}

		
		void print_vector_element(uint64_t x)
		{ std::cout << "Element at vector position " << x << " is:\t" << elements[x] <<'\n'; }

		void print_square_element(uint64_t x_position, uint64_t y_position)
		{	
			uint64_t location = ((y_position * number_of_x_elements) + x_position ); 
			std::cout << "The element at coordinate (" 
				<< x_position << " , " 
				<< y_position << ") is:\t" 
				<< elements[location] << '\n';
		}


		void print_cube_element(uint64_t x_position, uint64_t y_position, uint64_t z_position)
		{	
			uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position);
			std::cout << "The element at coordinate (" 
				<< x_position << " , " 
				<< y_position << " , " 
				<< z_position << ") is:\t" 
				<< elements[location] << '\n';
		}

		void print_tesseract_element(uint64_t x_position, uint64_t y_position, uint64_t z_position, uint64_t w_position)
		{	
			uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position) + \
					    (number_of_x_elements * number_of_y_elements * number_of_z_elements * w_position);	
			std::cout << "The element at coordinate (" 
				<< x_position << " , " 
				<< y_position << " , " 
				<< z_position << " , " 
				<< w_position << ") is:\t" 
				<< elements[location] << '\n';
		}
	};




};
