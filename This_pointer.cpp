// author: jaydattpatel
#include<iostream>
using namespace std;
  
class Test
{
    private:
        int x;
        int y;
    public:
        Test(int x = 0, int y = 0) 
            { this->x = x; this->y = y; }
        void setX(int a) 
            { this->x = a; }
        void setY(int b) 
            { this->y = b; }
        void destroy()  
            { delete this; }
        void print() 
            { cout << "x = " << x << " y = " << y << endl; }
        static void fun1() { cout << "Inside fun1()"; }
        //static void fun2() { cout << "Inside fun2()"; this->fun1();}
        //not to access static function or variable
};
  
int main()
{
    Test obj;
    obj.setX(5);
    obj.setY(10);
    obj.print();
    obj.destroy();
    obj.print();
    return 0;
}