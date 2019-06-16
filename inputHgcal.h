#ifndef inputHgcal_h
#define inputHgcal_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <cassert>
#include <vector>
#include <time.h>

#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TStyle.h"
#include "histHgcal.h"
#include "test.h"

using namespace std;


// ====================================================================
class inputHgcal {

public:
   inputHgcal();
   ~inputHgcal();

   string  getInput(const string & dataset);  // return the input file name
   //void setDebugFlag();
private:

   map<string, string> mydataset;
   map<string, double> myxsec;
//   map<string, int> mynentries;
   map<string, double> mynentries;
   double ncall;

   void hgcalNtuple();   

   //TTree * tree;
   string datasetname_; 
   double targetLumi_;
   double xsection_;
   double nentries_;
   double weight_;

};

#endif //~inputHgcal_h
