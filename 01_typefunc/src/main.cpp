#include <iostream>
#include "lrn/types.hpp"

void test_static_array() {

	int a[5]{1,3, 4,5,6};
	auto acopy = a;

	double b[] {1, 2, 3};

	std::cout << lrn::array_size(b) << " array size\n";
}


template<typename ArgType1, typename ArgType2>
auto summation_one(ArgType1 a, ArgType2 b){

	using common_t = std::common_type_t<ArgType1, ArgType2>;

	if constexpr(std::is_integral_v<common_t>) {
		using type_t = std::make_signed_t<common_t>;
		std::cout << lrn::type_to_string<type_t>() << "\n" ;
		type_t sum{};
		
		for (auto i = a; i < b; ++i){
			sum += i;
		}

		return sum;
	} else {
		using type_t = common_t;
		std::cout << lrn::type_to_string<type_t>() << "\n" ;
		type_t sum{};
		
		for (auto i = a; i < b; ++i){
			sum += i;
		}

		return sum;
	}
}


int main(int argc, char* argv[]) {
	//std::cout << "hello world";
	
	//std::cout << summation_one(0, 10) << "\n";
	//std::cout << summation_one(0, 10.0) << "\n";

	test_static_array();
	return 0;
}
