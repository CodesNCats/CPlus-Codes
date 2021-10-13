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
struct Link{
	int id;
	string name;
	int age;
	Link* next;
};

int count;
int id;
int userInput;
string name;
char choose;
Link* start = 0;
Link* end = 0;
Link* caboose; //tails the active links
Link* cargo; //ether contains a link to be added or the link to be edited or printed
Link* engine; //leads the travel down the link list during search and insert

//**************************** Functions ******************************
int add(){
	cargo = new Link;
	cout << "Enter ID" << endl;
	while(!(cin >> cargo->id)){
	    cout << " That is not a valid choice" << endl;
	    cout << endl << "Please enter a number:";
	    cin.clear();
	    cin.ignore(123, '\n');
	}
	cout << "Enter name" << endl;
	cin >> cargo->name;
	cout << "Enter age" << endl;
	cin >> cargo->age;
	cargo->next = 0;
	
	if(start == 0){
		start = cargo;
		cout << "The link list has been started" << endl;
	}else{
		engine = start;
		if(engine->id >= cargo->id){
			cargo->next = start;
			start = cargo;
		}else if(engine->next == 0){
			start->next = cargo;
		}else{
			while(1){
				caboose = engine;
				engine = engine->next;
				if(engine->id >= cargo->id){
					caboose->next = cargo;
					cargo->next = engine;
					break;
				}else if(engine->next == 0){
					engine->next = cargo;
					cargo->next = 0;
		            break;
				}
			}
	    }
	}
	count ++;
	return 0;
}

int remove(){
	if(start == 0){
		cout << "The link list is empty" << endl;
	}else{
        cout << "Please enter the name of the the node to be removed" << endl;
        cin >> name;
        
		engine = start;
		if(engine->name == name){
			cargo = engine;
			if(start->next == 0){
				start = 0;
			}else{
				start = start->next;
			}
			delete cargo;
		}else if(engine->next == 0){
			cout << "No file was found with that name" << endl;
		}else{
			while(engine->next != 0){
				caboose = engine;
				engine = engine->next;
				if(engine->name == name){
					cargo = engine;
					if(engine->next == 0){
						caboose->next = 0;
					}else{
						engine = engine->next;
						caboose->next = engine;
					}
					delete cargo;
					break;
				}else if(engine->next == 0){
					cout << "No file was found with that name" << endl;
					break;
				}
			}
		}
	}
	count --;
	return 0;
}

int find(){
	if(start == 0){
		cout << "The link list is empty" << endl;
	}else{
        cout << "Please enter a name to search" << endl;
        cin >> name;
		engine = start;
			do{
				if(engine->name == name){
					cout << engine->id << ") " << engine->name << " is " << engine->age << "   next:" << engine->next << endl;
					break;
				}else if(engine->next == 0){
					cout << "No file was found with that name" << endl;
					break;
				}
				engine = engine->next;
			}while(1);
		}
	return 0;
}

int mod(){
	if(start == 0){
		cout << "The link list is empty" << endl;
	}else{
        cout << "Please enter a name to modify" << endl;
        cin >> name;
		engine = start;
			do{
				if(engine->name == name){
					cout 	<< engine->id << ") Name:" << engine->name << "   Age:" << engine->age << "  has been selected " << endl
						 	<< "Enter a new name:";
					cin >> engine->name;
					cout << endl << "enter a new age:";
					cin >> engine->age;
					break;
				}else if(engine->next == 0){
					cout << "No file was found with that name" << endl;
					break;
				}
				engine = engine->next;
			}while(1);
		}
	return 0;
}

int read(){
	if(start == 0){
		cout << "The link list is empty" << endl;
	}else{
		engine = start;
		while(engine->next != 0){
			cout << engine->id << ") " << engine->name << " is " << engine->age << endl;
			engine = engine->next;
		}
		cout << engine->id << ") " << engine->name << " is " << engine->age << endl;
	}
	return 0;
}

//******************************* main ********************************
int main(void){
	

//******************************* process section
	choose = 'n';
	do{
        cout << "" << endl;
        cout << "Menu :\n"
             << "1) Add\n"
             << "2) Remove\n"
             << "3) Find\n"
             << "4) Modify\n"
             << "5) View List\n"
             << "6) Quit.\n";
        cout<<"Please enter a number between 1 and 6: ";
        cin >> userInput;
        system("CLS");
        cout<<"\n_________________________________\n";
        
        switch(userInput){
            case 1:
                add();
                break;
            case 2:
                remove();
                break;
            case 3:
                find();
                  break;
            case 4:
            	mod();
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
