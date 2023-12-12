// author: jaydattpatel
/*
copy file

These internal stream positions point to the locations within the stream where the next reading or writing operation is performed. These positions can be observed and modified using the following member functions:

tellg()
tellp()

These two member functions with no parameters return a value of the member type streampos, which is a type representing the current get position (in the case of tellg) or the put position (in the case of tellp).

seekg ( position );
seekp ( position );

seekg ( offset, direction );
seekp ( offset, direction );

ios::beg	offset counted from the beginning of the stream
ios::cur	offset counted from the current position
ios::end	offset counted from the end of the stream

streampos -	ios::pos_type -	Defined as fpos<mbstate_t>.
It can be converted to/from streamoff and can be added or subtracted values of these types.

streamoff -	ios::off_type -	It is an alias of one of the fundamental integral types (such as int or long long).
*/

// obtaining ifile size
#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>
#include <math.h>
using namespace std;

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

unsigned long long copied_size = 0; 
bool open = false, finished = false;

int sam = 0;
bool running = false;

void sizeprint()
{
    gotoxy(5,30);
    if(copied_size<pow(1024,0) && copied_size<pow(1024,1))
        cout << "Copied: " <<setw(6)<<setfill(' ')<<left<< copied_size << " bytes.";
    else if(copied_size>=pow(1024,1) && copied_size<pow(1024,2))
        cout << "Copied: " <<setw(6)<<setfill(' ')<<left<< (copied_size/pow(1024,1)) << " KB.";
    else if(copied_size>=pow(1024,2) && copied_size<pow(1024,3))
            cout << "Copied: " <<setw(6)<<setfill(' ')<<left<< (copied_size/pow(1024,2)) << " MB.";
    else if(copied_size>=pow(1024,3))
            cout << "Copied: " <<setw(6)<<setfill(' ')<<left<< (copied_size/pow(1024,3)) << " GB.";
}

void filecopy(char *source, char *destination) 
{
    ifstream ifile;
    ifile.open(source, ios::binary | ios::in);
     if(ifile.is_open())
        cout<<endl<<source<<" File opened successfully to read.";
    else
		{
			cout<<endl<<source<<" File Error to Open File !!!";
			return;
		}

    ofstream ofile;
    ofile.open(destination, ios::binary| ios::out);
    if(ofile.is_open())
        cout<<endl<<destination<<" File opened successfully to write.";
    else
		{
			cout<<endl<<destination<<" File Error to Open File !!!";
			return;
		}

    ifile.seekg (0, ios::beg);
    ofile.seekp (0, ios::beg);
    cout<<endl<<"File Copying........\nPlease Wait";

    open = true;
    char buff[1024];
    while (ifile.read(buff, sizeof(buff)))
    {
        copied_size = ifile.gcount() + copied_size;
        ofile.write(buff, ifile.gcount());
    }

    ifile.close();
    ofile.close();
    open = false;
    finished = true;
    sizeprint();
    cout<<endl<<"..........Finished";
}


void sizeupdate()
{
    while(1)
    {

        while(open)
            {   
                if(sam == 0 && !running)
                {
                    running = true;
                    gotoxy(5,30);
                    cout<<"                       ";
                    sizeprint();
                    sam++;
                    running = false;
                    this_thread::sleep_for(250ms);
                }
            }
        if(finished)
            break;
    }
}

void dotanimation()
{
    while(1)
    {
        
        while(open)
            {   
                static int i = 0;
                if(sam == 1 && !running)
                    {
                        running  = true;
                        if (i > 10)
                            {
                                gotoxy(5,12);
                                for(int j = 0; j<=10; j++)
                                        cout<<" ";    
                                i = 0;
                            }
                        else
                            {
                                gotoxy(5,i+12);
                                cout<<"." ;
                                i++;         
                            }
                        sam--;
                        running = false;
                        this_thread::sleep_for(500ms);
                    }          
            }
        if(finished)
            break;
    }
}

void samaphore()
{
    while(open)
    {
        while(sam<1)
            sam++;
        while(sam>0)
            sam--;
    }
}
int main()
{
    clear();
    char source[] = {"Lam.jpg"};
    char destination[] = {"Mla.jpg"};
    thread t1(filecopy,source,destination);
    thread t2(sizeupdate);
    thread t3(dotanimation);
    thread t4(samaphore);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;

}