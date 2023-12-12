// author: jaydattpatel
#include <iostream>// include< .h>  is used to include file from library folder
#include <string.h>        // include" .h"  is used to include file from curretnt folder

#pragma copyright "Manipal University"
#pragma copyright_date "2022-2025"
#pragma versionid "Manipal University, Version 1234 5.8.0 1.10"
#pragma optimize on
#pragma startup funcs  
#pragma exit funce 

#if 0 
write comment out here
use for comment
#endif
/* #error use to give error to user using compiler (remove comment quates)
   we can use #error:1,#error1,#error-1,#error(1)

#ifndef pp
   #error:1 "pp value is not correct or not defined"
#endif 
*/
#define pi 1.00
#undef pi   //remove pi defined 
#ifndef pi  //if pi not defined
   #define pi 3.14   //define pi
#endif      

#define sum(a,b) (a+b)  //addition
#define sub(a,b) (a-b)  //subtraction
#define div(a,b) (a/b)  //divison
#define avg(a,b) ((a+b)/2) //average
#define square(a) (a*a)    // find square of value
#define cube(a) (square(a)*a)    // find cube of value

#ifdef pi
   #define circlearea(r) (pi*r*r)   //define formula area of circle
#else   
   #error "pi value is not defined"
#endif   

#define inc(a) ++a //increment
#define dec(a) --a   //decrement
#define mer(a,b) a##b // concatenate merge
#define sss(a) printf("Hello "#a"\n") //move as it is
#define msg "C Programming" //string move to variable
/* "\" used for continue Programming in new line*/
#define msg1(a,b,i,limit) while(i<limit)\
                              {  i++;\
                                 printf("%d.Print:%s %s\n",i,a,b);}  //print line multiple time
#define pwr(a,b,i,out) for(i=0;i<b;i++)\
                              {\
                                 out = out * a;\
                              }  //find power
#define max(a,b) ((a)>(b)?(a):(b))     // find max between two variables
#define min(a,b,out) if(a<b){out=a;}else{out=b;}   // find min between two variables
#define tokenpaster(n) printf ("token" #n " = %d\n", token##n)//token##n=token(n)

using namespace std;
void funcs();
void funce();
void funcs(){  
cout<<"\nProgram start:\n";   
} 

void funce(){  
cout<<"\nProgram ends.\n";  
} 

int main( )
{
   printf("File :%s\nDate :%s\nTime :%s\nLine :%d\nANSI :%d\n\n",__FILE__,__DATE__,__TIME__,__LINE__,__STDC__);
   
   int d1=10, d2=4, result=1, i=0, d4=5;
   float f1=3;
   char c1[50]="Hello", c2[50]="World", c3[50] = msg;

   printf("pi=%f\n",pi);
   printf("sum(d1,d2)=%d\t\t",sum(d1,d2));                  
   printf("sub(d1,d2)=%d\n",sub(d1,d2));
   printf("div(d1,d2)=%d\t\t",div(d1,d2));                  
   printf("avg(d1,d2)=%d\n",avg(d1,d2));
   printf("square(d1)=%d\t\t",square(d1));                  
   printf("cube(d1)=%d\n",cube(d1));
   printf("circlearea(f1)=%f\t\t",circlearea(f1));          
   printf("inc(d1) = %d,inc(d2) = %d\n",inc(d1),inc(d2));
   printf("dec(d1) = %d,dec(d2) = %d\n",inc(d1),dec(d2));
   printf("mer(12,34)=%d\n",mer(12,34));                    
   printf("sss(Welcome) = ");
   sss(Welcome);  
   printf("msg = %s\n",c3);                                 
   msg1(c1,c2,i,d4);  
   result=1;    
   printf("max(d1,d2)=%d\t\t",max(d1,d2));                  
   min(d1,d2,result);   
   printf("min(d1,d2,result)=%d\n",result);
   pwr(d1,d2,i,result); 
   printf("pwr(d1,d2,i,result)=%d\n",result);
   int token34 = 40;
   tokenpaster(34);
  
   return 0;
}

