// my solution to Question 1 for Assignment 3
// I have done this assingment without seeing the code providied in the assignment.

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

float compute_sum(std::vector<float> &v)
{

    float total = 0;

    // using for loop to visit every element in a vector and add them up
    for (int i = 0; i < v.size(); i++)
    {
        total = total + v[i];

    }

    return ( total);
}

// this function calculates the mean by taking vector and the total calculated with abore function as paramteters
float compute_avg(std::vector<float> &v, float total)
{

    return ( total / v.size());
}

// This function takes avg from the above function and calculates RMS
float compute_rms(std::vector<float> &v, float avg)
{

    float sum  = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum = sum + pow((v[i] - avg), 2);

    }
    return ( sqrt(sum / v.size()));
}


int main(int argc, char const *argv[])
{
    cout << "Hello CERN" << endl;
    cout << "--------------" << endl;
    cout << " Assignment 3, Question 1 " << endl;

    // define which file to read
    ifstream in("assignment3_newline_numbers.txt");

    std::vector<float> Q;

    float data;

    while (in >> data)
    {
        Q.push_back(data);

    }

    // we make sure if we read all the values correctly
    cout << "____ The values we read from the txt file ___" << endl;
    
    for (int i = 0; i < Q.size(); i++)
    {
        cout << Q[i] << endl;
    }

    // we call the funcctions 
    float total= compute_sum(Q);
    float avg =compute_avg(Q,total);
    float rms=compute_rms(Q,avg);

    // We print the results
    cout << "________The results____________" << endl;

    cout <<"The total :"<< total<< endl;
    cout <<"The Average :"<< avg << endl;
    cout <<"The RMS :"<< rms << endl;
    
    return 99;
}