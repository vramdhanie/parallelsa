#ifndef FINAL_PARALLELSA_MAIN_H_
#define FINAL_PARALLELSA_MAIN_H_

#include <time.h>
#include <iostream>
#include <fstream>
#include "sa.h"
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <iostream>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

using namespace std;



//Some constants
const std::string BASE_FILE_PATH = "../DataGenerator/"; /*Where input files are located*/
const std::string BASE_FILE_NAME = "data_"; /*Name of data files*/
const std::string FILE_EXT = ".txt"; /*file extension to use*/

long double cost(vector< pair<int, int> >&); //cost function calculates the cost of a certain configuration
pair<int, int> nextConfiguration(vector< pair<int, int> >&); //find another configuration
void loadData(std::fstream&); //load all data from the input file
void printVector(); //print the  content of the plots vector
void revert(pair<int, int>, vector< pair<int, int> >&); //revert a configuration change
void sa(int, int, vector< pair<int, int> >&); //perform the sequential SA algorithm
void experiment(); //manage the experiment
thrust::host_vector< thrust::host_vector<long double> > loadLandUses(std::fstream& dataFile);
thrust::host_vector< thrust::host_vector<long double> > loadPlots(std::fstream& dataFile);
thrust::host_vector< pair<int, int> > loadAssignments(std::fstream& dataFile, int n);


#endif  // FINAL_PARALLELSA_MAIN_H_
