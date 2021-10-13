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
link* front;
link* temp;
link* step;
link* end;

//**************************** Functions ******************************
int enQue(){
	if(front == 0){
		front = new link;
		end = front;
		end->next = 0;
		cout << "The queue has been started" << endl;
	}else{
		temp = new link;
		end->next = temp;
		end = temp;
		end->next = 0;
	}
	cout << "Enter name" << endl;
	cin >> end->name;
	cout << "Enter age" << endl;
	while(!(cin >> end->age)){
	        cout << " That is not a valid choice" << endl;
	        cout << endl << "Please enter a number:";
	        cin.clear();
	        cin.ignore(123, '\n');
	}
	count ++;
	cout << "Node has been added" << endl;
	return 0;
}

int deQue(){
	if(front == 0){
		cout << "The queue is empty" << endl;
	}else{
		temp = front;
		front = front->next;
		cout << temp->name << " has been deQued" << endl;
		delete temp;	
	}
	return 0;
}

int rFront(){
	if(front==0){
		cout << "Queue is empty" << endl;
		return 0;
	}else{
		cout << front->name << " is " << front->age << " years old and at the front of the queue." << endl;
	}
}

int purge(){
	if(front==0){
		cout << "The queue is already empty" << endl;
		return 0;
	}else{
		while(front->next!=0){
			deQue();
		}
		deQue();
		cout << "The queue has been purged" << endl;
		return 0;
	}
}

int read(){
	if(front==0){
		cout << "the queue is empy" << endl;
		return 0;
	}else{
		temp = front;
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
	front = 0;

//******************************* process section
	choose = 'n';
	do{
        cout << "\n__________Menu__________\n"
             << "1) Add to the queue\n"
             << "2) Remove from the queue\n"
             << "3) View front of the queue\n"
             << "4) Purge the queue\n"
             << "5) View the queue\n"
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
                enQue();
                break;
            case 2:
                deQue();
                break;
            case 3:
                rFront();
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
