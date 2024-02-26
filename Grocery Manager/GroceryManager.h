/**This program read items from an inventory text file, allows a user to search search the
* inventory for a specific item and will output to the user how many specified items are in
* the inventory text file.
*
* Author: Carl LaLonde
* Date: 2/25/2024
*/
#ifndef GROCERYMANAGER_H
#define GROCERYMANAGER_H

#include <string>
#include <map>

using namespace std;

//class GroceryManager
class GroceryManager {
private: //private variables and functions
	map<string, int>* itemFrequencies;
	string inputFileName;
	string outputFileName;

	void loadInputFile();

public: //public functions
	GroceryManager(const string& inputFile, const string& outputFile);
	~GroceryManager();

	void displayMenu();
	void itemFrequency(const string& item);
	void printAllItemsFrequency();
	void printHistogram();
	void saveFrequencyData();

};

#endif GROCERYMANAGER_H
