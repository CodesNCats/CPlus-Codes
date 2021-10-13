// Name: Brandon Schroeder

//*********************** Preprocessor Directives *********************
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//**************************** Constants/Structures/Variables ******************************
struct link{
	string name;
	int age;
	link* next;
};

int count;
int userInput;
char choose;
link* top;
link* temp;
link* step;

//**************************** Functions ******************************
int push(){
	if(top == 0){
		top = new link;
		top->next = 0;
		cout << "The stack has been started" << endl;
	}else{
		temp = new link;
		temp->next = top;
		top = temp;
	}
	cout << "Enter name" << endl;
	cin >> top->name;
	cout << "Enter age" << endl;
	while(!(cin >> top->age)){
	        cout << " That is not a valid choice" << endl;
	        cout << endl << "Please enter a number:";
	        cin.clear();
	        cin.ignore(123, '\n');
	}
	count ++;
	cout << "Node has been added" << endl;
	return 0;
}

int pop(){
	if(top == 0){
		cout << "The stack is empty" << endl;
	}else{
		temp = top;
		top = top->next;
		cout << temp->name << " has been popped" << endl;
		delete temp;	
	}
	return 0;
}

int rTop(){
	if(top==0){
		cout << "Stack is empty" << endl;
		return 0;
	}else{
		cout << top->name << " is " << top->age << " years old and ontop of the stack." << endl;
	}
}

int purge(){
	if(top==0){
		cout << "The stack is already empty" << endl;
		return 0;
	}else{
		while(top->next!=0){
			pop();
		}
		pop();
		cout << "The stack has been purged" << endl;
		return 0;
	}
}

int read(){
	if(top==0){
		cout << "The stack is empty" << endl;
		return 0;
	}else{
		temp = top;
		while(temp->next!=0){
			cout << temp->name << " is " << temp->age << " years old." << endl;
			temp = temp->next;
		}
		cout << temp->name << " is " << temp->age << " years old." << endl;
		return 0;
	}
}

//******************************* main ********************************
int main(void){
	top = 0;

//******************************* process section
	choose = 'n';
	do{
        cout << "\n__________Menu__________\n"
             << "1) Push to stack\n"
             << "2) PoP from stack\n"
             << "3) View top of the stack\n"
             << "4) Purge the stack\n"
             << "5) View the stack\n"
             << "6) Quit\n";
        cout << "Please enter a number between 1 and 6: ";
        while(!(cin >> userInput)){
	        cout << " That is not a valid choice" << endl;
	        cout << endl << "Please enter a number between 1 and 6:";
	        cin.clear();
	        cin.ignore(123, '\n');
	     }
        system("CLS");
        
        switch(userInput){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                rTop();
                  break;
            case 4:
                purge();
                  break;
            case 5:
                read();
                  break;
            case 6:
                cout<<"\nto QUIT press 'y' or 'Y': ";
                cin>>choose;
                cout<<endl;
                break;
        }
    }
    while(choose!='y'&&choose!='Y');

//******************************* output section
  	
  	
}
