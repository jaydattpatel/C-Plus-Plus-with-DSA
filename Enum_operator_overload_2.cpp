//Supplementary example on overloading operator
#include<iostream>
#include<cstdint>
using namespace std;

enum class days:std::int8_t{SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY};


// ostream& operator<<(ostream& out, const days& d)
// { 
//     out << static_cast<int>(d); 
//     return out; 
// }

ostream& operator<<(ostream& out, const days& d)
{ 
    switch (d)
    {
        case days::SUNDAY   :   out <<"Sun";break;
        case days::MONDAY   :   out <<"Mon";break;
        case days::TUESDAY  :   out <<"Tue";break;
        case days::WEDNESDAY:   out <<"Wed";break; 
        case days::THURSDAY :   out <<"Thus";break;
        case days::FRIDAY   :   out <<"Fri";break;
        case days::SATURDAY :   out <<"Sat";break;
    } 
    return out; 
}

days operator++(days& d) //PREFIX OPERATOR
{ 
    d = static_cast<days>((static_cast<int>(d) + 1) % 7); 
    return d; 
}
days operator++(days& d, int) //POSTFIX OPERATOR
{
    days temp = d;
    d = static_cast<days>((static_cast<int>(d) + 1) % 7);
    return temp;
}
int main()
{
    days today{days::SUNDAY} , dd;// today = days::SUNDAY
    dd = today++;
    cout<<today<<"\t"<<dd<<endl; 
    return 0;
}