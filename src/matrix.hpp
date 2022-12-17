#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <cstdint>


#ifndef FMT_HEADER_ONLY
	#define FMT_HEADER_ONLY
	#include <fmt/core.h>
#endif


namespace scinge
{	

	using fmt::print;
	using u64 = std::uint64_t;
	
	template <typename T>
	class Matrix_1d
	{
		u64 number_of_x_elements;
		
		public:
		std::vector<T> elements;

		constexpr Matrix_1d(const u64 x_elements)
		{ 
			elements.reserve(x_elements);
       		Matrix_1d::number_of_x_elements = x_elements;	
		}

		constexpr void populate_vector(const u64 x_position, const T value)
		{	
			Matrix_1d::elements[x_position] = value;
		}
		
		constexpr void print_vector_element(const u64 x)
		{ 	print("The element at vector position {} is:\t{}\n", x, elements[x]); }

	};

	template <typename T>
	class Matrix_2d
	{
		u64 number_of_x_elements;
		u64 number_of_y_elements;
		
		public:
		std::vector<T> elements;

		constexpr Matrix_2d(const u64 x_elements, const u64 y_elements)
		{
       		elements.reserve(x_elements * y_elements);
			Matrix_2d::number_of_x_elements = x_elements;
			Matrix_2d::number_of_y_elements = y_elements;
       	}
		
		constexpr void populate_square_matrix(const u64 x_position, const u64 y_position, const T value)
		{	
			const u64 location = ((y_position * number_of_x_elements) + x_position ); 
			Matrix_2d::elements[location] = value;
		}

		constexpr void print_square_element(const u64 x_position, const u64 y_position)
		{	
			const u64 location = ((y_position * number_of_x_elements) + x_position ); 
			print("The element at coordinate ({}, {}) is:\t{}\n", x_position, y_position, elements[location]); 
		}

	};

	template <typename T>
	class Matrix_3d
	{
		u64 number_of_x_elements;
		u64 number_of_y_elements;
		u64 number_of_z_elements;

		public:
		std::vector<T> elements;

		constexpr Matrix_3d(const u64 x_elements, const u64 y_elements, const u64 z_elements)
		{ 
			elements.reserve(x_elements * y_elements * z_elements);	
			Matrix_3d::number_of_x_elements = x_elements;
			Matrix_3d::number_of_y_elements = y_elements;
			Matrix_3d::number_of_z_elements = z_elements;
		}
		
		constexpr void populate_cube(const u64 x_position, const u64 y_position, const u64 z_position, const T value)
		{	
			const u64 location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position);
			Matrix_3d::elements[location] = value;
		}

		constexpr void print_cube_element(const u64 x_position, const u64 y_position, const u64 z_position)
		{	
			const u64 location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position);
			print("The element at coordinate ({}, {}, {}) is:\t{}\n", x_position, y_position, z_position, elements[location]);
		}

	};

	template <typename T>
	class Matrix_4d
	{
		u64 number_of_x_elements;
		u64 number_of_y_elements;
		u64 number_of_z_elements;
		u64 number_of_w_elements;

		public:
		std::vector<T> elements;

		constexpr Matrix_4d(const u64 x_elements, const u64 y_elements, const u64 z_elements, const u64 w_elements)
		{ 
			elements.reserve(x_elements * y_elements * z_elements * w_elements); 
			Matrix_4d::number_of_x_elements = x_elements;
			Matrix_4d::number_of_y_elements = y_elements;
			Matrix_4d::number_of_z_elements = z_elements;
			Matrix_4d::number_of_w_elements = w_elements;
		}

		constexpr void populate_tesseract(const u64 x_position, const u64 y_position, const u64 z_position, const u64 w_position, const T value)
		{	
			const u64 location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position) + \
					    (number_of_x_elements * number_of_y_elements * number_of_z_elements * w_position);	
			Matrix_4d::elements[location] = value;
		}

		constexpr void print_tesseract_element(const u64 x_position, const u64 y_position, const u64 z_position, const u64 w_position)
		{	
			const u64 location = ((y_position * number_of_x_elements) + x_position ) + (number_of_x_elements * number_of_y_elements * z_position) + \
					    (number_of_x_elements * number_of_y_elements * number_of_z_elements * w_position);	
			print("The element at coordinate ({}, {}, {}, {}) is:\t{}\n", x_position, y_position, z_position, w_position, elements[location]);
		}
	};

	
};
