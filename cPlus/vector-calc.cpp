//Ashley Luciano 
//Brandon Schroeder 
//Val Monceau 
//Miguel Sosa 

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

struct VECTOR{
    double x;
    double y;
};

void get_Vector(VECTOR&, VECTOR&);          // prototypes
void input_Validation(int&);
void adding_Vectors(VECTOR&, VECTOR&, VECTOR&);
void substracting_Vectors(VECTOR&, VECTOR&,VECTOR&);
void scalar_Product(VECTOR&, VECTOR&);
void scalar_Multiple(VECTOR&, string&);
void magnitude(VECTOR&, string&);

int main()
{
    
    int userInput;                        // variables
    string string1,string2;
    VECTOR vector1, vector2, added_Vectors, susbtracted_Vectors;
    char choose = 'y';
    fstream Outfile;
    get_Vector(vector1, vector2);
    string outputAddedVectors="The result of the two added vectors is: ";
    string outputSubstractedVectors="The result of the two subtracted vectors is: ";
    string name1="vector 1";
    string name2="vector 2";
    
    do                    //menu
    {
        cout << "" << endl;
        cout << " Menu :\n"
             << "1) Add\n"
             << "2) Subtract\n"
             << "3) Scalar Product\n"
             << "4) Scalar Multiple\n"
             << "5) Magnitude\n"
             << "6) Quit.\n";
        cout<<"Please enter a number between 1 and 6: ";
        cin >> userInput;
        input_Validation(userInput);
        cout<<"\n_________________________________\n";
        
        switch(userInput)
        {
            case 1:
                adding_Vectors(vector1, vector2,added_Vectors);
                break;
            case 2:
                substracting_Vectors(vector1, vector2,susbtracted_Vectors);
                break;
                
            case 3:
                scalar_Product(vector1, vector2);
                  break;
            case 4:
                scalar_Multiple(vector1, name1);
                scalar_Multiple(vector2, name2);
                  break;
            case 5:
                magnitude(vector1, name1);
                magnitude(vector2, name2);
                  break;
            case 6:
                cout<<"\nto QUIT press any key, and to RETURN back to the Main Menu press 'y' or 'Y': ";
                cin>>choose;
                cout<<endl;
                break;
            }
    }
    while(choose=='y'||choose=='Y');
    Outfile.close();
    return 0;
}

void get_Vector(VECTOR &vector1, VECTOR &vector2)     // function to get the vectors
{
    cout <<"Please enter Vector1 ( a, b )" << endl;
    cout<<"a: ";
    cin >>vector1.x;
    cout<<"b: ";
    cin >>vector1.y;
    cout <<"Please enter Vector2 ( c, d)" << endl;
    cout<<"a: ";
    cin >>vector2.x;
    cout<<"b: ";
    cin >>vector2.y;
}


void input_Validation(int &userInput)    // check input function
{
    while(userInput>6||userInput<1||!(userInput))
    {
        cin.clear();
        cout<<"Please enter a number between 1 and 6: ";
        cin >> userInput;
    }
}

// add function
void adding_Vectors(VECTOR &vector1, VECTOR &vector2, VECTOR &added_Vectors)
{
    added_Vectors.x = vector1.x + vector2.x;
    added_Vectors.y = vector1.y + vector2.y;
    cout<<"Added vectors : " <<"("<<added_Vectors.x<<","<<added_Vectors.y<<")"<<endl;
}

// substract function
void substracting_Vectors(VECTOR &vector1, VECTOR &vector2, VECTOR &substracted_Vectors)
{
    substracted_Vectors.x = vector1.x - vector2.x;
    substracted_Vectors. y= vector1.y - vector2.y;
    cout<<"Subtracted vectors : " <<"("<<substracted_Vectors.x<<","<<substracted_Vectors.y<<")"<<endl;
}




// scalar product function
void scalar_Product(VECTOR &vector1, VECTOR &vector2){
     double result;
     result = vector1.x * vector2.x + vector1.y * vector2.y;
     cout << "The scalar product of these two vectors is: " << result << endl << endl;
     return;
}

// scalar multiple function
void scalar_Multiple(VECTOR &vector, string &name){
     VECTOR result;
     double K;
     cout << "Enter amount to multiply " << name << " by:";
     while(!(cin >> K)){
         cout << " That is not a valid amount!";
        cout << endl << "Enter amount to multiply " << name << " by:";
        cin.clear();
        cin.ignore(123, '\n');
     }
     result.x = vector.x * K;
     result.y = vector.y * K;
     cout << name << " multiplied by " << K << " is: " << result.x << ", " << result.y << endl << endl;
     return;
}

// magnitude function
void magnitude(VECTOR &vector, string &name){
     double mag;
     mag = vector.x * vector.x + vector.y * vector.y;
     mag = sqrt(mag);
     cout << "The magnitude of " << name << " is " << mag << endl;
     return;
}


