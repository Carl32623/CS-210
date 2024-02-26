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
#include <iomanip>
using namespace std;

// Constructor 
InvestmentApp::InvestmentApp(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears) {
    this->initialInvestment = initialInvestment;
    this->monthlyDeposit = monthlyDeposit;
    this->annualInterest = annualInterest;
    this->numYears = numYears;
}

// Accessors
double InvestmentApp::GetInitialInvestment() const {
    return initialInvestment;
}

double InvestmentApp::GetMonthlyDeposit() const {
    return monthlyDeposit;
}

double InvestmentApp::GetAnnualInterest() const {
    return annualInterest;
}

int InvestmentApp::GetNumYears() const {
    return numYears;
}

// Mutators
void InvestmentApp::SetInitialInvestment(double amount) {
    this->initialInvestment = amount;
}

void InvestmentApp::SetMonthlyDeposit(double amount) {
    this->monthlyDeposit = amount;
}

void InvestmentApp::SetAnnualInterest(double rate) {
    this->annualInterest = rate;
}

void InvestmentApp::SetNumYears(int years) {
    this->numYears = years;
}
/**This function will print out a user entered number of user 
* entered characters.  Parameters(int count, char sym)
*/
void nCharString(int count, char sym) {
    for (int i = 0; i < count; ++i) {
        cout << sym;
    }
}
//This function prints out a banner for the balances with and without monthly deposits.
void BalancesBanner() {
    cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
    nCharString(66, '='); cout << endl;
    cout << "Year\t\tYear End Balance\t Year End Earned Interest" << endl;
    nCharString(66, '-'); cout << endl;
}

//This function displays the user entered data.
void InvestmentApp::DisplayDataInput()const {
    nCharString(36, '*'); cout << endl;
    nCharString(11, '*'); cout << "  Data Input  "; nCharString(11, '*'); cout << endl;
    cout << "Initial Investment Amount: $" << initialInvestment << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest: %" << annualInterest << endl;
    cout << "Number of years: " << numYears << endl;
    cout << "Press any key to continue . . ." << endl;
    nCharString(36, '*'); cout << endl << endl;
    cin.ignore();
}

//This function displays, for each year, balances and interest earned with and withou mothly deposits.
void InvestmentApp::DisplayBalances()const {
    double openingAmount = initialInvestment;
    double depositedAmount = monthlyDeposit;
    double interestRate = annualInterest / 100.0;
    int months = numYears * 12;

    cout << fixed << setprecision(2);

    //Without monthly deposits.
    BalancesBanner();
    for (int i = 1; i <= numYears; ++i) {
        double interest = openingAmount * interestRate;
        double closingBalance = openingAmount + interest;
        cout << i << "\t\t\t$" << closingBalance << "\t\t\t\t$" << interest << endl;
        openingAmount = closingBalance;
    }
    cout << endl;

    //With monthly deposits.
    openingAmount = initialInvestment;
    BalancesBanner();
    for (int i = 1; i <= numYears; ++i) {
        double totalInterest = 0;
        for (int j = 1; j <= 12; ++j) {
            double monthlyInterest = openingAmount * (interestRate / 12.0);
            openingAmount += monthlyDeposit;
            totalInterest += monthlyInterest;
            openingAmount += monthlyInterest;
        }
        cout << i << "\t\t\t$" << openingAmount << "\t\t\t$" << totalInterest << endl;
    }
}

