// author: jaydattpatel
#include<iostream>
using namespace std;    //std::cout<<"sample";  we do not require to use "std::" duting program 

int main()
{
    int i=1000,a,b,size;
    float f=2;
    char ss[10]= "Manipal",str[50],ch='J';
    wchar_t tt[50]; // wide character variable.

    double pi = 3.14159783;
    cout.precision(5);  // Set precision to 5
    cout << "cout.precision(5) pi: "<<pi << endl;     // Print pi
    cout.precision(7);  // Set precision to 7
    cout << "cout.precision(7) pi: "<< pi << endl;     // Print pi

    cout<<"\nEnter two integers:\n";  // cout<< and wcout is used to print string or data in display.
    // wcout is use to print wide character.
    
    cin>>a>>b;  // cin>> is used to get input from keyboard 
    // wcin is use to get wide characters.
    cout<<"\ndec a: "<<dec<<a<<"oct a: "<<oct<<a<<"hex a: "<<hex<<a;
    cout<<"\ndec b: "<<dec<<b<<"oct b: "<<oct<<b<<"hex a: "<<hex<<b;
    cout<<"\na+b: "<<a+b<<endl;   cout<<"a-b: "<<a-b<<endl;   cout<<"a*b: "<<a*b;
    cout<<"a/b: "<<a/b<<endl;   cout<<"a%b: "<<a%b<<endl;

    cout<<"\nEnter two integers in decimal:\n";  
    cin>>dec>>a>>b;
    cout<<"\ndec a: "<<dec<<a<<"\toct a: "<<oct<<a<<"\thex a: "<<hex<<a;
    cout<<"\ndec b: "<<dec<<b<<"\toct b: "<<oct<<b<<"\thex a: "<<hex<<b;

    cout<<"\nEnter two integers in octal:\n";
    cin>>oct>>a>>b;
    cout<<"\ndec a: "<<dec<<a<<"\toct a: "<<oct<<a<<"\thex a: "<<hex<<a;
    cout<<"\ndec b: "<<dec<<b<<"\toct b: "<<oct<<b<<"\thex a: "<<hex<<b;

    cout<<"\nEnter two integers in hexadecimal:\n";
    cin>>hex>>a>>b;
    cout<<"\ndec a: "<<dec<<a<<"\toct a: "<<oct<<a<<"\thex a: "<<hex<<a;
    cout<<"\ndec b: "<<dec<<b<<"\toct b: "<<oct<<b<<"\thex a: "<<hex<<b;


    cout<<"\nHello world "<<i*f+22<<endl;
    cout<<"\t\tWelcome to "<<ss<<endl;
    cout<<"\t\tUniversity\n";

    //string Method-1
    cout<<"Enter string cin>>str :";
    cin>>str;  
    cout<<str<<endl;

    cout<<"Enter string wcin>>tt :";
    wcin>>tt;   //wcin used to get input in wide characters.
    wcout<<tt<<endl;    // wcout used to print wide characters

    //string Method-2
    cout<<"Enter string cin.getline(str, 5) :";     
    cin.getline(str, 5);    //same way we can use wcin.getline(tt,20); for wide characters.
    cout << " characters read: " << cin.gcount()<< '\n';
    cout<<str<<endl;
    

    //string Method-3
    cout<<"Enter string cin.get(str,7,'$') :";
    cin.get(str,7,'$');    //same way we can use wcin.get(tt,20,'$'); for wide characters.
    cout<<str<<endl;
    
    
    //string Method-4
    cout<<"Enter string cin.get(str, 5) :";
    cin.get(str, 5);  //same way we can use wcin.get(tt,20); for wide characters.
    cout<<str<<endl;
   

    //string Method-5
    cout<<"Enter string cin.read(str, 4) :";
    cin.read(str, 4); //same way we can use wcin.read(tt,20); for wide characters.
    cout<<str<<endl;
    

    cout<<"cout.write(ss, 7) : ";    
    cout.write(ss, 7)<<endl;  // Print first 7 character

    cout<<"cout.put(ch) : ";
    cout.put(ch)<<endl;   // Print the character ch

    cout<<"__LINE__ : "<< __LINE__ << endl<<"__FILE__ : "<< __FILE__ << endl<<"__TIME__ : "<< __TIME__ << endl;
 
    return(0);
}