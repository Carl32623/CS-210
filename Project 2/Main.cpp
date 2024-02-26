/** This program will allow students to enter values for Initial Investment Amount,
* Monthly Deposit, Annual Interest, and Number of Years.  The program will then calculate
* and output reports based on the useres data to show yearly earnings with and without
* monthly contributions.
*
* Author: Carl LaLonde
* Date: 2/10/2024
*/

#include "INVESTMENTAPP.H"
#include <iostream>

using namespace std;


//This is the main program that takes user input and calculates and outputs data.
//Calls DisplayDataInput() function and DisplayBalances() Function.
int main() {
    double 
        initialInvestment,
        monthlyDeposit,
        annualInterest;
    int
        numYears,

    //Validates that user entered data is non-negative value.
    do {
        cout << "Enter Initial Investment Amount: $";
        cin >> initialInvestment;
        if (initialInvestment < 0) {
            cout << "Initial Investment must be non-negative value." << endl;
        }
    } while (initialInvestment < 0);
    do {
        cout << "Enter Monthly Deposit: $";
        cin >> monthlyDeposit;
        if (monthlyDeposit < 0) {
            cout << "Monthly Deposit must be non-negative value." << endl;
        }
    } while (monthlyDeposit < 0);
    do {
        cout << "Enter Annual Interest (%): ";
        cin >> annualInterest;
        if (annualInterest < 0) {
            cout << "Annual Interest must be non-negative value." << endl;
        }
    } while (annualInterest < 0);
    do {
        cout << "Enter Number of Years: ";
        cin >> numYears;
        if (numYears < 0) {
            cout << "Years must be non-negative value." << endl;
        }
    } while (numYears < 0);

    //Outputs DisplayDataInput Function and DisplayBalances based on user input.
    InvestmentApp myInvestment(initialInvestment, monthlyDeposit, annualInterest, numYears);
    myInvestment.DisplayDataInput();
    myInvestment.DisplayBalances();



    return 0;
}
