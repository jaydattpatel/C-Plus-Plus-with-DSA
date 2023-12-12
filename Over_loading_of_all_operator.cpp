/* 
// author: jaydattpatel
//operator overloading
You can overload any of the following operators:
+	    -	    *	    ⁄	      %	        ^	    &	    |	    ~       !
=	    <	    >	    +=	      -=	    *=	    ⁄=	    %=      ^=      &=
|=	    <<	    >>	    <<=	      >>=	    ==	    !=      <=	    >=	    &&	    
||	    ++	    --	    ,	      ->*	    ->      ( )	    [ ]	    
new	    delete	  new[]	    delete[]

where () is the function call operator and [] is the subscript operator.

You can overload both the unary and binary forms of the following operators:
+	-	*	&
You cannot overload the following operators:
.	.*	::	?:

*/

#include<iostream>
using namespace std;

class cube
    {

        public:
        //for all operator int argument are needed for postfix experession
        cube& operator =(const cube& obj);
        cube& operator +(const cube& obj);
        cube& operator -(const cube& obj);
        cube& operator *(const cube& obj);
        cube& operator /(const cube& obj);
        cube& operator %(const cube& obj);
        cube& operator +=(const cube& obj);
        cube& operator -=(const cube& obj);
        cube& operator *=(const cube& obj);
        cube& operator /=(const cube& obj);
        cube& operator %=(const cube& obj);
        cube& operator ==(const cube& obj);
        cube& operator !=(const cube& obj);
        cube& operator >=(const cube& obj);
        cube& operator <=(const cube& obj);
        cube& operator >(const cube& obj);
        cube& operator <(const cube& obj);
        cube& operator &(const cube& obj);
        cube& operator &=(const cube& obj);
        cube& operator |(const cube& obj);
        cube& operator &&(const cube& obj);
        cube& operator ||(const cube& obj);
        cube& operator <<(const cube& obj);
        cube& operator >>(const cube& obj);
        cube& operator ^(const cube& obj);
        cube& operator ^=(const cube& obj);
        cube& operator |=(const cube& obj);
        cube& operator ()(const cube& obj);
        cube& operator [](const cube& obj);
        cube& operator !();
        cube& operator ~();
        cube& operator ->();
        void* operator new(size_t size);
        void* operator new[](size_t size);
        void operator delete(void*);
        void operator delete[](void*);

    }; 


cube& cube::operator =(const cube& obj)
        {
            cout<<"\nInside (cube& operator = (const cube& obj))\n";
            return *this;
        }

cube& cube::operator +(const cube& obj)
        {
            cout<<"\nInside (cube& operator + (const cube& obj))\n";
            return *this;
        }

cube& cube::operator -(const cube& obj)
        {
            cout<<"\nInside (cube& operator - (const cube& obj))\n";
            return *this;
        }

cube& cube::operator *(const cube& obj)
        {
            cout<<"\nInside (cube& operator * (const cube& obj))\n";
            return *this;
        }

cube& cube::operator /(const cube& obj)
        {
            cout<<"\nInside (cube& operator / (const cube& obj))\n";
            return *this;
        }

cube& cube::operator %(const cube& obj)
        {
            cout<<"\nInside (cube& operator % (const cube& obj))\n";
            return *this;
        }

cube& cube::operator +=(const cube& obj)
        {
            cout<<"\nInside (cube& operator += (const cube& obj))\n";
            return *this;
        }

cube& cube::operator -=(const cube& obj)
        {
            cout<<"\nInside (cube& operator -= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator *=(const cube& obj)
        {
            cout<<"\nInside (cube& operator *= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator /=(const cube& obj)
        {
            cout<<"\nInside (cube& operator /= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator %=(const cube& obj)
        {
            cout<<"\nInside (cube& operator %= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator ==(const cube& obj)
        {
            cout<<"\nInside (cube& operator == (const cube& obj))\n";
            return *this;
        }

cube& cube::operator !=(const cube& obj)
        {
            cout<<"\nInside (cube& operator != (const cube& obj))\n";
            return *this;
        }

cube& cube::operator >=(const cube& obj)
        {
            cout<<"\nInside (cube& operator >= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator <=(const cube& obj)
        {
            cout<<"\nInside (cube& operator <= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator >(const cube& obj)
        {
            cout<<"\nInside (cube& operator > (const cube& obj))\n";
            return *this;
        }

cube& cube::operator <(const cube& obj)
        {
            cout<<"\nInside (cube& operator < (const cube& obj))\n";
            return *this;
        }

cube& cube::operator &(const cube& obj)
        {
            cout<<"\nInside (cube& operator & (const cube& obj))\n";
            return *this;
        }

cube& cube::operator &=(const cube& obj)
        {
            cout<<"\nInside (cube& operator &= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator |(const cube& obj)
        {
            cout<<"\nInside (cube& operator | (const cube& obj))\n";
            return *this;
        }

cube& cube::operator &&(const cube& obj)
        {
            cout<<"\nInside (cube& operator && (const cube& obj))\n";
            return *this;
        }

cube& cube::operator ||(const cube& obj)
        {
            cout<<"\nInside (cube& operator || (const cube& obj))\n";
            return *this;
        }

cube& cube::operator <<(const cube& obj)
        {
            cout<<"\nInside (cube& operator << (const cube& obj))\n";
            return *this;
        }

cube& cube::operator >>(const cube& obj)
        {
            cout<<"\nInside (cube& operator >> (const cube& obj))\n";
            return *this;
        }

cube& cube::operator ^(const cube& obj)
        {
            cout<<"\nInside (cube& operator ^ (const cube& obj))\n";
            return *this;
        }

cube& cube::operator ^=(const cube& obj)
        {
            cout<<"\nInside (cube& operator ^= (const cube& obj))\n";
            return *this;
        }
        
cube& cube::operator |=(const cube& obj)
        {
            cout<<"\nInside (cube& operator |= (const cube& obj))\n";
            return *this;
        }

cube& cube::operator ()(const cube& obj)
        {
            cout<<"\nInside (cube& operator () (const cube& obj))\n";
            return *this;
        }

cube& cube::operator [](const cube& obj)
        {
            cout<<"\nInside (cube& operator [] (const cube& obj))\n";
            return *this;
        }

cube& cube::operator !()
        {
            cout<<"\nInside (cube& operator ! () )\n";
            return *this;
        }

cube& cube::operator ~()
        {
            cout<<"\nInside (cube& operator ~ () )\n";
            return *this;
        }

cube& cube::operator ->()
        {
            cout<<"\nInside (cube& operator -> () )\n";
            return *this;
        }

void* cube::operator new(size_t size)
        {
            cout<<"\nInside (void* operator new (size_t size))\n"; 
            void * p = malloc(size);
            return p;
        }

void* cube::operator new[](size_t size)
        {
            cout<<"\nInside (void* operator new[] (size_t size))\n"; 
            void * p = malloc(size);
            return p;
        }

void cube::operator delete(void* p)
        {
          cout<<"\nInside (void operator delete (void* p))\n";
          free(p);
        }

void cube::operator delete[](void* p)
        {
          cout<<"\nInside (void operator delete[] (void* p))\n"; 
          free(p);
        }


int main()
    {

        cube c1,c2;
        //when you use operator(=,+,-,*,/,%,+=,-=,*=,/=,%=) then operator constructor executes
        (c1 = c2);  
        (c2 + c1);  (c2 - c1);  (c2 * c1);  (c2 / c1);  (c2 % c1);    
        (c2 += c1);  (c2 -= c1);  (c2 *= c1);  (c2 /= c1);  (c2 %= c1);    

        cout<<"\n============================= 1 =============================\n";
        //when you use operator(==,!=,>=,<=,>,<,<>=) then operator constructor executes
        (c1 == c2); (c1 != c2); (c1 >= c2); (c1 <= c2); (c1 > c2);  (c1 < c2);

        cout<<"\n============================= 2 =============================\n";
        //when you use operator(&, &=, | , && , ||) then operator constructor executes
        (c1 & c2); (c1 &= c2);  (c1 | c2);  (c1 && c2); (c1 || c2);

        cout<<"\n============================= 3 =============================\n";
        (c1 << c2); //when you use operator(<<,>>,^,^=,|=) then operator constructor executes
        (c1 >> c2); (c1 ^ c2);  (c1 ^= c2); (c1 |= c2);

        cout<<"\n============================= 4 =============================\n";
        //when you use operator((),[],! ,~ ,->, ->*,!~ , ,) then operator constructor executes
        c1(c2); c1[c2]; !c1; ~c1;

        cout<<"\n============================= 5 =============================\n";
        //when you use operator( (type), new, new[], delete, delete[]) then operator constructor executes
        cube *p = new(cube);
        cube *p1 = new(cube[3]);
        delete(p); delete[] p1;

        return 0;
    }


