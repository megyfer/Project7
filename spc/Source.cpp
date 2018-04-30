// Chapter 5, Programming Challenge 16: Savings Account Balance
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double yrInterestRate;       // Annual interest rate
	double moInterestRate;       // Monthly interest rate
	double balance;              // Account balance
	double deposited;            // Amount deposited in a single month
	double withDrawn;            // Amount withdrawn in a single month
	double moIntPaid;            // Interest paid in a single month
	double totalDeposits = 0; // Total of all deposits
	double totalWithdrawals = 0; // Total of all withdrawals
	double totalInterest = 0; // Total interest earned
	int    months;               // Number of months passed

	// Set up the output formatting.
	cout << fixed << showpoint << setprecision(2);

	// Get the annual interest rate.
	cout << "Enter the annual interest rate "
		<< "on the account (e.g. .04): ";
	cin >> yrInterestRate;

	// Validate the interest rate.
	while (yrInterestRate < 0)
	{
		cout << "Interest rate must be non-negative: ";
		cin >> yrInterestRate;
	}

	// Get the starting balance.
	cout << "Enter the starting balance: ";
	cin >> balance;

	// Validate the starting balance.
	while (balance <= 0)
	{
		cout << "The balance must be greater than 0: ";
		cin >> balance;
	}

	// Get the number of months that the account
	// has been open.
	cout << "How many months have passed since the ";
	cout << "account was established? ";
	cin >> months;

	// Validate the number of months.
	while (months < 0)
	{
		cout << "Number of months must be non-negative: ";
		cin >> months;
	}

	// Calculate the monthly interest rate.
	moInterestRate = yrInterestRate / 12.0;

	// Process the transactions.
	for (int count = 1; count <= months; count++)
	{
		// Display the month number.
		cout << "\nMonth " << count << endl;

		// Input the amount deposited this month.
		cout << "\tTotal deposits for this month: $";
		cin >> deposited;

		// Validate the amount deposited this month.
		while (deposited < 0)
		{
			cout << "\tDeposits must be zero or greater. "
				<< "Please re-enter: ";
			cin >> deposited;
		}

		// Input the amount withdrawn this month.
		cout << "\tTotal withdrawals for this month: $";
		cin >> withDrawn;

		// Validate the amount withdrawn this month.
		while (withDrawn < 0)
		{
			cout << "\tWithdrawals must be zero or greater. "
				<< "Please re-enter: ";
			cin >> withDrawn;
		}

		// Calculate the totals.
		balance += deposited;          // Add deposits to balance
		totalDeposits += deposited;    // Total of deposits
		balance -= withDrawn;          // Subtract withdrawals from balance
		totalWithdrawals += withDrawn; // Total of withdrawals

		// Determine if we have a negative balance.
		if (balance < 0)
		{
			cout << "\nThe account has a balance of $" << balance << endl;
			cout << "Because the balance is negative, the account ";
			cout << "has been closed.\n";
			break;   // Break out of loop! The account is closed.
		}

		// Calculate the monthly interest paid.
		moIntPaid = balance * moInterestRate;

		// Accumulate the total interest.
		totalInterest += moIntPaid;

		// Add the interest to the balance.
		balance += moIntPaid;
	}

	// Display results
	cout << endl;
	cout << "Ending balance: \t   $" << setw(10)
		<< balance << endl;
	cout << "Amount of deposits: \t   $" << setw(10)
		<< totalDeposits << endl;
	cout << "Amount of withdrawals: \t   $" << setw(10)
		<< totalWithdrawals << endl;
	cout << "Amount of interest earned: $" << setw(10)
		<< totalInterest << endl << endl;

	return 0;
}