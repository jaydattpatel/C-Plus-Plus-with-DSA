// author: jaydattpatel
/*
Command line arguments:For programs that have minimal and/or optional inputs, command line arguments offer 
a great way to make programs more modular. The optional string arguments that are given by the user to a program during execution are known as ‘command line arguments’. 

We have to pass two arguments in the main function i.e. argc and argv. The names of the arguments are by convention. The example is as follows: 

int main(int argc, char *argv[])

argc is an argument containing the number of arguments passed to the program. argc will always be at least 1, because the first argument is always the name of the program itself! The value of argc will be incremented by 1 each time the user provides the command line argument. Each command line argument the user provides will cause argc to increase by 1. 

Powershell or Command Promte:

PS F:\C++ Programs> g++ "File_argc_argv_.cpp"
PS F:\C++ Programs> .\a
There are 1 arguments:
argv[0] : F:\C++ Programs\a.exe

PS F:\C++ Programs> .\a student.doc File_Print.txt
There are 3 arguments:
argv[0] : F:\C++ Programs\a.exe
argv[1] : student.doc
argv[2] : File_Print.txt
*/
#include <iostream> 
#include <fstream>
using namespace std; 

int main(int argc, char *argv[]) 
{ 
    ofstream file_out("File_Print.txt");
    file_out<<"This is a test print page";

    cout << "There are " << argc << " arguments:" << endl; 
    // Loop through each argument and print its number and value 
    for (int nArg=0; nArg < argc; nArg++) 
        cout << "argv[" <<nArg << "] : " << argv[nArg] << endl; 
    return 0; 
}