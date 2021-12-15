#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

namespace scinge
{
	template <typename T>
	struct Matrix
	{
		std::uint64_t number_of_x_elements;
		std::uint64_t number_of_y_elements;
		std::uint64_t number_of_z_elements;
		std::uint64_t number_of_w_elements;
		
		public:
		std::vector<T> elements;
		
		Matrix()
		{
		
		}	

		Matrix(std::uint64_t number_of_x_elements)
		{ elements.reserve(number_of_x_elements); }

		Matrix(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements)
		{ elements.reserve(number_of_x_elements * number_of_y_elements); }
		
		Matrix(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements, std::uint64_t number_of_z_elements)
		{ elements.reserve(number_of_x_elements * number_of_y_elements * number_of_z_elements);	}
		
		Matrix(std::uint64_t number_of_x_elements, std::uint64_t number_of_y_elements, std::uint64_t number_of_z_elements, std::uint64_t number_of_w_elements)
		{ elements.reserve(number_of_x_elements * number_of_y_elements * number_of_z_elements * number_of_w_elements); }

	};




};
