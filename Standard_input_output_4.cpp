//author: jaydattpatel
/*
Manipulators with Arguments: Some of the manipulators are used with the argument like setw (20), setfill (‘*’), and many more. These all are defined in the header file. If we want to use these manipulators then we must include this header file in our program. For Example, you can use following manipulators to set minimum width and fill the empty space with any character you want: std::cout << std::setw (6) << std::setfill (’*’);

Some important manipulators in <iomanip> are:
setw (val):         It is used to set the field width in output operations.
setfill (c):        It is used to fill the character ‘c’ on output stream.
setprecision (val): It sets val as the new value for the precision of floating-point values.
setbase(val):       It is used to set the numeric base value for numeric values.
setiosflags(flag):  It is used to set the format flags specified by parameter mask.
resetiosflags(m):   It is used to reset the format flags specified by parameter mask.

Some important manipulators in <ios> are:
showpos:     It forces to show a positive sign on positive numbers.
noshowpos:   It forces not to write a positive sign on positive numbers.
showbase:    It indicates the numeric base of numeric values.
uppercase:   It forces uppercase letters for numeric values.
nouppercase: It forces lowercase letters for numeric values.
fixed:       It uses decimal notation for floating-point values.
scientific:  It uses scientific floating-point notation.
hex:         Read and write hexadecimal values for integers and it works same as the setbase(16).
dec:         Read and write decimal values for integers i.e. setbase(10).
oct:         Read and write octal values for integers i.e. setbase(10).
left:        It adjusts output to the left.
right:       It adjusts output to the right.

*/

#include<iostream>
#include <iomanip>
using namespace std;

int main()
{

    int a=15;  
    float f = 1.34255;
    cout << "\nsetw(10):"<<setw(10) << a; 
    cout<<"\nleft setw(10) : "<< left << setw(10) << a;
    cout<<"\nright setw(10) : "<< right << setw(10) << a;
    cout<<"\nleft setfill('*') setw(10) : "<< left << setfill('*') << setw(10) << a;
    cout<<"\nright setfill('*') setw(10) : "<< right <<setfill('*')<< setw(10) << a;

    
    cout <<"\nfixed setprecision(3):"<<fixed<< setprecision(3) << f << endl;

    int num = 0;

    cout << "\nEnter Dec = ";   
    cin >> dec >> num;
    cout << "Dec = " << dec << num <<endl;
    cout << "Hex = " << hex << num <<endl;
    cout << "Oct = " << oct << num << endl;
    cout << "Setbase(8) = " << setbase(8) << num << endl;
    cout << "Setbase(16) = " << setbase(16) << num << endl;
    


    cout << "\nEnter Hex = ";   
    cin >> hex >> num;
    cout << "Dec = " << dec << num <<endl;
    cout << "Hex = " << hex << num <<endl;
    cout << "Oct = " << oct << num << endl;
    cout << "Setbase(8) = " << setbase(8) << num << endl;
    cout << "Setbase(16) = " << setbase(16) << num << endl;

    char name[50];
    cout << "\nEnter your name" << endl;
    cin >> ws;
    cin.getline(name,50);
    cout << name << endl;
    
    return 0;
}
