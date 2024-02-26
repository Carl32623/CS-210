/** This program will allow students to enter values for Initial Investment Amount,
* Monthly Deposit, Annual Interest, and Number of Years.  The program will then calculate
* and output reports based on the useres data to show yearly earnings with and without 
* monthly contributions.  
* 
* Author: Carl LaLonde
* Date: 2/10/2024
*/

#pragma once
using namespace std;

#ifndef INVESTMENTAPP_H
#define INVESTMENTAPP_H


class InvestmentApp {
public:
    //Constructor
    InvestmentApp(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears);

    // Accessors
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetAnnualInterest() const;
    int GetNumYears() const;

    // Mutators
    void SetInitialInvestment(double amount);
    void SetMonthlyDeposit(double amount);
    void SetAnnualInterest(double rate);
    void SetNumYears(int years);

    // Other methods
    void DisplayDataInput()const;
    void DisplayBalances()const;
 
private:
    int numYears;
    double
        initialInvestment,
        monthlyDeposit,
        annualInterest;
};
#endif

