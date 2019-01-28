//AppleProduct.h

#ifndef APPLEPRODUCT_H
#define APPLEPRODUCT_H

#include <iostream>
using namespace std;

//namespace cs31
namespace cs31 {
	class AppleProduct {
	public:
		//enum Kind
		enum Kind { NOTSPECIFIED, IPHONE, IPAD, WATCH };
		//Constructors
		AppleProduct();
		AppleProduct(Kind kind, string version, string color, double cost);
		//Public methods
		string getVersion();
		string getColor();
		Kind getKind();
		double getCost();
	private:
		//Private data
		Kind mKind;
		string mVersion;
		string mColor;
		double mCost;
	};
}
#endif //APPLEPRODUCT_H