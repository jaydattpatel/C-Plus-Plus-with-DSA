// author: jaydattpatel
//friend class

#include<iostream>
using namespace std;

class class_A
{
	int x;

		public:	
            class_A()
                {
                    x=10;
                }
            friend class class_B; //friend class
    };

class class_B
{
	public:
		void display(class_A &t)
		{
			cout<<endl<<"The value of x="<<t.x;
		}
};

main()
{
	class_A CA;
	class_B CB;
	CB.display(CA);
	return 0;
}
