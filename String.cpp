// author: jaydattpatel
#include <iostream>
#include <cstring>
using namespace std;

int main () 
{
   int a=2022,diff,len;
   char char0[100];
   char char1[50] = "HeLlo";
   char char2[] = "WoRld";
   char char3[] = {'h', 'e', 'l', 'l', 'o', '\0'};
   char char4[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

   string str1 = "String-1";
   string str2("String-2");
   string str3,str4;

   // sprintf(string formation will be saved into char0 )  
   sprintf(char0,"\nsprintf(string,..): %s %s %s %d ",char1,"Welcome to ",char2,a);// sprintf to make string format  
   cout<<char0<<endl;

   // strcat only character array allowed 
   strcat(char1, char2); //joint the both array and store in first one
   cout<<"\nstrcat(char1, char2) : "<<char1<<endl;

   str1.append(str2);
   cout << "\nstr1.append(str2) : "<<str1;

   cout << "\nstr1.length() : "<< str1.length();
   cout << "\nstr1.size() : "<< str1.size();
   cout << "\nstr1.capacity() : "<< str1.capacity();
   cout << "\nstr1.max_size() : "<< str1.max_size();

   str1.resize(8);
   cout << "\nstr1.resize(8) : "<<str1;
   str1.shrink_to_fit();
   cout << "\nstr1.shrink_to_fit()";
   cout << "\nstr1.size() : "<< str1.size();
   cout << "\nstr1.capacity() : "<< str1.capacity();
   cout << "\nstr1.max_size() : "<< str1.max_size();

   str3 = str1 + str2; 
   cout << "\n\nstr3 = str1 + str2 : "<<str3;

   if(str1 == str2)
      cout<<"\n(str1 == str2) : "<<(str1 == str2)<<" are same : " <<str1<<" , "<<str2;
   else
      cout<<"\n(str1 == str2) : "<<(str1 == str2)<< "are not same : "<<str1<<" , "<<str2;


   for(int i = 0; i<8;i++)
      str3.pop_back();
   cout << "\nstr3.pop_back() : "<<str3;

   for(int i = 0; i<str2.length();i++)
      str3.push_back(str2[i]);
   cout << "\nstr3.push_back(str2[i]) : "<<str3;

   str3.copy(char4, 6, 0); //string to character array
   cout << "\nstr3.copy(char4, 6, 0) : "<<char4;

   str1.swap(str2);
   cout << "\nstr1.swap(str2) :";
   cout << "\nstr1: "<<str1<< "\nstr2: "<<str2;

   cout << "\n\nEnter the string cin.get(char0, 50) : ";
   cin.get(char0, 100);
   cout<<"\n"<<char0<<endl;

   cout << "\nEnter the string (press $ to terminate) : ";
   cin.getline(char0,100,'$');
   cout<<"\n"<<char0<<endl;

   return 0;
}