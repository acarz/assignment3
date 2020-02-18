// this is not the same as you saw in class
#include <iostream>
using namespace std;
int main ()
{
    // We defined an array which will hold 6 elements and *p is the pointer
    int numbers[6];
    int *p;

    // numbers[0]=1 we assign the first element of the array to 1
    p = numbers;
    *p = 1;
    
    // we inreament p
    p++;
    *p = 4; //  // numbers[1]=4

    // we make numbers[2] = numbers[0]  which is 1
    p = &numbers[2];
    *p = numbers[0];
    
    // numbers[3] = memory address of 4
    p = numbers + *p;
    *p = 4;
    
    //numbers[5] = 5
    p = numbers + 1;
    *(p + 4) = 5;
    
    // Prints the elements of the array
    cout << "Numbers : " << numbers[0]
         << " " << numbers[1]
         << " " << numbers[2]
         << " " << numbers[3]
         << " " << numbers[4]
         << " " << numbers[5] << endl;
    return 0;
}