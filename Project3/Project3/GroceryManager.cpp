/**This program read items from an inventory text file, allows a user to search search the
* inventory for a specific item and will output to the user how many specified items are in
* the inventory text file.
*
* Author: Carl LaLonde
* Date: 2/25/2024
*/
#include "GroceryManager.h"
#include <iostream>
#include <fstream>
#include <ostream>


using namespace std;
/**Constructor
* uses parameters inputFile to load the .txt file and
* outputFile to save the data to a .dat file.
*/
GroceryManager::GroceryManager(const string& inputFile, const string& outputFile) {
	inputFileName = inputFile;
	outputFileName = outputFile;
	itemFrequencies = new map<string, int>();
	loadInputFile();
}
//Deconstructor
GroceryManager::~GroceryManager() {
	delete itemFrequencies;
}
/**This function will display a menu from which the user
* will be able to choose from.
*/
void GroceryManager::displayMenu() {
	cout << "Menu" << endl;
	cout << "1. Search Item Frequency." << endl;
	cout << "2. Print All Items Frequency." << endl;
	cout << "3. Print Histogram." << endl;
	cout << "4. Exit." << endl;
	cout << "Enter Menu Choice:" << endl;
}
/**This function loads the specified file, in this case, "Inventory.txt",
* also checking to see if the file is already open.
*This function also updates the frequency of each item in the list.
*/
void GroceryManager::loadInputFile() {
	ifstream inFS(inputFileName);
	if (!inFS.is_open()) {
		cout << "Unable to open file " << inputFileName << endl;
		return;
	}
	string item;
	while (inFS >> item) {
		++(*itemFrequencies)[item];
	}
	inFS.close();
}
/**This function prints out the specified item and the frequency the
* specified item occurs in the file using parameter string item.
*/
void GroceryManager::itemFrequency(const string& item) {
	auto it = itemFrequencies->find(item);
	if (it != itemFrequencies->end()) {
		cout << "Frequency of " << item << ": " << it->second << endl << endl;
	}
	else {
		cout << "Item not found." << endl << endl;
	}
}
/**This function will print out all items within the file and the
* frequency of each item.
*/
void GroceryManager::printAllItemsFrequency() {
	for (const auto& pair : (*itemFrequencies)) {
		cout << pair.first << " " << pair.second << endl;
	}
	cout << endl;
}
/**This function also prints out all the items within the file with the
* frequency of each item but instead of using a number for the frequency,
* the frequency of each item is shown with the character "*" for each time
* the item appears in the list.
*/
void GroceryManager::printHistogram() {
	int i;
	for (const auto& pair : (*itemFrequencies)) {
		cout << pair.first << " ";
		for (i = 0; i < pair.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}
/**This function will save the item frequencies to an
* output file, in this case "frequency.dat".
*/
void GroceryManager::saveFrequencyData() {
	ofstream outFS(outputFileName);
	if (!outFS.is_open()) {
		cout << "Unable to open file " << outputFileName << endl;
		return;
	}
	for (const auto& pair : (*itemFrequencies)) {
		outFS << pair.first << " " << pair.second << endl;
	}
	outFS.close();
}
