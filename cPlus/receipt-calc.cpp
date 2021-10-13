// Name: Brandon Schroeder
// Course: CIS-165
// Last Update: 10/27/2017
// Description: program to calculate a customer bill based on the number of photos submitted and the number of reprints ordered.

//*********************** Preprocessor Directives *********************
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;

//******************************* main ********************************
int main(void)
{
	const double PHOTO_PRICE = 0.50, TAX = 0.07;  //Update with your stats tax amount
	char name[25], date[21];
	int photos, reprints, total_prints;
	double base_price, tax_amount, final_price;
	
    cout << "Enter your name" << endl;
	cin >> ws;
	cin.getline(name, (sizeof(name) - 1) );
	cout << endl << "Enter today's date MM/DD/YYYY" << endl;
	cin >> ws;
	cin.getline(date, (sizeof(date) - 1) );  //.getline used incase user enters date in a diffrent format
	cout << endl<<  "Enter the number of photos submited" << endl;
	cin >> photos;
	cout << endl << "Enter the desired number of reprints" << endl;
	cin >> reprints;
	
	total_prints = photos * reprints;
	base_price = total_prints * PHOTO_PRICE;  //Price before tax
	tax_amount = base_price * TAX;
	final_price = base_price + tax_amount;  //Price with tax
	
	system ("cls"); //Clear screen before printing results
	
	//===== Print Results =====
	cout << "MOREPRINTS Photo Store" << endl;
	cout << "----------------------" << endl << endl;
	
	cout << "Date: " << date << endl << endl;
	
	cout << setw(5) << "Name:" << setw(20) << name << endl << endl;
	
	cout << setw(10) << "Photos in:" << setw(15) << photos << endl;
	cout << setw(17) << "Reprints Ordered:" << setw(8) << reprints << endl;
	cout << setw(15) << "Total Reprints:" << setw(10) << total_prints << endl;
	cout << setw(14) << "Price/Reprint:" << setw(11) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << PHOTO_PRICE << endl << endl;
	
	cout << setw(13) << "Reprint cost:" << setw(12) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << base_price << endl;
	cout << setw(4) << "Tax:" << setw(21) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << tax_amount << endl;
	cout << setw(11) << "Total Cost:" << setw(14) << setiosflags(ios::showpoint | ios::fixed) << setprecision(2) << final_price;
	
	
    cout << endl << endl;	// provides blank line before pause display message
    system ("pause");
    return 0;
}

