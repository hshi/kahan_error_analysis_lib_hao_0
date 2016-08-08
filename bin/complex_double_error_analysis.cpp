#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <complex>
#include <iomanip>
#include "error_analysis.h"
#include "kahan.h"

using namespace std;
int main(int argc, char** argv)
{
    if( argc<3 ) {cout<<"Error!!!!! Need input file name!"<<endl;}
    string input  = argv[1];
    string output = argv[2];

    vector<complex<double>> vec;
    vector<size_t> fact;
    vector<complex<double>> mean;
    vector<double> err;

    //read data to vec
    ifstream input_file;
    input_file.open(input, ios::in);
    if ( ! input_file.is_open() ) {cout << "Error opening input file in double_error_analysis.cpp!!!"; exit(1);}
    double re, im;
    while (input_file >> re >> im) vec.push_back( complex<double>(re, im) );
    input_file.close();

    //data analysis
    error_analysis_blk_loop(vec,fact,mean,err);

    //write data to output
    ofstream output_file;
    output_file.open(output, ios::out|ios::trunc);
    if( !output_file.is_open() ) {cout << "Error opening output file in double_error_analysis.cpp!!! "<<endl; exit(1);}
    output_file<<setprecision(16)<<scientific;
    for(size_t i=0; i<fact.size(); i++) output_file<<setw(26)<<fact[i]<<setw(26)<<mean[i].real()<<setw(26)<<mean[i].imag()<<setw(26)<<err[i]<<"\n";
    output_file.close();

    return 0;
}
