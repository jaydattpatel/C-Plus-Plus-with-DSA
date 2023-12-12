/* author: jaydattpatel
Polymorphisam:
Polymorphism means same content but different forms. 
The concept of polymorphism the same program code can call different functions of different classes.
*/
#include <iostream> 
using namespace std;

 class vehicle 
 { 
        int wheels; 
        float weight; 
    public: 
        void message(void) // first message 
            { 
            cout<<"Vehicle message, from vehicle, the base class\n";
            } 
    
};

class car : public vehicle 
{ 
        int passenger_load; 
    public: 
        void message(void) // second message 
            { 
                cout<<"Car message, from car, the vehicle derived class\n"; 
            } 
 }; 

class truck: public vehicle 
{ 
        int passenger_load; 
        float payload; 
    public: 
        int passengers(void) 
            { 
            return passenger_load; 
            } 
}; 
class boat: public vehicle
{ 
        int passenger_load; 
    public: 
        int passengers(void) 
            { 
                return passenger_load; 
            } 
        void message (void) // third message 
            { 
                cout<<"Boat message, from boat, the vehicle derived class\n";
            } 
};

int main() 
{ 
vehicle unique_vehicle; 
car sedan_car; 
truck ashok_truck; 
boat sailboat; 

unique_vehicle.message(); 
sedan_car.message(); 
ashok_truck.message(); 
sailboat.message(); 
// base and derived object assignment 
unique_vehicle = sedan_car; 
unique_vehicle.message(); 

return 0; 
} 