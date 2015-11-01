#include "main.h"

using namespace std;

//define some data structures
vector< vector<long double> > plots;
vector< vector<long double> > landUses;
vector< pair<int, int> > assignments;

/**
 * Read the given file and load up a vector of plots
 */
 __host__
thrust::host_vector< thrust::host_vector<long double> > loadPlots(std::fstream& dataFile){


  int n, m;

  //find total number of plots n and number of attributes m
  dataFile >> n >> m;

  //Create a vector of size n
  thrust::host_vector< thrust::host_vector<long double> > H(n);
  //make sure that the plots vector is empty
  H.clear();

   //find all attributes for all plots
  for (int i = 0; i < n; i++){
    thrust::host_vector<long double> row(m);
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
thrust::host_vector< thrust::host_vector<long double> > loadLandUses(std::fstream& dataFile){
  int l, m;
  //find total number of land uses and criteria then load all values
  dataFile >> l >> m;

  thrust::host_vector< thrust::host_vector<long double> > landUses(l);

  //make sure the landUses vector is clear
  landUses.clear();

  for(int i = 0; i < l; i++){
    thrust::host_vector<long double> row;
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

/*
    Load the data from the text file.
*/
void loadData(std::fstream& dataFile){
/*
    int n, m, l, p, a;

    //find total number of plots n and number of attributes m
    dataFile >> n >> m;

    //make sure that the plots vector is empty
    plots.clear();

    float b;
     //find all attributes for all plots
    int num_plots = n * m;
    int count = 0;
    for (int i = 0; i < n; i++){
      vector<long double> row;
      long double r;
      for (int j = 0; j < m; j++){
        dataFile >> r;
        row.push_back(r);
        count++;
      }
      plots.push_back(row);
    }

    //find total number of land uses and criteria then load all values
    dataFile >> l >> m;
    int num_landUses = l * m;
    count = 0;

    //make sure the landUses vector is clear
    landUses.clear();

    for(int i = 0; i < l; i++){
      vector<long double> row;
      long double r;
      for (int j = 0; j < m; j++ ){
        dataFile >> r;
        row.push_back(r);
        count++;
      }
      landUses.push_back(row);
    }

    //make sure the assignments vector is clear
    assignments.clear();

    //find all assignments
    for(int i = 0; i < n; i++){
      dataFile >> p >> a;
      assignments.push_back(make_pair(p, a));
    }
*/
}

void printVector(){

  for (vector<vector<long double> >::size_type i = 0; i < plots.size(); i++){
    for (vector<long double>::size_type j = 0; j < plots[i].size(); j++){
      cout << plots[i][j] << " ";
    }
    cout << endl;
  }

}
