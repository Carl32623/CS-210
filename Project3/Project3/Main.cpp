/**This program read items from an inventory text file, allows a user to search search the
* inventory for a specific item and will output to the user how many specified items are in
* the inventory text file.
*
* Author: Carl LaLonde
* Date: 2/25/2024
*/
#include "GroceryManager.h"
#include <iostream>


using namespace std;

int main() {
	//Creates a GroceryManager object with the input and output file names "Inventory.txt" and "frequency.dat".
	GroceryManager manager("Inventory.txt", "frequency.dat");
	int choice;
	string input;

	do {//do while loop to process user input choice from main menu.
		manager.displayMenu();
		cin >> choice;

		switch (choice) {
		case 1: {
			string item;
			cout << endl << "Enter item to search: " << endl;
			cin >> item;
			cout << endl;
			manager.itemFrequency(item);
			break;
		}
		case 2:
			cout << endl;
			manager.printAllItemsFrequency();
			break;

		case 3:
			cout << endl;
			manager.printHistogram();
			break;

		case 4:
			cout << endl << "Goodbye..." << endl;
			manager.saveFrequencyData();
			break;

		default:
			cout << endl << "Invalid Entry. Try Again." << endl << endl;
			break;
		}
	} while (choice != 4);

	return 0;
}