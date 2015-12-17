#include "error_analysis.h"
#include "kahan.h"
#include <iostream>

#ifdef MPI_HAO
#include <mpi.h>
#endif
using namespace std;

void error_analysis_test();
void kahandata_classtest();
void calculate_mean_err_between_thread_test();

int main(int argc, char** argv)
{
    int rank=0;
#ifdef MPI_HAO
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

    if(rank==0)
    {
        cout<<"\n\n\n=======Testing======="<<endl;
        kahandata_classtest();
        error_analysis_test();
    }

    calculate_mean_err_between_thread_test();

#ifdef MPI_HAO
    MPI_Finalize();
#endif

    return 0;
}
