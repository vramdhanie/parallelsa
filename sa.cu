#include <stdio.h>

// For the CUDA runtime routines (prefixed with "cuda_")
#include <cuda_runtime.h>
#include "main.h"

using namespace std;


struct testit {

__device__
  thrust::device_vector<double> operator()(thrust::device_vector<double> plots){

    return plots;
  }
};


/**
 * Host main routine
 */
int main(void){
    printf("Trying to call experiment from main\n");
    experiment();

    printf("Done\n");
    return 0;
}

/*
   Manage the process of loading data, running the experiment
   and saving the results.
*/
__host__
void experiment(){
  for(int k = 0; k < NUMBER_OF_INPUT_FILES; k++){
    std::ostringstream ostr; //output string stream
    ostr << BASE_FILE_PATH << BASE_FILE_NAME << k << FILE_EXT;
    std::fstream myfile(ostr.str().c_str(), std::ios_base::in);
    thrust::host_vector< thrust::host_vector<double> > plots = loadPlots(myfile);
    thrust::host_vector< thrust::host_vector<double> > landUses = loadLandUses(myfile);
    thrust::host_vector< pair<int, int> > assignments = loadAssignments(myfile, plots.size());
    myfile.close();
    cout << "Plots: " << plots.size() << "\tLand Uses: " << landUses.size() << "\tAssignments: " << assignments.size() << endl;
    //vector< pair<int, int> > a;
    //for(int i = 1; i <= ITERATIONS_PER_FILE; i++){
    //  a = assignments;
      //sa(k, i, a);
    //}

    //thrust::device_vector< thrust::device_vector<long double> > d_plots = plots;
    //thrust::transform(d_plots.begin(), d_plots.end(), d_plots.begin(), testit());
  }
}
