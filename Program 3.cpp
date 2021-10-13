// Name: Brandon Schroeder
// Course: CIS-165
// Last Update: 11/28/2017
// Description: Program to calculate employee payments

//*********************** Preprocessor Directives *********************
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>

using namespace std;

//******************************* main ********************************
int main(void)
		{
		const int 		regular_hours = 40;
		
		const double	class1 = 5.50, //job classification pay 1-5
						class2 = 6.00,
						class3 = 7.00,
						class4 = 9.00,
						class5 = 12.00;	
			
 		int		choice,
 				employ_id,
 				job_class;
 				
 		double	hours_worked,
 				hourly_rate,
 				regular_pay,
 				overtime,
 				overtime_pay,
 				total;
 
 		char	drive[2],
				disk_file[15],
				file[9],
				employ_name[25],
				message[51];

 		ofstream	outfile;

                                                        // input section
		system ("cls"); // clear the screen 

// remove this comment ans place your input statements here.
		cout << "Enter employee's name" << endl;
		cin.getline(employ_name, sizeof(employ_name) - 1);
		cout << "Enter employee's ID number" << endl;
		cin >> employ_id;
		cout << "Enter empolyee's job classification number" << endl;
		cin >> job_class;
		cout << "Enter the number of hours the employee worked" << endl;
		cin >> hours_worked;

                                                        // process section

// remove this comment ans place your process statements here.
		switch (job_class)
				{
				case 1: 	hourly_rate = class1;
							break;
				case 2: 	hourly_rate = class2;
							break;
				case 3: 	hourly_rate = class3;
							break;
				case 4: 	hourly_rate = class4;
							break;
				case 5: 	hourly_rate = class5;
							break;
				default:	hourly_rate = class1;
							strcpy(message,"***   The Employee's Job Classification is in error   ***");
				}
		
		if (hours_worked >= 40)
			{
			regular_pay = regular_hours * hourly_rate;
			}
			else
			{
			regular_pay = hours_worked * hourly_rate;
			}
		
		if (hours_worked > 40)
			{
			overtime = (hours_worked - regular_hours);
			overtime_pay = overtime * 1.5 * hourly_rate;
			}
			else
			{
			overtime_pay = 0;
			overtime = 0;
			}
		
		total = regular_pay + overtime_pay;

                           								// output section
  		system ("cls");
  		cout << "Output to console (1) or disk file (2):   ";
  		cin >> choice;
  		if ( choice == 1 )
	  		{
			system ("cls");
			outfile.open("con");
	  		}
  			else				  //routine allows interactive entry of external file name
	  		{
			cout << "Which drive:  a, b, c, d, e, or f ?   ";
			cin >> drive;
			strcpy(disk_file, drive);
			strcat(disk_file, ":\\");
			cout << "Enter a results file name:   ";
			cin >> file;
			strcat(disk_file, file);
			strcat(disk_file, ".txt");
			outfile.open(disk_file);
			}
  		outfile << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);

  // output statements
  		outfile << setw(26) << " " << "WorkHard Corporation" << endl;
  		outfile << setw(26) << " " << "====================" << endl;
  		outfile << "Employee Name: " << employ_name << setw(sizeof(employ_name) - strlen(employ_name) + 2) << " " << "ID Number: " << employ_id << endl << endl;
  		outfile << "Job Classification: " << setw(7) << job_class << setw(15) << " " << "Total Hours Worked: " << setw(7) << hours_worked << endl << endl;
  		outfile << "Hourly Rate: " << setw(7) << " " << setw(7) << hourly_rate << setw(15) << " " << "Overtime Hours: " << setw(4) << " " << setw(7) <<  overtime << endl << endl;
  		outfile << "Regular Pay: " << setw(7) << " " << setw(7) << regular_pay << setw(15) << " " <<"Overtime Pay: " << setw(6) << " " << setw(7) << overtime_pay << endl << endl;
  		outfile << setw(19) << " " << "Total Earnings ......... " << total << endl << endl;
  		if (strlen(message) > 10){
  			outfile << setw(8) << " " << message << endl;
		  }
  
  		outfile.close();
  		cout << endl << endl;    // provides blank line before pause display message
  		system ("pause");
  		return 0;
  }
