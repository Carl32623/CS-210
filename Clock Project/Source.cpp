/** This program will add one to each unit of time as chosen by the user.
*	Use a menu to pick the unit of time (hours, minutes, seconds).
*	Print out the clock in two formats 12hr and 24 hr.
*
*	Author: Carl LaLonde
*
*	Date: 1/28/2024
*/

// Global Variables
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int hour12;
int hour24;
int minute;
int second;

//Gets time from local machine.
void GetTime() {
	time_t ttime = time(0); //Declare ttime as argument for local function.
	tm* local_time = localtime(&ttime); //Holds local time.

	hour12 = local_time->tm_hour % 12; // Convert to 12-hour format
	hour24 = local_time->tm_hour;
	minute = local_time->tm_min;
	second = local_time->tm_sec;
	
}

//Character loop for time output.
void nCharString(int count) {
	for (int i = 0; i < count; ++i) {
		cout << "*";
	}
}

// displays time shown in 12hour and 24hour format
void displayTime() {
	nCharString(26); cout << endl;
	cout << "*     12-Hour Clock      *" << endl;
	cout << "*       " 
		<< setw(2) << setfill('0') << hour12 << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second 
		<< "         *" << endl;
	nCharString(26); cout << endl;
	cout << endl;
	nCharString(26); cout << endl;
	cout << "*     24-Hour Clock      *" << endl;
	cout << "*       "
		<< setw(2) << setfill('0') << hour24 << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second
		<< "         *" << endl;
	nCharString(26); cout << endl;
	cout << endl;
}

//This function increases the hour by one.
void addOneHour() {
	if (hour12 < 12) {
		hour12 = hour12 + 1;
	}
	else if(hour12 == 12) {
		hour12 = 1;
	}
	if (hour24 < 24) {
		hour24 = hour24 + 1;
	}
	else if (hour24 == 24) {
		hour24 = 1;
	}
}

//This function increases the minutes by one as well as the hour if the minutes run over 59.
void addOneMinute() {
	if (minute < 59) {
		minute = minute + 1;
	}
	else {
		minute = 0;
		if (minute == 0) {
			addOneHour();
		}
	}
}
/**This function adds one second as well as the minutes if the seconds run over 59 and
* the hours if the minutes run over 59.*/
void addOneSecond() {
	if (second < 59) {
		second = second + 1;
	}
	else {
		second = 0;
		if (second == 0) {
			addOneMinute();
			if (minute == 0) {
				addOneHour();
			}
		}
	}
}

//Prints out a menu and asks for user choice.
void displayMenu() {
	nCharString(26); cout << endl;
	cout << "* 1 - Add One Hour       *" << endl;
	cout << "* 2 - Add One Minute     *" << endl;
	cout << "* 3 - Add One Second     *" << endl;
	cout << "* 4 - Exit Program       *" << endl;
	nCharString(26); cout << endl;
}


/** This program will diplay user menu options, ask user for choice
*	of option and will update time as user requests.  Then will output 
*	updated time.*/
int main() {
	GetTime(); //Initializes time.

	char menuChoice; //character variable menuChoice.

	/**do while loop to displayTime, displayMenu, ask user for user 
	* for input for menuChoice until user enteres 4 to quit program.*/
	do {
		displayTime();
		displayMenu();
		cout << "Enter Menu Choice: " << endl;
		cin >> menuChoice;

		// switch statement runs through and executes user menu choices.
		switch (menuChoice) {
		case '1':
			addOneHour();
			break;

		case '2':
			addOneMinute();
			break;

		case '3':
			addOneSecond();
			break;

		case '4':
			cout << "Good Bye..." << endl;
			break;

		default:
			cout << "Invalid Entry..." << endl;
		}
	} while (menuChoice != '4');


	return 0;
}
