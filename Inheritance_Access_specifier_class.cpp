/*
// author: jaydattpatel

Access specifier public:
When we derive a class using public base class access specifier, all inherited public members of the base class will become public members of the derived class. All inherited protected members of the base class will become protected members of the derived class. All inherited private members will remain private to the base class, and cannot be accessed by the member functions of the derived class.

Access specifier private: 
When you derive a class using a private base class access specifier, all inherited public and protected members of the base class will become private members of the derived class. All the private members of the base class cannot be accessed by the member functions of the base class. 

Access specifier protected: 
When you derive a class using a protected base class access specifier, then all the inherited public and protected members of the base class will become protected members of the derived class. And all the private 
members of the base class cannot be accessed by the member functions of the derived class. 
*/

#include <iostream>
using namespace std;

class Base 
{
    private:
        int pvt = 1;

    protected:
        int prot = 2;

    public:
        int pub = 3;
        int getPVT()    //to access private member or function with derived class
            {return pvt;}
};

//Derived from public base: public members of the base class will become public members of the derived class, protected members of the base class will become protected members of the derived class and all the private members of the base class cannot be accessed by the member functions of the derived class. 
class PublicDerived : public Base //public base
{
    private:
      
    protected:  
        // include protected of base into protected of derived 
    public:     
        // include public of Base into public of derived
        int getProt() 
            {return prot;}  
    
};

//Derived from protected base: public and protected members of the base class will become protected members of the derived class and all the private members of the base class cannot be accessed by the member functions of the derived class. 
class ProtectedDerived : protected Base // with private base
{  
    private:

    protected:
        // include public of base into protected of derived 
        // include protected of base into protected of derived
    public:

        int getPVT()    
            {return (Base::getPVT());}
        int getPub() 
            {return pub;}
        int getProt() 
            {return prot;}
};

//Derived from private base:public and protected members of the base class will become private members of the derived class and all the private members of the base class cannot be accessed by the member functions of the derived class. 
class PrivateDerived : private Base // with private base
{  
    private:
        // include public of base into private of derived 
        // include protected of base into private of derived 
    protected:

    public:
        int getPVT()    
            {return (Base::getPVT());}
        int getPub() 
            {return pub;}
        int getProt() 
            {return prot;}
};

int main() 
{
    cout<<"\n--------------Derived class with Public Base---------------\n";
    PublicDerived object1;
    cout << "Private = " << object1.getPVT() << endl;
    cout << "Protected = " << object1.getProt() << endl;
    cout << "Public = " << object1.pub << endl;

    cout<<"\n--------------Derived class with Protected Base---------------\n";
    ProtectedDerived object2;
    cout << "Private = " << object2.getPVT() << endl;
    cout << "Protected = " << object2.getProt() << endl;
    cout << "Public = " << object2.getPub() << endl;

    cout<<"\n--------------Derived class with Private Base---------------\n";
    PrivateDerived object3;
    cout << "Private = " << object3.getPVT() << endl;
    cout << "Protected = " << object3.getProt() << endl;
    cout << "Public = " << object3.getPub() << endl;

    return 0;
}