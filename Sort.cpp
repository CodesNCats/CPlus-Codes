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
int base [] = { 5, 20, 1, 7, 6, 19, 18, 17, 14, 15, 11, 10, 16, 9, 2, 3, 4, 13, 12, 8 };
int temp;
int userInput;
char choice;
int count;
//**************************** Functions ******************************
void insert(){
	for(int i=0;i<19;i++){
		if(base[i] < base[i+1]){
		}else{
			int reverse = i+1;
			while(base[reverse-1] > base[reverse]){
				temp = base[reverse];
				base[reverse] = base[reverse-1];
				base[reverse-1] = temp;
				if(reverse <= 1){
					break;
				}else{
					reverse--;
				}
			}
		}
	}
}

void selection(){
	for(int i=0;i<19;i++){
		temp = base[i];
		count = i;
		for(int c = i;c<=19;c++){
			if(temp < base[c]){ //exchnage greater or less then sign to change from ascending to descending
				temp = base[c];
				count = c;
			}else{
				continue;
			}
		}
		if(count == i){
			continue;
		}else{
			base[count] = base[i];
			base[i] = temp;
		}
	}
}

void quick(int start, int mid, int end){
	for(int i=start;i<end;i++){ //find median element
		if(base[i] == mid){
			mid = i;
			break;
		}else{
			continue;
		}
	}
	for(int i=start;i<end;i++){
		if(i<mid){ //checking items before mid point
			if(base[i]>base[mid]){ //issue found
				for(int c=end;c>=mid;c--){ //look for swap
					if(base[c]<base[mid]){ //found a swap
						temp = base[c];
						base[c] = base[i];
						base[i] = temp;
						break;
					}else if(c==mid){ //no swaps availbe move mid over
						temp = base[i];
						for(int m=i;m<mid;m++){
							base[m] = base[m+1];
						}
						base[mid] = temp;
						mid--;
						i--;
						break;
					}else{ //no swap found yet
						continue;
					}
				}
			}else{ //no issue
			}
		}else{ //checking items after the mid point
			if(base[i]<base[mid]){ //issue found
				for(int c=start;c<=mid;c++){ //look for swap
					if(base[c]>base[mid]){ //found a swap
						temp = base[c];
						base[c] = base[i];
						base[i] = temp;
						break;
					}else if(c==mid){ //no swaps availbe move mid over
						temp = base[i];
						for(int m=i;m>mid;m--){
							base[m] = base[m-1];
						}
						base[mid] = temp;
						mid++;
						i--;
						break;
					}else{ //no swap found yet
					}
				}
				
			}else{ //no issue
				continue;
			}
		}
	}
	
	switch(count){
		case 0:
			count=1;
			quick(0, 6, 11);
			break;
		case 1:
			count = 2;
			quick(10, 15, 19);
			break;
		case 2:
			count = 3;
			quick(0, 3, 5);
			break;
		case 3:
			count = 4;
			quick(5, 7, 10);
			break;
		case 4:
			count = 5;
			quick(10, 13, 15);
			break;
		case 5:
			count = 6;
			quick(15, 17, 19);
			break;
		case 6:
			count = 7;
			quick(0, 2, 2);
			break;
		case 7:
			count = 8;
			quick(3, 5, 5);
			break;
		case 8:
			count = 9;
			quick(6, 8, 8);
			break;
		case 9:
			count = 10;
			quick(9, 11, 11);
			break;
		case 10:
			count = 11;
			quick(12, 14, 14);
			break;
		case 11:
			count = 12;
			quick(15, 17, 17);
			break;
		case 12:
			count = 13;
			quick(18, 18, 19);
			break;
	}
	
}
//******************************* Main ********************************
int main(void){
	

//******************************* process section
	while(choice != 'y' && choice != 'Y'){
		for(int i=0; i<20; i++){
			cout << base[i] << ", ";
		}
		cout << endl << endl;
	
		cout << " Menu :\n"
	         << "1) Insertion Sort (ascending)\n"
	         << "2) Selection Sort (descending)\n"
	         << "3) Quick Sort     (ascending)\n"
	         << "4) Quit.\n";
	        cout<<"Please enter a number between 1 and 4: ";
	        while(!(cin >> userInput)){
		        cout << " That is not a valid choice" << endl;
		        cout << endl << "Please enter a number between 1 and 4";
		        cin.clear();
		        cin.ignore(123, '\n');
		     }
	        cout<<"\n_________________________________\n";
	        
		switch(userInput){
	        case 1:
	            insert();
	            break;
	        case 2:
	            selection();
	            break;
	        case 3:
	        	count = 0;
				quick(0, 11, 19);
		        break;
		    case 4:
		    	cout << "enter Y to quit" << endl;
		    	cin >> choice;
		    	break;
		}
	}

//******************************* output section
  	
  	
}
