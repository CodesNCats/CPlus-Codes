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

using namespace std;

//**************************** Constants/Structure/Variables ******************************
int state = 1;									//keeps track of the current state
int endP = 0;									//Used to keep the program running
string binary;									//Holds the binary code
//**************************** Functions ******************************
void updateState(char input){					//updates the state based on the input and current state of the machine
	switch (state){
    case 1: 
    	if(input == '0'){
    		return;
		}else{
			state = 2;
			return;
		}
        break;
    case 2: 
    	if(input == '0'){
    		state = 1;
    		return;
		}else{
			state = 3;
			return;
		}
        break;
    case 3: 
    	if(input == '0'){
    		state = 4;
    		return;
		}else{
			return;
		}
        break;
    case 4:
    	if(input == '0'){
    		state = 1;
    		return;
		}else{
			state = 5;
			return;
		}
    	break;
    case 5:
    	return;
    	break;
    default: 
    	return;
	}
};

//******************************* input section
int main(){
	while(endP == 0){							//Keep looping program, no end functions are included
		int test = 1;
		cout << "Enter your binary code: ";
		while(test != 0){ 						//If an invalid character is entered, has the user renter the code
			cin >> binary;
			for(int i = 0; i < binary.length(); i++){
				if(binary[i]!='0' && binary[i]!='1'){	//Checks for invalid characters
					test = 1;
					cout << "None binary element detected, resubmit binary code: ";
					i = binary.length();
				}else{
					test = 0;
				}
			}
		}
		
		
//******************************* process section
		cout << "State: " << state;				//show the user changes in state
		for (int i = 0; i < binary.length(); i++){
			updateState(binary[i]);
			cout << " > " << state;
		}
		cout << endl;
		if(state == 5){							//checks if the machine reached its final state
			cout << "code accepted" << endl;
		}else{
			cout << "code rejected" << endl;
		}
		state = 1;								//resets state for next code
		cout << endl << endl;
	}
//******************************* output section
  	return 0;
}
