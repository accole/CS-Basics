//Project 5
//
//Adam Cole
//004912373
//Discussion 1E
//
//main.cpp

//includes
#include "AppleProduct.h"
#include "AppleStore.h"

#include <string>
#include <cassert>

//functions and methods

//main method won't be used in grading
int main() {
	// test code 
	cs31::AppleProduct p;
	assert(p.getCost() == 0.0);
	assert(p.getKind() == cs31::AppleProduct::Kind::NOTSPECIFIED);
	assert(p.getColor() == "");
	assert(p.getVersion() == "");

	cs31::AppleProduct p1(cs31::AppleProduct::Kind::IPHONE, "8", "Space Grey", 699.00);
	assert(std::to_string(p1.getCost()) == "699.000000");
	assert(p1.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(p1.getColor() == "Space Grey");
	assert(p1.getVersion() == "8");

	cs31::AppleStore store;
	cs31::AppleProduct iphone8_64 = store.buyiPhone8("Space Grey", 64);
	assert(std::to_string(iphone8_64.getCost()) == "699.000000");
	assert(iphone8_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8_64.getColor() == "Space Grey");
	assert(iphone8_64.getVersion() == "8");

	try
	{
		cs31::AppleStore s;
		cs31::AppleProduct iphone8 = s.buyiPhone8("Space Grey", 9999);
		assert(false);

	}
	catch (std::logic_error) {
		assert(true);
	}

	cout << "all tests passed!" << endl;
	//return
	return 0;
}