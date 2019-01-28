//AppleStore.h

#ifndef APPLESTORE_H
#define APPLESTORE_H

#include "AppleProduct.h"

//namespace cs31
namespace cs31 {
	class AppleStore {
	public:
		//Constructor
		AppleStore();
		//iWatch methods
		AppleProduct buyWatch1(string color);
		AppleProduct buyWatch3(string color);
		//iPad methods
		AppleProduct buyiPad(string color, int gigabytes);
		AppleProduct buyiPadPro(string color, int gigabytes);
		//iPhone methods
		AppleProduct buyiPhoneX(string color, int gigabytes);
		AppleProduct buyiPhone8(string color, int gigabytes);
		AppleProduct buyiPhone8Plus(string color, int gigabytes);
	};
}
#endif //APPLESTORE_H

