//AppleProduct.cpp

#include "AppleProduct.h"

//Default constructor
cs31::AppleProduct::AppleProduct() {
	mVersion = "";
	mColor = "";
	mCost = 0.00;
	mKind = NOTSPECIFIED;
};
//Constructed with Arguments
cs31::AppleProduct::AppleProduct(Kind kind, string version, string color, double cost) {
	mKind = kind;
	mVersion = version;
	mColor = color;
	mCost = cost;
};
//get Private data functions
string cs31::AppleProduct::getVersion() {
	return this->mVersion;
};
string cs31::AppleProduct::getColor() {
	return this->mColor;
}
cs31::AppleProduct::Kind cs31::AppleProduct::getKind() {
	return this->mKind;
}
double cs31::AppleProduct::getCost() {
	return this->mCost;
}