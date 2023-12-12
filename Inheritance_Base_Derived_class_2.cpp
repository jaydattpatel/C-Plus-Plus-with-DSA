// author: jaydattpatel
#include<iostream>
using namespace std;

// Base class
class PAIR
{
  private:
    int a,b;
  public:
    PAIR(int,int);
    void show(){
      cout<<"Private a: "<<a<<"\tb: "<<b<<endl;
    }
};

// Base class constructor
PAIR::PAIR(int x,int y)
{
  a = x;
  b = y;
  cout<<"\nData copied into private variables\n";
};


// Derived class
class sumPair : public PAIR
{
  public:
    int sum;
    sumPair(int,int);
};
 
sumPair::sumPair(int p,int q):PAIR(p, q)  // here constructor called and copied into private variable
{
  sum =p+q;
}

/* Class PAIR has already been
 * declared and defined with the
 * following constructor:
 *
 *   PAIR(int,int)
 *
 * that stores its two arguments in
 * two private member variables of PAIR.
 *
 * Class sumPair has also already been
 * defined as follows:
 *
 *
 * Implement the constructor
 * sumPair(int,int) such that it
 * loads the two member variables of
 * the base PAIR class with its
 * arguments, and initializes the
 * member variable sum with their sum.
 */
 
int main() {
  sumPair sp(15,16);
  cout << "sp(15,16).sum =" << sp.sum << endl;
  sp.show();
  return 0;
}