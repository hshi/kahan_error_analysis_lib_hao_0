#include <math.h> 
#include <algorithm>
#include <iostream>
#include <complex>
#include <iomanip>
#include "error_analysis.h"
#include "kahan.h"

using std::cout;
using std::cin;
using std::vector;
using std::complex;
using std::sort;

void get_factors(const size_t n, vector<size_t>& fact)
{
 if(!fact.empty()) fact.clear();
 for(size_t i=1; (i*i)<n; i++) {if((n%i)==0) {fact.push_back(i);fact.push_back(n/i);}}
 size_t sqrtn=lround(sqrt(static_cast<double>(n)));
 if((sqrtn*sqrtn)==n) fact.push_back(sqrtn);
 sort(fact.begin(),fact.end()); 
}


void double_error_analysis_file()
{
 vector<double> vec;
 vector<size_t> fact;
 vector<double> mean;
 vector<double> err;

 //read data to vec
 double data;
 while (cin >> data) vec.push_back(data);

 //data analysis
 error_analysis_blk_loop(vec,fact,mean,err);

 cout<<std::setprecision(18)<<std::scientific;
 for(size_t i=0; i<fact.size(); i++) cout<<fact[i]<<" "<<mean[i]<<" "<<err[i]<<"\n";
}


void complex_double_error_analysis_file()
{
 vector<complex<double>> vec;
 vector<size_t> fact;
 vector<complex<double>> mean;
 vector<double> err;

 //read data to vec
 complex<double> data;
 while (cin >> data) vec.push_back(data);

 //data analysis
 error_analysis_blk_loop(vec,fact,mean,err);

 cout<<std::setprecision(18)<<std::scientific;
 for(size_t i=0; i<fact.size(); i++) cout<<fact[i]<<" "<<mean[i]<<" "<<err[i]<<"\n";
}
