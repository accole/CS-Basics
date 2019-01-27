//Project 4

//Adam Cole

//includes
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

//methods and functions
int countAllPunctuation(const string array[], int n);
int findMinimum(const string array[], int n);
int countFloatingPointValues(const string array[], int   n);
int removeDuplicatedValues(string array[], int  n);
int replaceAll(string array1[], int n, char letterToReplace, char letterToFill);
int shiftRight(string array[], int n, int amount, string   placeholder);
bool ifPunctuation(string test, int index);

//main won't be used for grading
int main() {
	//test string arrays
	string fourtwofive[8] = { "Wallin-", "C.r.o.l.e.", "Jason", "Em.jay", "Angel?", "Buffy!", "Angel? ", "Hi"};
	string sigmaphiepsilon[8] = {"Ba.um", "Arjun", "McKeon", "Miller", "Degan", "Ba.um", "Connor", "HEY"};

	//test cases
	cout << "Minimum of 425: " << findMinimum(fourtwofive, 8) << endl;
	cout << "Minimum of SigEp: " << findMinimum(sigmaphiepsilon, 8) << endl << endl;

	cout << "Punctuation of 425: " << countAllPunctuation(fourtwofive, 8) << endl;
	cout << "Punctuation of SigEp: " << countAllPunctuation(sigmaphiepsilon, 8) << endl << endl;

	cout << "Floating point of 425: " << countFloatingPointValues(fourtwofive, 8) << endl;
	cout << "Floating point of SigEp: " << countFloatingPointValues(sigmaphiepsilon, 8) << endl << endl;

	cout << "Duplicates of 425: " << removeDuplicatedValues(fourtwofive, 8) 
		<< ": " << endl;
	cout << "Duplicates of SigEp: " << removeDuplicatedValues(sigmaphiepsilon, 8)
		<< ": " << sigmaphiepsilon[4] << ": " << sigmaphiepsilon[5] << ": " << sigmaphiepsilon[6] << endl << endl;

	cout << "Replace all a's with Z's in 425: " << replaceAll(fourtwofive, 8, 'a', 'z') << ": " << fourtwofive[0] << " " << 
		" " << fourtwofive[2] << " " << fourtwofive[3] << endl;
	cout << "Replace all a's with Z's in SigEp: " << replaceAll(sigmaphiepsilon, 8, 'a', 'z') << ": " << sigmaphiepsilon[0] << ": "
		<< sigmaphiepsilon[4] << ": " << sigmaphiepsilon[5] << endl << endl;

	cout << "shift 425 right twice: " << shiftRight(fourtwofive, 6, 2, "waterpolo") << ": " << fourtwofive[1] << " " << fourtwofive[2]
		<< " " << fourtwofive[7] << endl;
	cout << "shift SigEp right three times: " << shiftRight(sigmaphiepsilon, 5, 3, "Jazz") << ": " << sigmaphiepsilon[2] << " " << sigmaphiepsilon[3] 
		<< " " << sigmaphiepsilon[4] << " " << sigmaphiepsilon[5] << " " << sigmaphiepsilon[6] << endl << endl;

	//return
	return 0;
}

int findMinimum(const string array[], int n) {
	//Return the index of the smallest item found in the array or -1
	//if n <= 0.  For example, for the array people[ 5 ] shown above, 
	//findMinimum( people, 5 ) should return the value 3, corresponding to 
	//the index of "daenerys".  If there are multiple duplicate minimum values,
	//you may return the index of either element that has this smallest value.
	if (n > 0) {
		//int index
		int index = 0;
		int min = array[0][0];
		//find the first string in alphabetical order in the array
		//check to see if any other string has the same first letter
		for (int i = 0; i < n; i++) {
			string s = array[i];
			int c = s[0];
			if (min > c) {
				min = c;
				index = i;
			}
			else if (min == c) {
				//if there are multiple strings with the same first letter, 
				//loop through the rest of the letters
				for (size_t k = 1; k < array[index].size(); k++) {
					if (array[index][k] > array[i][k]) {
						index = i;
					}
					else if (k = array[index].size() - 1) {
						if (array[i].size() < array[index].size()) {
							index = i;
						}
					}
				}
			}
		}
		//otherwise return the index
		return index;
	}
	//if n <= 0 return -1
	return -1;
}

int countAllPunctuation(const string array[], int n) {
	//Return the total number of punctuation symbols found in all the elements of 
	//the passed array argument.  For the purpose of this function, the characters '.' ,
	//',', '!', ';', ''', '-', '/', ':', '?', '"' count as punctuation symbols (that is, 
	//period, comma, exclamation mark, semicolon, apostrophe, dash, slash, colon, question 
	//mark, and double quote).  Return -1 if  n <= 0.  For example, for the array 
	//string data[ 4 ] = { "howard-", "ucla.", "howard", "ucla" };     
	//countAllPunctuation( data, 4 ) should return the value 2 while countAllPunctuation( data, -14 )   
	//should return -1. 
	if (n > 0) {
		//int variable
		int punctuation = 0;
		//count the punctuation
		for (int i = 0; i < n; i++) {
			for (size_t j = 0; j < array[i].size(); j++) {
				if (ifPunctuation(array[i], j)) {
					punctuation++;
				}
			}
		}
		return punctuation;
	}
	// if n <= 0, return -1
	return -1;
}

int countFloatingPointValues(const string array[], int n) {
	//Return the total number of floating - point values found in all the array elements of
	//the passed array argument.For the purpose of this function, a floating - point value 
	//should have the form #.#, where # is one of the digits 0 - 9.  The decimal point is optional but 
	//should only be found once for the element to count as a valid floating - point value.
	//Return - 1 if n <= 0.  For example, for the array     string data[4] = { "4.4.3.3", "44", "33.098", "33.098a" };     
	//countFloatingPointValues(data, 4) should return the value 2 while countFloatingPointValues(data, -14)   
	//should return -1.  According to this specification, all of the following are valid floatingPointValues :
	//"1.0", "1", ".0101", "0.0123".What I am after is the regular expression : (0 - 9) + (.)*(0 - 9)*  
	//That means one or more digit characters followed by an optional decimal point followed 
	//by additional optional digit characters.
	if (n > 0) {
		int decimal = 0;
		int floatingpoints = 0;
		bool other = false;
		//count floating points
		for (int i = 0; i < n; i++) {
			string matt = array[i];
			decimal = 0;
			other = false;
			for (size_t j = 0; j < matt.size(); j++) {
				char c = matt[j];
				switch (c) {
				case '.':
					decimal++;
					break;
				case '9': case '8': case '7': case '6': case '5': 
				case '4': case '3': case '2': case '1': case '0':
					break;
				default:
					other = true;
				}
			}
			if ((decimal < 2) && (other == false)) {
				floatingpoints++;
			}
		}
		return floatingpoints;
	}
	//if n <= 0 return -1
	return -1;
}

int removeDuplicatedValues(string array[], int n) {
	//This function should ensure that none of the array elements are the same.
	//All the non - duplicated values should be kept together at the front of the array and your
	//function should use "" (the empty string) to fill out the array as needed.
	//Return the number of elements which were removed or -1 if the array has no elements.For example, 
	//for the array  people[5]  shown above, removeDuplicatedValues(people, 5)  should return 0 and 
	//the array argument should be unchanged.However, removeDuplicatedValues(people, -5)  
	//should return -1.  And finally, for the array     string data[4] = { "happy", "days", "happy", "days" };     
	//removeDuplicatedValues(data, 4) should return the value 2 and the array argument should be changed to :
	//{ "happy", "days", "", "" };
	//-----------------------------------------------------------------------------------------
	//integer for number of duplicates
	int duplicates = 0;
	//test if n > 0
	if (n > 0) {
		for (int i = 0; i < n - 1; i++) {
			string degan = array[i];
			for (int j = i + 1; j < n; j++) {
				if (degan == array[j]) {
					duplicates++;
					for (int k = j; k < n; k++) {
						if (k == n - 1) {
							array[n - 1] = "";
						} else {
							array[k] = array[k + 1];
						}
					}
				}
			}
		}
		return duplicates;
	}
	//if n <= 0, return -1
	return -1;
}

int replaceAll(string array1[], int n, char letterToReplace, char letterToFill) {
	//This function should replace every occurrence of the letterToReplace value with the letterToFill value 
	//found in all the array elements of the passed array argument.  Return the number of letters that were 
	//replaced or -1 if the array has no elements.  For example, for the array  people[ 5 ]  shown above,  
	//replaceAll( people, 5, 'z', 'a' )  should return 0 and the array argument should be unchanged.   
	//However, replaceAll( people, -5, 'z', 'a' )  should return -1.  And finally, for the array     
	//string data[ 4 ] = { "happy", "days", "are here", "again" };     replaceAll( data, 4, 'a', 'z' ) 
	//should return the value 5 and the array argument should be changed to:   { "hzppy", "dzys", "zre here", "zgzin" }; 
	//----------------------------------------------------------------------------------------------------
	//int replaces
	int replaces = 0;
	//test if  n > 0
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			string kylie = array1[i];
			for (size_t j = 0; j < kylie.size(); j++) {
				if (kylie[j] == letterToReplace) {
					kylie[j] = letterToFill;
					array1[i] = kylie;
					replaces++;
				}
			}
		}
		return replaces;
	}
	//otherwise return -1
	return -1;
}

int shiftRight(string array[], int n, int amount, string placeholder) {
	//Adjust the items found in the array, shifting each value to the right by amount parameter, 
	//filling the resulting first amount elements of the array with the placeholder parameter and returning 
	//the number of times the placeholder value was used after all the shifting has been performed or -1 if the array has no elements.  
	//For example,  for the array  people[ 5 ]  shown above,  shiftRight( people, 5, 3, "foo" )  should return 3 and 
	//adjust the array to have the values { "foo", "foo", "foo", "samwell", "jon" };    However,    shiftRight( people, -5, 3, "foo" )   
	//should return -1.  Finally,    shiftRight( people, 5, 25, "foo" ) should return 5 and adjust the 
	//array to have the values  { "foo", "foo", "foo", "foo", "foo" };
	//------------------------------------------------------------------------------
	//test if n > 0
	if (n > 0) {
		if (amount < n) {
			//do this "amount" of times
			for (int i = 0; i < amount; i++) {
				//move all the elements to the right one index
				for (int j = n - 1; j > 0; j--) {
						array[j] = array[j - 1];
				}
				//insert placeholder at the beginning
				array[0] = placeholder;
			}
			return amount;
		}
		else {
			for (int i = 0; i < n; i++) {
				//replace all of the elements with string placeholder
				array[i] = placeholder;
			}
			return n;
		}
	}
	//otherwise return -1
	return -1;
}

bool ifPunctuation(string test, int index) {
	//input : string and the index
	//output: true if the character is punctuation markings, false if not
	char c = test[index];
	if (c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == '-' || c == '/'
		|| c == ':' || c == '\'') {
		return true;
	}
	//else
	return false;
}
