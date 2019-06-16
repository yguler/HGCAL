#ifndef histHgcal_h
#define histHgcal_h


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
#include "TH3D.h"
#include "TProfile.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TStyle.h"

#include "test.h"

using namespace std;

// ====================================================================
class histoSet1{

public:
  histoSet1(TFile * fout, string anaType,  string cutname);
  ~histoSet1();

  void process(test & ev, double weight);
  void summary(string anaType, string mydataset);
  vector<double>  PileUpWeights();

private:

  // Histograms with names
  std::map<std::string, TH1D*> histo1D;
  std::map<std::string, TH1D*>::iterator histo1Diter;

  std::map<std::string, TH2D*> histo2D;
  std::map<std::string, TH2D*>::iterator histo2Diter;

  std::map<std::string, TH3D*> histo3D;
  std::map<std::string, TH3D*>::iterator histo3Diter;

  double nevents_unweighted;
  double nevents_weighted;
  double nevents_weighted_New;
  string dirname;
};

#endif  //~histHgcal_h
