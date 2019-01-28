//AppleStore.cpp

#include "AppleStore.h"
#include "AppleProduct.h"

//constructor
cs31::AppleStore::AppleStore() {
	//nothing inside the constructor - no data to be stored,
	//	just an object to hold the methods to buy and work with
	//	AppleProducts.
};
//iWatch methods
//iWatch V1
cs31::AppleProduct cs31::AppleStore::buyWatch1(string color) {
	return AppleProduct(AppleProduct::Kind::WATCH, "1", color, 249.00);
};
//iWatch V3
cs31::AppleProduct cs31::AppleStore::buyWatch3(string color) {
	return AppleProduct(AppleProduct::Kind::WATCH, "3", color, 329.00);
};
//iPad methods
//iPad
cs31::AppleProduct cs31::AppleStore::buyiPad(string color, int gigabytes) {
	if (gigabytes == 32) {
		return AppleProduct(AppleProduct::Kind::IPAD, "", color, 329.00);
	}
	else if (gigabytes == 128) {
		return AppleProduct(AppleProduct::Kind::IPAD, "", color, 429.00);
	}
	else {
		throw logic_error("Incorrect gigabytes");
	}
};
//iPad Pro
cs31::AppleProduct cs31::AppleStore::buyiPadPro(string color, int gigabytes) {
	if (gigabytes == 64) {
		return AppleProduct(AppleProduct::Kind::IPAD, "", color, 649.00);
	}
	else if (gigabytes == 256) {
		return AppleProduct(AppleProduct::Kind::IPAD, "", color, 799.00);
	}
	else if (gigabytes == 512) {
		return AppleProduct(AppleProduct::Kind::IPAD, "", color, 999.00);
	}
	else {
		throw logic_error("Incorrect gigabytes");
	}
};
//iPhone methods
//iPhone X
cs31::AppleProduct cs31::AppleStore::buyiPhoneX(string color, int gigabytes) {
	if (gigabytes == 64) {
		return AppleProduct(AppleProduct::Kind::IPHONE, "X", color, 999.00);
	}
	else if (gigabytes == 256) {
		return AppleProduct(AppleProduct::Kind::IPHONE, "X", color, 1149.00);
	}
	else {
		throw logic_error("Incorrect gigabytes");
	}
};
//iPhone 8
cs31::AppleProduct cs31::AppleStore::buyiPhone8(string color, int gigabytes) {
	if (gigabytes == 64) {
		return AppleProduct(AppleProduct::Kind::IPHONE, "8", color, 699.00);
	}
	else if (gigabytes == 256) {
		return AppleProduct(AppleProduct::Kind::IPHONE, "8", color, 849.00);
	}
	else {
		throw logic_error("Incorrect gigabytes");
	}
};
//iPhone 8Plus
cs31::AppleProduct cs31::AppleStore::buyiPhone8Plus(string color, int gigabytes) {
	if (gigabytes == 64) {
		return AppleProduct(AppleProduct::Kind::IPHONE, "8PLus", color, 799.00);
	}
	else if (gigabytes == 256) {
		return AppleProduct(AppleProduct::Kind::IPHONE, "8Plus", color, 949.00);
	}
	else {
		throw logic_error("Incorrect gigabytes");
	}
};
