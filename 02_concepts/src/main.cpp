#include <iostream>
#include <concepts>
#include <type_traits>

/////////////////////////////////////////////////////////
template<typename T, typename S>
auto simple_modulo_without_constraints(T p, S q) 
{
	return p%q;
}

void test_simple_modulo_without_constraints() {
	int p {5};
	int q {3};
	auto r = simple_modulo_without_constraints(p, q);
	std::cout << r << "\n";
}


/////////////////////////////////////////////////////////
template<typename Type1, typename Type2>
concept ModuleValidOperation = requires (Type1 p, Type2 q) { p % q; };


template<typename T, typename S>
	requires ModuleValidOperation<T, S>
auto modulo_with_constraints(T p, S q) 
{
	return p%q;
}

void test_modulo_with_constraints() {
	int p {5};
	int q {3};
	auto r = modulo_with_constraints(p, q);
	std::cout << r << "\n";
}


/////////////////////////////////////////////////////////
template<typename T, typename S, typename = std::enable_if_t<std::is_integral_v<T> && std::is_integral_v<S>> >
auto modulo_with_conventional_constraints(T p, S q) 
{
	return p%q;
}

void test_modulo_with_conventional_constraints() {
	int p {7};
	int q {3};
	auto r = modulo_with_conventional_constraints(p, q);
	std::cout << r << "\n";
}


int main() {


	std::cout << "heelo\n";
	//test_simple_modulo_without_constraints();
	//test_modulo_with_constraints();
	test_modulo_with_conventional_constraints();
	return 0;
}
