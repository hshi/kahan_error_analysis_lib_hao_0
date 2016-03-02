#ifndef THREAD_ERR_ANAL_HAO_H
#define THREAD_ERR_ANAL_HAO_H

#include <iostream>
#include <vector>
#include <complex>

#ifdef MPI_HAO
#include <mpi.h>
#endif

//Calculate mean value and error bar between different thread
//Send mean value to all the thread
//Only send error bar to main thread==> However we need to allocate *err in all thread. 
void calculate_mean_err_between_thread(std::complex<double> value_thread, std::complex<double>& mean, double& err);
void calculate_mean_err_between_thread(int N, const std::complex<double>* value_thread, std::complex<double>* mean, double* err);
void calculate_mean_err_between_thread(const std::vector< std::complex<double> >& value_thread, 
                                             std::vector< std::complex<double> >& mean, std::vector<double>& err);
#endif
