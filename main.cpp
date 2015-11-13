#include "main.h"

using namespace std;

/**
 * Read the given file and load up a vector of plots
 */
 __host__
thrust::host_vector< thrust::host_vector<double> > loadPlots(std::fstream& dataFile){


  int n, m;

  //find total number of plots n and number of attributes m
  dataFile >> n >> m;

  //Create a vector of size n
  thrust::host_vector< thrust::host_vector<double> > H(n);
  //make sure that the plots vector is empty
  H.clear();

   //find all attributes for all plots
  for (int i = 0; i < n; i++){
    thrust::host_vector<double> row(m);
    long double r;
    for (int j = 0; j < m; j++){
      dataFile >> r;
      row.push_back(r);
    }
    H.push_back(row);
  }

  return H;

}

__host__
thrust::host_vector< thrust::host_vector<double> > loadLandUses(std::fstream& dataFile){
  int l, m;
  //find total number of land uses and criteria then load all values
  dataFile >> l >> m;

  thrust::host_vector< thrust::host_vector<double> > landUses(l);

  //make sure the landUses vector is clear
  landUses.clear();

  for(int i = 0; i < l; i++){
    thrust::host_vector<double> row;
    long double r;
    for (int j = 0; j < m; j++ ){
      dataFile >> r;
      row.push_back(r);
    }
    landUses.push_back(row);
  }
  return landUses;
}

__host__
thrust::host_vector< pair<int, int> > loadAssignments(std::fstream& dataFile, int n){
  thrust::host_vector< pair<int, int> > assignments(n);

  int p, a;

  //find all assignments
  for(int i = 0; i < n; i++){
    dataFile >> p >> a;
    assignments.push_back(make_pair(p, a));
  }
  return assignments;
}
