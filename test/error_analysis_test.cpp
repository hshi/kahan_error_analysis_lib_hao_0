#include <iostream>
#include "error_analysis.h"

#ifdef MPI_HAO
#include <mpi.h>
#endif

using namespace std;

//============
//Pointer test
//============
void get_average_err_pointer_test()
{
    //double test
    const size_t L=9;
    double array[L]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    double mean,err;
   
    get_average(L,array,mean);
    if(abs(mean-5.0)<1e-14) {cout<<"PASSED! Get_average passed double pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_average failed double pointer test!"<<endl;}
   
    get_err(L,array,mean,err);
    if(abs(err-0.912870929175277)<1e-14) {cout<<"PASSED! Get_err passed double pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_err failed double pointer test!"<<endl;}
   
    get_err(1,array,mean,err);
    if(abs(err-0)<1e-14) {cout<<"PASSED! Get_err passed double one pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_err failed double one pointer test!"<<endl;}
   
   
    //complex<double> test
    const size_t L_c=4;
    complex<double> array_c[L_c]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0}};
    complex<double> mean_c;
    double err_c;
   
    get_average(L_c,array_c,mean_c);
    if(abs(mean_c-complex<double>(4.0,5.0))<1e-14) {cout<<"PASSED! Get_average passed complex double pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_average failed complex double pointer test!"<<endl;}
   
    get_err(L_c,array_c,mean_c,err_c);
    if(abs(err_c-1.8257418583505536)<1e-14) {cout<<"PASSED! Get_err passed complex double pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_err failed complex double pointer test!"<<endl;}
   
    get_err(1,array_c,mean_c,err_c);
    if(abs(err_c-0)<1e-14) {cout<<"PASSED! Get_err passed complex double one pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_err failed complex double one pointer test!"<<endl;}
}




void error_analysis_pointer_test()
{
    //double test
    const size_t L=9;
    double array[L]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    double mean,err;
   
    error_analysis(L,array,mean,err);
    if((abs(mean-5.0)<1e-14)&&(abs(err-0.912870929175277)<1e-14)) {cout<<"PASSED! Error_analysis passed double pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Error_analysis failed double pointer test!"<<endl;}
   
   
    //complex test
    const size_t L_c=4;
    complex<double> array_c[L_c]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0}};
    complex<double> mean_c;
    double err_c;
   
    error_analysis(L_c,array_c,mean_c,err_c);
    if((abs(mean_c-complex<double>(4.0,5.0))<1e-14)&&(abs(err_c-1.8257418583505536)<1e-14))
        {cout<<"PASSED! Error_analysis passed complex double pointer test!"<<endl;}
    else 
        {cout<<"WARNING!!!!!!!!! Error_analysis failed complex double pointer test!"<<endl;}
}



void error_analysis_blk_pointer_test()
{
    const size_t L=8;
    const size_t blk_size=2;
    double array[L]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
    double mean,err;
    error_analysis_blk(L,blk_size,array,mean,err);
    if((abs(mean-4.5)<1e-14)&&(abs(err-1.2909944487358056)<1e-14)) {cout<<"PASSED! Error_analysis_blk passed double pointer test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Error_analysis_blk failed double pointer test!"<<endl;}
}


void error_analysis_blk_loop_pointer_test()
{
    const size_t L=10;
    double array[L]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    vector<size_t> fact;
    vector<double> mean,err;
    vector<double> mean_exact={5.5,5.5,5.5,5.5};
    vector<double> err_exact={0.957427107756338,1.41421356237310,2.5,0};
    error_analysis_blk_loop(L,array,fact,mean,err);
   
    size_t flag=0; 
    for(size_t i=0;i<fact.size();i++) 
    {
        if( (abs(mean[i]-mean_exact[i])>1e-14) || (abs(err[i]-err_exact[i])>1e-14) ) flag++;
    }
   
    if(flag==0) cout<<"PASSED! Error_analysis_blk_loop passed pointer test!"<<endl;
    else cout<<"WARNING!!!!!!!!! Error_analysis_blk_loop failed pointer test!"<<endl;
}



//============
//Vector test
//============

void get_average_err_vector_test()
{
    //double test
    vector<double> vec{1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    double mean,err;
   
    get_average(vec,mean);
    if(abs(mean-5.0)<1e-14) {cout<<"PASSED! Get_average passed double vector test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_average failed double vector test!"<<endl;}
   
    get_err(vec,mean,err);
    if(abs(err-0.912870929175277)<1e-14) {cout<<"PASSED! Get_err passed double vector test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_err failed double vector test!"<<endl;}
   
    //complex double test
    vector<complex<double>> vec_c{{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0}};
    complex<double> mean_c;
    double err_c; 
   
    get_average(vec_c,mean_c); 
    if(abs(mean_c-complex<double>(4.0,5.0))<1e-14) {cout<<"PASSED! Get_average passed complex double vector test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_average failed complex double vector test!"<<endl;}
   
    get_err(vec_c,mean_c,err_c);
    if(abs(err_c-1.8257418583505536)<1e-14) {cout<<"PASSED! Get_err passed complex double vector test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Get_err failed complex double vector test!"<<endl;} 
}



void error_analysis_vector_test()
{
    //double test
    vector<double> vec{1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    double mean,err;
   
    error_analysis(vec,mean,err);
    if((abs(mean-5.0)<1e-14)&&(abs(err-0.912870929175277)<1e-14)) {cout<<"PASSED! Error_analysis passed double vector test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Error_analysis failed double vector test!"<<endl;}
   
    //complex test
    vector<complex<double>> vec_c{{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0}};
    complex<double> mean_c;
    double err_c;
    
    error_analysis(vec_c,mean_c,err_c);
    if((abs(mean_c-complex<double>(4.0,5.0))<1e-14)&&(abs(err_c-1.8257418583505536)<1e-14))
      {cout<<"PASSED! Error_analysis passed complex double vector test!"<<endl;}
    else 
      {cout<<"WARNING!!!!!!!!! Error_analysis failed complex double vector test!"<<endl;}
}


void error_analysis_blk_vector_test()
{
    const size_t blk_size=2;
    vector<double> vec{1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
    double mean,err;
    error_analysis_blk(blk_size,vec,mean,err);
    if((abs(mean-4.5)<1e-14)&&(abs(err-1.2909944487358056)<1e-14)) {cout<<"PASSED! Error_analysis_blk passed double vector test!"<<endl;}
    else {cout<<"WARNING!!!!!!!!! Error_analysis_blk failed double vector test!"<<endl;}
}


void error_analysis_blk_loop_vector_test()
{
    vector<double> vec{1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    vector<size_t> fact;
    vector<double> mean,err;
    vector<double> mean_exact={5.5,5.5,5.5,5.5};
    vector<double> err_exact={0.957427107756338,1.41421356237310,2.5,0};
    error_analysis_blk_loop(vec,fact,mean,err);
   
    size_t flag=0;
    for(size_t i=0;i<fact.size();i++)
    {
        if( (abs(mean[i]-mean_exact[i])>1e-14) || (abs(err[i]-err_exact[i])>1e-14) ) flag++;
    }
   
    if(flag==0) cout<<"PASSED! Error_analysis_blk_loop passed vector test!"<<endl;
    else cout<<"WARNING!!!!!!!!! Error_analysis_blk_loop failed vector test!"<<endl;
}


//==========
//Other test
//==========
void get_factors_test()
{
    size_t n=500;
    vector<size_t> fact;
    vector<size_t> fact_exact={1,2,4,5,10,20,25,50,100,125,250,500};
    get_factors(n,fact);
   
    if(fact.size()!=fact_exact.size()) cout<<"WARNING!!!!!!!!! get_factors failed test!"<<endl;
   
    size_t flag=0;
    for (size_t i=0; i<fact.size(); i++)  {if(fact[i]!=fact_exact[i]) flag++;}
    if(flag==0) cout<<"PASSED! Get_factors passed test!"<<endl;
    else cout<<"WARNING!!!!!!!!! Get_factors failed test!"<<endl;
   
    /*get_factors(36,fact); for (size_t i=0; i<fact.size(); i++) cout<<fact[i]<<"\n";
    cout<<fact.size()<<"\n";*/
}





void error_analysis_test()
{
    int rank=0;
#ifdef MPI_HAO
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        get_factors_test();
   
        get_average_err_pointer_test();
        error_analysis_pointer_test();
        error_analysis_blk_pointer_test();
        error_analysis_blk_loop_pointer_test();
   
        get_average_err_vector_test();
        error_analysis_vector_test();
        error_analysis_blk_vector_test();
        error_analysis_blk_loop_vector_test();
        cout<<" "<<endl;
    }
    
}
