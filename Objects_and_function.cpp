// author: jaydattpatel
#include<iostream>
using namespace std;

class distance_feet_inch
{   
    private:
        int feet;
        int inches;
    
    public:
        void setdistance(int c, int d)
        {   feet=c;
            inches=d;
        }
        
        void display()
        {   
            cout<<feet<<"ft"<<inches<<"inches";  
        }
        
        void adddist(distance_feet_inch d1,distance_feet_inch d2)
        {   
            feet=d1.feet+d2.feet;
            inches=d1.inches+d2.inches;
            if (inches>12)
                { 
                    feet++;
                    inches=inches-12;
                }
        }
};

int main()
{ 
    distance_feet_inch d1,d2,d3;
    d1.setdistance(10, 2);
    d2.setdistance(2,4);
    d3.adddist(d1,d2);
    d3.display();
    return(0);
} 