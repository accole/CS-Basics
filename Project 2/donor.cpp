//Adam Cole

//Project 2

//inlcude statements
#include <iostream>
#include <string>
using namespace std;

//declare function methods before the main method
bool validgender(string response);
bool validdonor(string gender, int age, int height, int weight);

int main() {
	//information variables
	string donorname;
	int age;
	int weight;
	string gender;
	int height;

	//get information from user while checking
	//for incorrect responses, if incorrect response
	//then exit the code.
	//--------------------------------------


	//Donor name:
	cout << "Donor name: ";
	getline(cin, donorname);
	if (donorname == "") {
		//exit the code at the first error
		cout << "--- You must enter a valid name." << endl;
		return(-1);
	}

	//Gender:
	cout << "Gender: ";
	getline(cin, gender);
	if (validgender(gender) == false) {
		cout << "--- You must enter a valid gender." << endl;
		return(-1);
	}

	//Age:
	cout << "Age: ";
	cin >> age;
	if (age <= 0) {
		cout << "--- You must enter a valid age." << endl;
		return(-1);
	}

	//Weight:
	cout << "Weight: ";
	cin >> weight;
	if (weight <= 0) {
		cout << "--- You must enter a valid weight." << endl;
		return(-1);
	}

	//Height:
	cout << "Height: ";
	cin >> height;
	if (height <= 0) {
		cout << "--- You must enter a valid height." << endl;
		return(-1);
	}

	//test for if the donor can give blood
	bool donate;
	donate = validdonor(gender, age, height, weight);
	if (donate == true) {
		cout << "--- Yes, " << donorname << " you can donate blood." << endl;
	}
	else {
		cout << "--- No, " << donorname << " you cannot donate blood." << endl;
	}


	//return statement
	return 0;
}

bool validgender(string response) {
	//test the gender response
	//if one of the 6 predetermined genders, return true
	//if not, return false
	if (response == "Male" || response == "Female" || response == "Queer" ||
		response == "Different" || response == "Trans Male" || response == "Trans Female") {
		return true;
	}
	return false;
}

bool validdonor(string gender, int age, int height, int weight) {
	//tests to see if any conditions given by the user
	//makes them invalid for donation
	//return true if they can donate
	//false if they cannot
	//-------------------
	//no matter what if they are younger than 16 or lighter than 110
	//	pounds they can't donate
	if (age < 16 || weight < 110) {
		return false;
	}
	//test gender since the gender determines following elligibility
	if (gender == "Male") {
		//male
		if (height < 60) {
			//less than 5' tall, not elligible
			return false;
		}
		return true;
	}
	else if (gender == "Female") {
		//female
		if (height < 58) {
			//if less than 4'10" can't donate
			return false;
		}
		else if (height == 58) {
			//if 4'10" must weight 146+
			if (weight < 146) {
				return false;
			}
			return true;
		}
		else if (height == 59) {
			//if 4'11" must weigh 142+
			if (weight < 142) {
				return false;
			}
			return true;
		}
		else {
			//over 5'
			return true;
		}
	}
	else {
		//Trans Male, Trans Female, Queer, Different
		//if older than 22, they can donate
		if (age < 23) {
			return false;
		}
		return true;
	}
}
