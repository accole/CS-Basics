//Adam Cole

//Project 3

//includes
#include <iostream>
#include <string>
using namespace std;

//functions and methods
//methods/functions
bool isValidEbayListingString(string auctionstring);
bool listingSold(string auctionstring);
int howMuch(string auctionstring);
int watchers(string auctionstring);
int bids(string auctionstring, int beginningindex);

//main will not be used for grading
int main() {
	//get the auction string from the user
	string auction;
	cout << "enter the auction string: " << endl;
	getline(cin, auction);

	//test the 4 methods and display the results
	cout << "isValidEbayListingString: " << isValidEbayListingString(auction) << endl;
	cout << "listingSold: " << listingSold(auction) << endl;
	cout << "howMuch: " << howMuch(auction) << endl;
	cout << "watchers: " << watchers(auction) << endl;

	//return
	return 0;
}

bool isValidEbayListingString(string auctionstring) {
	// This function returns true if its parameter is a well - formed auction string as 
	//described above, and false otherwise.
	//--------------------------------------
	//test for spaces, periods, unwatch before a watch, watch before a bid,
	//	unwatch in the middle of a bid, unwatching can't exceed max number of watchers,
	//	list price first, list price can't be changed, opening bid must start with B not B+,
	//	opening bid B can only happen once
	//-------------------------------------------
	//local variables
	bool firstbid = false;
	int watchers = 0;
	int unwatchers = 0;
	//specifically test the first character as L
	char a = auctionstring[0];
	switch (a) {
	case 'L':
	case 'l':
		break;
	default:
		return false;
	}
	//test if string length is 0
	if (auctionstring.size() == 0) {
		return false;
	}
	//loop variables
	char b = auctionstring[0];
	char p = auctionstring[0];
	//loop through the string
	for (size_t i = 0; i < auctionstring.size(); i++) {
		//test each character in the string
		char c = auctionstring[i];
		switch (c) {
			//space and decimal cases
		case ' ':
		case '.':
			return false;
			//list price cases
		case 'L':
		case 'l':
			//if it appears later than the first digit, false
			if (i != 0) {
				return false;
			}
			if (auctionstring[i + 1] == '1' || auctionstring[i + 1] == '2' || auctionstring[i + 1] == '3' || auctionstring[i + 1] == '4' ||
					auctionstring[i + 1] == '5' || auctionstring[i + 1] == '6' || auctionstring[i + 1] == '7' || auctionstring[i + 1] == '8' ||
					auctionstring[i + 1] == '9' || auctionstring[i + 1] == '0') {
					break;
			}
				else
					return false;
			break;
			//test bid cases
		case 'B':
		case 'b':
			//if just a B, not B+
			if (auctionstring[i + 1] != '+') {
				//return false if theres already been a first bid
				if (firstbid)
					return false;
				//otherwise set firstbid = true
				else
					firstbid = true;
			}
			else {
				if (!firstbid)
					return false;
				break;
			}
			break;
		//validate +
		case '+':
			if (i > 0) {
				p = auctionstring[i - 1];
				switch (p) {
				case 'b':
				case 'B':
					break;
				default:
					return false;
				}
				break;
			}
			else
				return false;
		//test watchers
		case 'W':
		case 'w':
			//increment watchers
			watchers++;
			break;
			//test unwatchers
		case 'U':
		case 'u':
			//increment unwatchers
			unwatchers++;
			//test to see if unwatchers are greater than watchers
			if (unwatchers > watchers)
				return false;
			break;
			//test numbers
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			//if the index before the number is not a B, a +, or another number,
			// theres an interruption and return false;
			b = auctionstring[i - 1];
			switch (b) {
			case 'B': case 'L': case 'l': case 'b': case '+': case '0':
			case '1': case '2': case '3': case '4': case '5':
			case '6': case '7': case '8': case '9':
				break;
			default:
				return false;
			}
			break;
		default:
			//if char c is anything else besides a number, a space,
			//a decimal, an L, a B, a +, a U, or a W, return false
			return false;
		}
	}
	//if passes through the for loop ok,
	return true;
}

bool listingSold(string auctionstring) {
	// If the parameter is a well-formed auction string, this function should process 
	//all the bids and determine if the total bid amount exceeds the list price.  If 
	//the total final bid exceeds the list price, return true.  or false otherwise. 
	//---------------------------------------------------------------------------
	//prices variables
	int listprice = 0;
	int bidprice = 0;
	//test if valid string
	if (isValidEbayListingString(auctionstring)) {
		//loop variables
		char g = auctionstring[0];
		//calculate bid prices and list prices
		for (size_t i = 0; i < auctionstring.size(); i++) {
			char f = auctionstring[i];
			switch (f) {
			case 'L':
			case 'l':
				//extract the list price and set it as listprice
				listprice = bids(auctionstring, 1);
				break;
			case 'B':
			case 'b':
				g = auctionstring[i + 1];
				switch (g) {
				case '+':
					//extract the bid and add it to the bidprice
					bidprice += bids(auctionstring, i + 2);
					break;
				default:
					//extract the original bid and set it as bidprice
					bidprice = bids(auctionstring, i + 1);
					break;
				}
			default:
				break;
			}
		}
		//only if the bid price exceeds the listing will it sell
		if (listprice < bidprice)
			return true;
	}
	//if not valid, return false
	return false;
}

int howMuch(string auctionstring) {
	//If the parameter is a well-formed auction string and the listing sold, this function
	//should process all the bids and return the total final bid.  If the auction string is 
	//not valid, return -1.  If the auction string was valid but the item did not sell, return 0. 
	//----------------------------------------------------------------------------------------
	//prices variables
	int listprice = 0;
	int bidprice = 0;
	//test if valid string
	if (isValidEbayListingString(auctionstring)) {
		//test if auction was sold
		if (listingSold(auctionstring)) {
			//loop variables
			char g = auctionstring[0];
			//calculate bid prices and list prices
			for (size_t i = 0; i < auctionstring.size(); i++) {
				char f = auctionstring[i];
				switch (f) {
				case 'B':
				case 'b':
					g = auctionstring[i + 1];
					switch (g) {
					case '+':
						//extract the bid and add it to the bidprice
						bidprice += bids(auctionstring, i + 2);
						break;
					default:
						//extract the original bid and set it as bidprice
						bidprice = bids(auctionstring, i + 1);
						break;
					}
				default:
					break;
				}
			}
			return bidprice;
		}
		//if valid but didn't sell, return 0
		return 0;
	}
	//if not valid, return -1
	return -1;
}

int watchers(string auctionstring) {
	//If the parameter is a well-formed auction string, this function should count up all the watchers 
	//that existed at the end of the auction.  If the auction string is not valid, return -1.  
	//----------------------------------------------
	//test to see if well - formed auction string
	if (isValidEbayListingString(auctionstring)) {
		//count up the number of 'W''s and 'U''s
		int wat = 0;
		int un = 0;
		for (size_t i = 0; i < auctionstring.size(); i++) {
			char c = auctionstring[i];
			switch (c) {
			case 'W':
			case 'w':
				//increment number of watchers
				wat++;
				break;
			case 'U':
			case 'u':
				//decrement number of watchers
				un++;
				break;
			}
		}
		return wat - un;
	}
	//if not valid, return -1
	return -1;
}

int bids(string auctionstring, int beginningindex) {
	//takes a string auctionstring and the index of the first number
	//and outputs the value of the bid in the string
	//--------------------------------------------------
	//local variables
	int bid = 0;
	char z = auctionstring[beginningindex];
	//determine the index of the last number by looping
	size_t i = beginningindex;
	while (z == '0' || z == '1' || z == '2' || z == '3' || z == '4'
		|| z == '5' || z == '6' || z == '7' || z == '8' || z == '9') {
		if (i < auctionstring.size()) {
			i++;
			z = auctionstring[i];
		}
	}
	//loop through the string
	for (size_t p = beginningindex; p < i ; p++) {
		char k = auctionstring[p];
		bid = bid * 10 + (k - '0');
	}
	//return the bid
	return bid;
}
