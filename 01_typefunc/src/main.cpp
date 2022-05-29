#include <iostream>
#include <string>
#include <cstring>
#include <type_traits>

template<typename Type>
std::string type_to_string(){
	std::string fname(__PRETTY_FUNCTION__);
	
	const char * with_type = "Type = ";
	auto pos = fname.find(with_type);
	fname = fname.substr(pos + std::strlen(with_type));

	
	return fname.substr(0, fname.find(";"));
}


template<typename ArgType1, typename ArgType2>
auto summation_one(ArgType1 a, ArgType2 b){

	using common_t = std::common_type_t<ArgType1, ArgType2>;

	if constexpr(std::is_integral_v<common_t>) {
		using type_t = std::make_signed_t<common_t>;
		std::cout << type_to_string<type_t>() << "\n" ;
		type_t sum{};
		
		for (auto i = a; i < b; ++i){
			sum += i;
		}

		return sum;
	} else {
		using type_t = common_t;
		std::cout << type_to_string<type_t>() << "\n" ;
		type_t sum{};
		
		for (auto i = a; i < b; ++i){
			sum += i;
		}

		return sum;
	}
}


int main(int argc, char* argv[]) {
	//std::cout << "hello world";
	
	std::cout << summation_one(0, 10) << "\n";
	std::cout << summation_one(0, 10.0) << "\n";

//	std::cout << type_to_string<int>() << "\n";
	return 0;
}
