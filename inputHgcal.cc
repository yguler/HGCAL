#include "inputHgcal.h"

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
#include <TLorentzVector.h>
#include "test.h"

using namespace std;

//g++ `root-config --cflags` -o HGCALAnalyzer test.cc histHgcal.cc inputHgcal.cc anaHgcal.cc  `root-config --glibs`
// ====================================================================

inputHgcal::inputHgcal() {
   std::cout<<"  inputHgcal is created "<<std::endl;
   ncall=0;

   hgcalNtuple();
}

// ====================================================================
inputHgcal::~inputHgcal() {

}


// ====================================================================
string inputHgcal::getInput(const string & dataset){

  //  find and set tree name...
  //
  //  arg1: string-  data set name
  string filename=mydataset[dataset];

  // save weight...
  datasetname_=dataset;
  // std::cout<<" inoutMonojet:: mynentries[dataset]="<<mynentries[dataset]<<std::endl; 
  nentries_=mynentries[dataset];
   std::cout<<" yg inputHgcal::getInput - dateset name="<<dataset<<std::endl;


 return filename;
}


// ==================================================================
void inputHgcal::hgcalNtuple(){

  string fileDirectoryRe = "root://cmsxrootd.fnal.gov//store/user/";
  string fileDirectoryM17GJets ="root://cmseos.fnal.gov//store/group/";
  string fileDirectorydatav1 ="/uscms_data/d3/ygule/";
  string fileDirectorylx ="/afs/cern.ch/work/y/yalcin/public/hgcal_March2018/ntuples/";
  //string fileDirectoryEOSdata ="root://eoscms.cern.ch//eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_june/offline_analysis/ntuples/v11/";
  string fileDirEOSdata ="root://eoscms.cern.ch//eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/ntuples/v11/";
  string fileDirEOSv1 ="root://eoscms.cern.ch//eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v1/withMCP/";
  string fileDirEOSv2 ="root://eoscms.cern.ch//eos/cms/store/group/dpg_hgcal/tb_hgcal/2018/cern_h2_october/offline_analysis/sim_ntuples/v2/withMCP/";

  mydataset["pdgID211_beamMomentum20_listFTFP_BERT_EMM_v1"]  = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum20_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum50_listFTFP_BERT_EMM_v1"]  = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum50_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum80_listFTFP_BERT_EMM_v1"]  = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum80_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum100_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum100_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum120_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum120_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum200_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum200_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum250_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum250_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum300_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID211_beamMomentum300_listFTFP_BERT_EMM.root";

  mydataset["pdgID2211_beamMomentum20_listFTFP_BERT_EMM_v1"]  = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum20_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum50_listFTFP_BERT_EMM_v1"]  = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum50_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum80_listFTFP_BERT_EMM_v1"]  = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum80_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum100_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum100_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum120_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum120_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum200_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum200_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum250_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum250_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum300_listFTFP_BERT_EMM_v1"] = fileDirEOSv1+"ntuple_sim_config22_pdgID2211_beamMomentum300_listFTFP_BERT_EMM.root";

  mydataset["pdgID211_beamMomentum20_listFTFP_BERT_EMM_v2"]  = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum20_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum50_listFTFP_BERT_EMM_v2"]  = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum50_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum80_listFTFP_BERT_EMM_v2"]  = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum80_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum100_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum100_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum120_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum120_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum200_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum200_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum250_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum250_listFTFP_BERT_EMM.root";
  mydataset["pdgID211_beamMomentum300_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID211_beamMomentum300_listFTFP_BERT_EMM.root";

  mydataset["pdgID2211_beamMomentum20_listFTFP_BERT_EMM_v2"]  = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum20_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum50_listFTFP_BERT_EMM_v2"]  = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum50_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum80_listFTFP_BERT_EMM_v2"]  = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum80_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum100_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum100_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum120_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum120_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum200_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum200_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum250_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum250_listFTFP_BERT_EMM.root";
  mydataset["pdgID2211_beamMomentum300_listFTFP_BERT_EMM_v2"] = fileDirEOSv2+"ntuple_sim_config22_pdgID2211_beamMomentum300_listFTFP_BERT_EMM.root";
////////////////100 GeV Pion
  mydataset["pionBeam_Run552_100GeV"] = fileDirEOSdata+"ntuple_552.root";
  mydataset["pionBeam_Run553_100GeV"] = fileDirEOSdata+"ntuple_553.root";
  mydataset["pionBeam_Run554_100GeV"] = fileDirEOSdata+"ntuple_554.root";
  mydataset["pionBeam_Run555_100GeV"] = fileDirEOSdata+"ntuple_555.root";
  mydataset["pionBeam_Run557_100GeV"] = fileDirEOSdata+"ntuple_557.root";
  mydataset["pionBeam_Run558_100GeV"] = fileDirEOSdata+"ntuple_558.root";
  mydataset["pionBeam_Run559_100GeV"] = fileDirEOSdata+"ntuple_559.root";
  mydataset["pionBeam_Run560_100GeV"] = fileDirEOSdata+"ntuple_560.root";
  mydataset["pionBeam_Run561_100GeV"] = fileDirEOSdata+"ntuple_561.root";
  mydataset["pionBeam_Run562_100GeV"] = fileDirEOSdata+"ntuple_562.root";
/////////////////
////////////////20 GeV Pion
  mydataset["pionBeam_Run679_20GeV"] = fileDirEOSdata+"ntuple_679.root";
  mydataset["pionBeam_Run680_20GeV"] = fileDirEOSdata+"ntuple_680.root";
  mydataset["pionBeam_Run681_20GeV"] = fileDirEOSdata+"ntuple_681.root";
  mydataset["pionBeam_Run682_20GeV"] = fileDirEOSdata+"ntuple_682.root";
  mydataset["pionBeam_Run683_20GeV"] = fileDirEOSdata+"ntuple_683.root";
  mydataset["pionBeam_Run685_20GeV"] = fileDirEOSdata+"ntuple_685.root";
  mydataset["pionBeam_Run687_20GeV"] = fileDirEOSdata+"ntuple_687.root";
  mydataset["pionBeam_Run688_20GeV"] = fileDirEOSdata+"ntuple_688.root";
  mydataset["pionBeam_Run689_20GeV"] = fileDirEOSdata+"ntuple_689.root";
////////////////
/*
679
680
681
682
683
685
687
688
689
772
777
778
779
780
781
782
818
819
820
821
824
825
826
818
819
820
821
824
825
826
1016 
1017 20 GeV 

1044 100 GeV
1045
1046
1047
1048
1049
1079
1080
1081
1082
*/
}


