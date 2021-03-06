/**
 * Demostrates exceptions and assertions.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

// Throw an object:
class argument_must_be_positive {};

// Throw an object:
double sqrt2(double x) {
	if (x<0)
		throw argument_must_be_positive{};
	double result = std::sqrt(x);
	return result;
}

int main() {
	cout << "std::sqrt(4) = " << std::sqrt(4) << endl;
	cout << "std::sqrt(-4) = " << std::sqrt(-4) << endl;
	try {
		cout << "sqrt2(4) = " << sqrt2(4) << endl;
		cout << "sqrt2(-4) = " << sqrt2(-4) << endl;
	}
	//catch (argument_must_be_positive x) {
	// 	cout << "   caught exception " << typeid(x).name() << endl;
	//}
	catch (...) {
		auto exception = std::current_exception();
	 	cout << "   caught exception of type " << exception.__cxa_exception_type()->name() << endl;
	}
}
