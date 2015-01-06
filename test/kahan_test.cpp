#include <iostream>
#include <iomanip> 
#include <cmath>
#include <cstdlib>
#include <limits>
#include "kahan.h"

using namespace std;
void kahandata_classtest()
{
    //void construction
    KahanData<double> ksum1;
    if((abs(ksum1.sum-0.0)<1e-14) && (abs(ksum1.c-0)<1e-14)) {cout<<"Kahandata passed the void construction test! \n";}
    else {cout<<"WARNING!!!!!!!!!Kahandata failed the void construction test! \n";}
   
    //sum value construction
    KahanData<double> ksum2(0.2);
    if((abs(ksum2.sum-0.2)<1e-14) && (abs(ksum2.c-0)<1e-14)) {cout<<"Kahandata passed the value construction test! \n";}
    else {cout<<"WARNING!!!!!!!!!Kahandata failed the value construction test! \n";}
   
    // copy construction
    KahanData<double> ksum3=ksum2;
    if((abs(ksum3.sum-0.2)<1e-14) && (abs(ksum3.c-0)<1e-14)) {cout<<"Kahandata passed the copy construction test! \n";}
    else {cout<<"WARNING!!!!!!!!!Kahandata failed the copy construction test! \n";}
   
    // copy assigment
    ksum3.c=1.2;ksum1=ksum3;
    if((abs(ksum1.sum-0.2)<1e-14) && (abs(ksum1.c-1.2)<1e-14)) {cout<<"Kahandata passed the copy assigment test! \n";}
    else {cout<<"WARNING!!!!!!!!!Kahandata failed the copy assigment test! \n";}
   
    //  +=
    KahanData<double> ksum4;ksum4+=0.5;
    if((abs(ksum4.sum-0.5)<1e-14) && (abs(ksum4.c-0)<1e-14)) {cout<<"Kahandata passed the += test! \n";}
    else {cout<<"WARNING!!!!!!!!!Kahandata failed the += test! \n";}
   
    // big summation
    KahanData<double> ksum5;
    double sum_naive=0;
    for (int i=1; i<=499992; i++) 
    {
        double j=1000.00001;
        ksum5+=j;
        sum_naive+=j;
        //std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' ); // means pause in fortran
    }
    cout<<setprecision(18)<<"Use Kahan sum: "<<ksum5.sum-499992004.99992<<endl;
    cout<<setprecision(18)<<"Use Naive sum: "<<sum_naive-499992004.99992<<endl;
    if(abs(ksum5.sum-499992004.99992)<1e-6) {cout<<"Kahandata passed the sum test! \n";}
    else {cout<<"WARNING!!!!!!!!!Kahandata failed the sum test! \n";}
   
    cout<<"\n \n";
}

/*int main()
{
 kahandata_classtest();
 return 0;
}*/
