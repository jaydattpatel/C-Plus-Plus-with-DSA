// author: jaydattpatel
//friend function
#include <iostream>
using namespace std;

class Rect
    {
        //by default private variable and function if not mention it is private or public
        int a, b; // a is the variable to store width and b is the variable to store height 
        int x = 77;

        protected:
            int z = 55;

        public:
            int y = 88;
            void setvalue(int c, int d)
                {
                    a = c;
                    b = d;
                };
            int area () 
                {return (a * b);}
            friend class t_class;
            friend Rect duplicate(Rect);
            friend void find_max(Rect);
            
    };

class t_class
{
    public:
        void react_print(Rect &r)
        {
            cout<<"\nx,y and z of Rect accessed by t_class: "<<r.x<<"  "<<r.y<<"  "<<r.z;
        }

};

Rect duplicate (Rect rectparam)
    { 
        Rect r;
        r.a = rectparam.a;
        r.b = rectparam.b;
        return (r);
    }

void find_max(Rect t)
{
    int max;
    max = (t.a>t.b)?(t.a):(t.b);  
    cout<<"Maximum Number is "<<max;
}


int main () 
    {
        Rect r1, r2;
        r1.setvalue(4,7);
        cout <<"r1.area(): "<<r1.area()<<endl;
        r2 = duplicate (r1);
        cout <<"r2.area(): "<<r2.area()<<endl;
        find_max(r1);

        t_class tt;
        tt.react_print(r1);
        return 0;
    } 