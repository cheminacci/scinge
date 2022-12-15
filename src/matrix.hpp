#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <cstdint>

#ifndef FMT_HEADER_ONLY
	#define FMT_HEADER_ONLY
	#include <fmt/core.h>
#endif

using fmt::print;

namespace scinge
{	
	
	template <typename T>
	class Matrix_1d
	{
		std::uint64_t number_of_x_elements;
		
		public:
		std::vector<T> elements;

		constexpr Matrix_1d(std::uint64_t number_of_x_elements)
		{ 
			elements.reserve(number_of_x_elements);
       			Matrix_1d::number_of_x_elements = number_of_x_elements;	
		}

		constexpr void populate_vector(std::uint64_t x_position, T value)
		{	
			Matrix_1d::elements[x_position] = value;
		}
		
		constexpr void print_vector_element(std::uint64_t x)
		{ 	print("The element at vector position {} is:\t{}\n", x, elements[x]); }

	};

	template <typename T>
	class Matrix_2d
	{
		std::uint64_t number_of_x_elements;
		std::uint64_t number_of_y_elements;
		
		public:
		std::vector<T> elements;

		constexpr Matrix_2d(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements)
		{
			elements.reserve(number_of_x_elements * number_of_y_elements);
			Matrix_2d::number_of_x_elements = number_of_x_elements;
			Matrix_2d::number_of_y_elements = number_of_y_elements;
       		}
		
		constexpr void populate_square_matrix(std::uint64_t x_position, std::uint64_t y_position, T value)
		{	
			std::uint64_t location = ((y_position * number_of_x_elements) + x_position ); 
			Matrix_2d::elements[location] = value;
		}

		constexpr void print_square_element(std::uint64_t x_position, std::uint64_t y_position)
		{	
			std::uint64_t location = ((y_position * number_of_x_elements) + x_position ); 
			print("The element at coordinate ({}, {}) is:\t{}\n", x_position, y_position, elements[location]); 
		}

	};

	template <typename T>
	class Matrix_3d
	{
		std::uint64_t number_of_x_elements;
		std::uint64_t number_of_y_elements;
		std::uint64_t number_of_z_elements;

		public:
		std::vector<T> elements;

		constexpr Matrix_3d(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements, std::uint64_t number_of_z_elements)
		{ 
			elements.reserve(number_of_x_elements * number_of_y_elements * number_of_z_elements);	
			Matrix_3d::number_of_x_elements = number_of_x_elements;
			Matrix_3d::number_of_y_elements = number_of_y_elements;
			Matrix_3d::number_of_z_elements = number_of_z_elements;
		}
		
		constexpr void populate_cube(std::uint64_t x_position, std::uint64_t y_position, std::uint64_t z_position, T value)
		{	
			std::uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position);
			Matrix_3d::elements[location] = value;
		}

		constexpr void print_cube_element(std::uint64_t x_position, std::uint64_t y_position, std::uint64_t z_position)
		{	
			std::uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position);
			print("The element at coordinate ({}, {}, {}) is:\t{}\n", x_position, y_position, z_position, elements[location]);
		}

	};

	template <typename T>
	class Matrix_4d
	{
		std::uint64_t number_of_x_elements;
		std::uint64_t number_of_y_elements;
		std::uint64_t number_of_z_elements;
		std::uint64_t number_of_w_elements;

		public:
		std::vector<T> elements;

		constexpr Matrix_4d(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements, std::uint64_t number_of_z_elements, std::uint64_t number_of_w_elements)
		{ 
			elements.reserve(number_of_x_elements * number_of_y_elements * number_of_z_elements * number_of_w_elements); 
			Matrix_4d::number_of_x_elements = number_of_x_elements;
			Matrix_4d::number_of_y_elements = number_of_y_elements;
			Matrix_4d::number_of_z_elements = number_of_z_elements;
			Matrix_4d::number_of_w_elements = number_of_w_elements;
		}

		constexpr void populate_tesseract(std::uint64_t x_position, std::uint64_t y_position, std::uint64_t z_position, std::uint64_t w_position, T value)
		{	
			std::uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position) + \
					    (number_of_x_elements * number_of_y_elements * number_of_z_elements * w_position);	
			Matrix_4d::elements[location] = value;
		}

		constexpr void print_tesseract_element(std::uint64_t x_position, std::uint64_t y_position, std::uint64_t z_position, std::uint64_t w_position)
		{	
			std::uint64_t location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position) + \
					    (number_of_x_elements * number_of_y_elements * number_of_z_elements * w_position);	
			print("The element at coordinate ({}, {}, {}, {}) is:\t{}\n", x_position, y_position, z_position, w_position, elements[location]);
		}
	};
};
