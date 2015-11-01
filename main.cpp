#include "main.h"

using namespace std;

//define some data structures
vector< vector<long double> > plots;
vector< vector<long double> > landUses;
vector< pair<int, int> > assignments;

/*
   Manage the process of loading data, running the experiment
   and saving the results.
*/
void experiment(){
  for(int k = 0; k < NUMBER_OF_INPUT_FILES; k++){
    std::ostringstream ostr; //output string stream
    ostr << BASE_FILE_PATH << BASE_FILE_NAME << k << FILE_EXT;
    std::fstream myfile(ostr.str().c_str(), std::ios_base::in);
    loadData(myfile);
    myfile.close();
    cout << "Plots: " << plots.size() << "\tLand Uses: " << landUses.size() << "\tAssigments: " << assignments.size() << endl;
    vector< pair<int, int> > a;
    for(int i = 1; i <= ITERATIONS_PER_FILE; i++){
      a = assignments;
      //sa(k, i, a);
    }
}
}

/*
    Load the data from the text file.
*/
void loadData(std::fstream& dataFile){

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

}

void printVector(){

  for (vector<vector<long double> >::size_type i = 0; i < plots.size(); i++){
    for (vector<long double>::size_type j = 0; j < plots[i].size(); j++){
      cout << plots[i][j] << " ";
    }
    cout << endl;
  }

}
