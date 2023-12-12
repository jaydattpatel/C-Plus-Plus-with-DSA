// author: jaydattpatel
#include<iostream>
#include<math.h>

using namespace std;        //std::cout<<"sample";  we do not require to use "std::" duting program


class circle
    {
        private:                // privately defined variable and function can not access out side of class. 
            float radius;
            float c_area()
                {   return(pow(radius,2)*22/7);  }
            float c_circumference();    //

        public:                 // publically defined variable and function can access within entire program. 
            float r; 
            float area(float r)        
                {    radius=r;
                    return (c_area());  }     // c_area is abstract function to hide function defination 

            float circumference(float r)
                {    radius=r;
                    return (c_circumference());  }     
    };

float circle :: c_circumference()
                {   return(radius*2*22/7);  }   //function defination of membor function of class can define out side but prototype defined in class.

int main()
    {
        
        circle c[3];  // define class array object(variable) or single object like circle c1;
        for(int i=0; i<3; i++)
            {
                cout<<i+1<<". Enter radius:";
                cin>>c[i].r;
            }
        for(int i=0; i<3; i++)
            cout<<i+1<<". Area: "<<c[i].area(c[i].r)<<"; Circumference:"<<c[i].circumference(c[i].r)<<endl;

        return 0;
    }