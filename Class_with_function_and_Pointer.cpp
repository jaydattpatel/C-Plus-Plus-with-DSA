// author: jaydattpatel
#include<iostream>

using namespace std;

namespace uiuc
{
    class cube
    {
        private:
        double length;
        
        public:
        double getVolume(){
            return(length * length * length); 
        }
        double getSurfacearea(){
            return(6 * length * length); 
        }
        void setLength(double l){
            length = l;
        }
    }; 
}

//using namespace uiuc;  //you can use this if you dont write namespace "uiuc::"

//function to set length return cube data.
uiuc::cube creatunit(){
    uiuc::cube x;
    x.setLength(10);
    return(x);
}

//function to creat new cube, set length and return cube pointer
uiuc::cube *creatunitptr(){
    uiuc::cube *cc,x;
    cc = &x;
    x.setLength(20);
    cout<<"\nAddress of cc : "<<cc<<endl;
    return(cc);
}
int main()
    {
        //creat cube get cube data by call function 
        uiuc::cube c = creatunit();
        double a = c.getVolume();
        double b = c.getSurfacearea();
        cout<<"Volume: "<<a<<"\nSurfacearea: "<<b<<endl;

        //creat cube pointer get address of cube pointer by call cube pointer function 
        uiuc::cube *m = creatunitptr();
        double x = m->getVolume();
        double y = m->getSurfacearea();
        cout<<"Address of m:"<<m<<endl;
        cout<<"\nVolume: "<<x<<"\nSurfacearea: "<<y;

        return 0;
    }