// author: jaydattpatel
#include<iostream>
using namespace std;

class cube
    {
        private:
        double length;
        
        public:

        double getVolume(){
            return(length * length * length); 
        }
        
        void setLength(double l){
            length = l;
        }
    }; 

int main()
{
    //assign value of object to other and storage allocate for both
    cube c;
    c.setLength(10.0);
    cube c1 = c;
    cout<<"c Volume: "<<c.getVolume()<<"\t\tc memory location:"<<&c<<"\n";
    cout<<"c1 Volume: "<<c1.getVolume()<<"\t\tc1 memory location:"<<&c1<<"\n\n";

    //assign the address of variable to pointer and storage of both variable is common to save memory. same way you can save by address to function block.
    cube *c_ptr = &c;
    cout<<"c Volume: "<<c.getVolume()<<"\t\tc memory location: "<<&c<<"\n";
    cout<<"c_ptr Volume: "<<(*c_ptr).getVolume()<<"\tc_ptr memory location:"<<c_ptr<<"\n\n"; 

    //copy the address of variable to variable by reference operator and storage of both variable is common to save memory. same way you can save by address to function block.
    cube &c3 = c;
    cout<<"c Volume:"<<c.getVolume()<<"\t\tc memory location:"<<&c<<"\n";
    cout<<"c3 Volume:"<<c1.getVolume()<<"\t\tc3 memory location:"<<&c3<<"\n\n";

    return 0;
}